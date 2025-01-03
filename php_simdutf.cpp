/*
  +----------------------------------------------------------------------+
  | simdutf_php                                                          |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.0 of the Apache license,    |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.apache.org/licenses/LICENSE-2.0.html                      |
  +----------------------------------------------------------------------+
  | Author: Don MacAskill  <don@awesome.co>                              |
  +----------------------------------------------------------------------+
*/

extern "C" {
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "zend_exceptions.h"
#include "zend_smart_str.h"
#include "main/SAPI.h"
#include "ext/standard/info.h"
#include "ext/spl/spl_exceptions.h"

#include "php_simdutf.h"

} /* end extern "C" */

#include "src/simdutf.h"

#include "simdjson_arginfo.h"

PHP_FUNCTION(simdutf_validate_utf8) {
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    // Handle empty string case
    if (ZSTR_LEN(string) == 0) {
        GC_ADD_FLAGS(string, IS_STR_VALID_UTF8);  // Empty string is valid UTF-8
        RETURN_TRUE;
    }

    // Check for null byte in the string
    if (UNEXPECTED(ZSTR_VAL(string)[0] == '\0')) {
        RETURN_FALSE;
    }

    // If string was already successfully validated, just return true
    if (ZSTR_IS_VALID_UTF8(string)) {
        RETURN_TRUE;
    }

    // Validate input pointer
    if (UNEXPECTED(ZSTR_VAL(string) == NULL)) {
        zend_throw_exception(NULL, "Invalid string pointer", 0);
        RETURN_THROWS();
    }

    bool is_ok = simdutf::validate_utf8(ZSTR_VAL(string), ZSTR_LEN(string));

    if (EXPECTED(is_ok)) {
        // String is UTF-8 valid, so we can also set proper flag
        GC_ADD_FLAGS(string, IS_STR_VALID_UTF8);
    }

    RETURN_BOOL(is_ok);
}

PHP_FUNCTION(simdutf_validate_utf8_with_errors) {
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    // Handle empty string case
    if (ZSTR_LEN(string) == 0) {
        GC_ADD_FLAGS(string, IS_STR_VALID_UTF8);
        RETURN_TRUE;
    }

    // If string was already successfully validated, just return true
    if (ZSTR_IS_VALID_UTF8(string)) {
        RETURN_TRUE;
    }

    // Validate input pointer
    if (UNEXPECTED(ZSTR_VAL(string) == NULL)) {
        zend_throw_exception(NULL, "Invalid string pointer", 0);
        RETURN_THROWS();
    }

    simdutf::result validation_result = simdutf::validate_utf8_with_errors(
        ZSTR_VAL(string),
        ZSTR_LEN(string)
    );

    if (!validation_result.error) {
        GC_ADD_FLAGS(string, IS_STR_VALID_UTF8);
        RETURN_TRUE;
    } else {
        // Create an associative array with error details
        array_init(return_value);
        add_assoc_bool(return_value, "valid", false);
        add_assoc_long(return_value, "error_offset", validation_result.count);
        return;
    }
}

// base64 functions
PHP_FUNCTION(simdutf_binary_to_base64) {
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    // Check for input length overflow - base64 encoding expands by 4/3
    if (ZSTR_LEN(string) > SIZE_MAX * 3 / 4) {
        zend_throw_exception(NULL, "Input string too long", 0);
        RETURN_THROWS();
    }

    size_t encoded_length = simdutf::base64_length_from_binary(ZSTR_LEN(string));

    // Double check the encoded length is what we expect
    if (encoded_length == 0 && ZSTR_LEN(string) != 0) {
        zend_throw_exception(NULL, "Failed to calculate base64 length", 0);
        RETURN_THROWS();
    }

    zend_string *result = zend_string_alloc(encoded_length, 0);
    if (!result) {
        zend_throw_exception(NULL, "Failed to allocate memory", 0);
        RETURN_THROWS();
    }

    size_t written = simdutf::binary_to_base64(
        ZSTR_VAL(string),
        ZSTR_LEN(string),
        ZSTR_VAL(result)
    );

    // Sanity check on written bytes
    if (written != encoded_length) {
        zend_string_free(result);
        zend_throw_exception(NULL, "Unexpected number of bytes written during base64 encoding", 0);
        RETURN_THROWS();
    }

    GC_ADD_FLAGS(result, IS_STR_VALID_UTF8); // base64 encoded string must be always valid UTF-8 string

    RETURN_STR(result);
}

PHP_FUNCTION(simdutf_base64_to_binary) {
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    // For base64, every 4 chars encode 3 bytes
    size_t decoded_length = (ZSTR_LEN(string) * 3) / 4;
    zend_string *result = zend_string_alloc(decoded_length, 0);

    simdutf::result decode_result = simdutf::base64_to_binary(
        ZSTR_VAL(string),
        ZSTR_LEN(string),
        ZSTR_VAL(result)
    );

    if (decode_result.error) {
        zend_string_free(result);
        if (decode_result.error == simdutf::error_code::INVALID_BASE64_CHARACTER) {
            char error_message[128];
            snprintf(error_message, sizeof(error_message),
                    "Invalid base64 character at position %zu", decode_result.count);
            zend_throw_exception(NULL, error_message, 0);
        } else if (decode_result.error == simdutf::error_code::BASE64_INPUT_REMAINDER) {
            zend_throw_exception(NULL, "Invalid base64 input length", 0);
        } else {
            zend_throw_exception(NULL, "Base64 decoding failed", 0);
        }
        RETURN_THROWS();
    }

    // Resize the result to the actual number of bytes written
    if (decode_result.count < decoded_length) {
        result = zend_string_truncate(result, decode_result.count, 0);
    }

    RETURN_STR(result);
}

// count functions
PHP_FUNCTION(simdutf_count_utf8) {
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    // Handle empty string case
    if (ZSTR_LEN(string) == 0) {
        RETURN_LONG(0);
    }

    // Validate input pointer
    if (UNEXPECTED(ZSTR_VAL(string) == NULL)) {
        zend_throw_exception(NULL, "Invalid string pointer", 0);
        RETURN_THROWS();
    }

    size_t count = simdutf::count_utf8(ZSTR_VAL(string), ZSTR_LEN(string));
    RETURN_LONG(count);
}

PHP_FUNCTION(simdutf_count_utf16) {
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    // Handle empty string case
    if (ZSTR_LEN(string) == 0) {
        RETURN_LONG(0);
    }

    // Convert UTF-8 to UTF-16
    size_t utf16_length = simdutf::utf16_length_from_utf8(
        ZSTR_VAL(string),
        ZSTR_LEN(string)
    );

    char16_t *utf16_input = new char16_t[utf16_length];

    size_t chars_converted = simdutf::convert_utf8_to_utf16(
        ZSTR_VAL(string),
        ZSTR_LEN(string),
        utf16_input
    );

    if (chars_converted != utf16_length) {
        delete[] utf16_input;
        zend_throw_exception(NULL, "Failed to convert input to UTF-16", 0);
        RETURN_THROWS();
    }

    size_t count = simdutf::count_utf16(utf16_input, utf16_length);
    delete[] utf16_input;

    RETURN_LONG(count);
}

PHP_FUNCTION(simdutf_count_utf16le) {
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    // Handle empty string case
    if (ZSTR_LEN(string) == 0) {
        RETURN_LONG(0);
    }

    // Convert UTF-8 to UTF-16LE
    size_t utf16_length = simdutf::utf16_length_from_utf8(
        ZSTR_VAL(string),
        ZSTR_LEN(string)
    );

    char16_t *utf16_input = new char16_t[utf16_length];

    size_t chars_converted = simdutf::convert_utf8_to_utf16(
        ZSTR_VAL(string),
        ZSTR_LEN(string),
        utf16_input
    );

    if (chars_converted != utf16_length) {
        delete[] utf16_input;
        zend_throw_exception(NULL, "Failed to convert input to UTF-16LE", 0);
        RETURN_THROWS();
    }

    size_t count = simdutf::count_utf16le(utf16_input, utf16_length);
    delete[] utf16_input;

    RETURN_LONG(count);
}

PHP_FUNCTION(simdutf_count_utf16be) {
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    // Handle empty string case
    if (ZSTR_LEN(string) == 0) {
        RETURN_LONG(0);
    }

    // Convert UTF-8 to UTF-16BE
    size_t utf16_length = simdutf::utf16_length_from_utf8(
        ZSTR_VAL(string),
        ZSTR_LEN(string)
    );

    char16_t *utf16_input = new char16_t[utf16_length];

    size_t chars_converted = simdutf::convert_utf8_to_utf16(
        ZSTR_VAL(string),
        ZSTR_LEN(string),
        utf16_input
    );

    if (chars_converted != utf16_length) {
        delete[] utf16_input;
        zend_throw_exception(NULL, "Failed to convert input to UTF-16BE", 0);
        RETURN_THROWS();
    }

    size_t count = simdutf::count_utf16be(utf16_input, utf16_length);
    delete[] utf16_input;

    RETURN_LONG(count);
}

/* {{{ proto string simdutf_convert_latin1_to_utf8(string input)
   Convert Latin1 string to UTF-8 using simdutf */
PHP_FUNCTION(simdutf_convert_latin1_to_utf8)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    // Get required size for UTF-8 output (worst case: input_len * 2)
    size_t utf8_output_capacity = input_len * 2;
    char *utf8_output = (char *)safe_emalloc(utf8_output_capacity, 1, 1);

    // Convert using simdutf
    size_t utf8_output_size = simdutf::convert_latin1_to_utf8(
        reinterpret_cast<const char *>(input),
        input_len,
        reinterpret_cast<char *>(utf8_output)
    );

    if (utf8_output_size == 0) {
        efree(utf8_output);
        RETURN_FALSE;
    }

    RETVAL_STRINGL(utf8_output, utf8_output_size);
    efree(utf8_output);
}
/* }}} */

/* {{{ proto string simdutf_convert_latin1_to_utf8_safe(string input, int max_len)
   Convert Latin1 string to UTF-8 with length limit using simdutf */
PHP_FUNCTION(simdutf_convert_latin1_to_utf8_safe)
{
    char *input;
    size_t input_len;
    zend_long max_len;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_STRING(input, input_len)
        Z_PARAM_LONG(max_len)
    ZEND_PARSE_PARAMETERS_END();

    if (max_len < 0) {
        zend_throw_exception(NULL, "Maximum length cannot be negative", 0);
        RETURN_FALSE;
    }

    char *utf8_output = (char *)safe_emalloc(max_len, 1, 1);

    size_t utf8_output_size = simdutf::convert_latin1_to_utf8_safe(
        reinterpret_cast<const char *>(input),
        input_len,
        reinterpret_cast<char *>(utf8_output),
        max_len
    );

    if (utf8_output_size == 0) {
        efree(utf8_output);
        RETURN_FALSE;
    }

    RETVAL_STRINGL(utf8_output, utf8_output_size);
    efree(utf8_output);
}
/* }}} */

/* {{{ proto string simdutf_convert_latin1_to_utf16le(string input)
   Convert Latin1 string to UTF-16LE using simdutf */
PHP_FUNCTION(simdutf_convert_latin1_to_utf16le)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    // Allocate buffer for UTF-16 output (each Latin1 char becomes one UTF-16 char)
    char16_t *utf16_output = (char16_t *)safe_emalloc(input_len, sizeof(char16_t), 1);

    size_t utf16_output_size = simdutf::convert_latin1_to_utf16le(
        reinterpret_cast<const char *>(input),
        input_len,
        utf16_output
    );

    if (utf16_output_size == 0) {
        efree(utf16_output);
        RETURN_FALSE;
    }

    RETVAL_STRINGL((char *)utf16_output, utf16_output_size * sizeof(char16_t));
    efree(utf16_output);
}
/* }}} */

/* {{{ proto string simdutf_convert_latin1_to_utf16be(string input)
   Convert Latin1 string to UTF-16BE using simdutf */
PHP_FUNCTION(simdutf_convert_latin1_to_utf16be)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    char16_t *utf16_output = (char16_t *)safe_emalloc(input_len, sizeof(char16_t), 1);

    size_t utf16_output_size = simdutf::convert_latin1_to_utf16be(
        reinterpret_cast<const char *>(input),
        input_len,
        utf16_output
    );

    if (utf16_output_size == 0) {
        efree(utf16_output);
        RETURN_FALSE;
    }

    RETVAL_STRINGL((char *)utf16_output, utf16_output_size * sizeof(char16_t));
    efree(utf16_output);
}
/* }}} */

/* {{{ proto string simdutf_convert_latin1_to_utf32(string input)
   Convert Latin1 string to UTF-32 using simdutf */
PHP_FUNCTION(simdutf_convert_latin1_to_utf32)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    char32_t *utf32_output = (char32_t *)safe_emalloc(input_len, sizeof(char32_t), 1);

    size_t utf32_output_size = simdutf::convert_latin1_to_utf32(
        reinterpret_cast<const char *>(input),
        input_len,
        utf32_output
    );

    if (utf32_output_size == 0) {
        efree(utf32_output);
        RETURN_FALSE;
    }

    RETVAL_STRINGL((char *)utf32_output, utf32_output_size * sizeof(char32_t));
    efree(utf32_output);
}
/* }}} */

/* {{{ proto string simdutf_convert_utf8_to_latin1(string input)
   Convert UTF-8 string to Latin1 using simdutf */
PHP_FUNCTION(simdutf_convert_utf8_to_latin1)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    char *latin1_output = (char *)safe_emalloc(input_len, 1, 1);

    size_t written = simdutf::convert_utf8_to_latin1(
        reinterpret_cast<const char *>(input),
        input_len,
        latin1_output
    );

    if (written == 0) {
        efree(latin1_output);
        RETURN_FALSE;
    }

    RETVAL_STRINGL(latin1_output, written);
    efree(latin1_output);
}
/* }}} */

/* {{{ proto string simdutf_convert_utf8_to_utf16(string input)
   Convert UTF-8 string to UTF-16 using simdutf */
PHP_FUNCTION(simdutf_convert_utf8_to_utf16)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    char16_t *utf16_output = (char16_t *)safe_emalloc(input_len, sizeof(char16_t), 1);

    size_t written = simdutf::convert_utf8_to_utf16(
        reinterpret_cast<const char *>(input),
        input_len,
        utf16_output
    );

    if (written == 0) {
        efree(utf16_output);
        RETURN_FALSE;
    }

    RETVAL_STRINGL((char *)utf16_output, written * sizeof(char16_t));
    efree(utf16_output);
}
/* }}} */

/* {{{ proto array simdutf_convert_utf8_to_latin1_with_errors(string input)
   Convert UTF-8 string to Latin1 with error information */
PHP_FUNCTION(simdutf_convert_utf8_to_latin1_with_errors)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    char *latin1_output = (char *)safe_emalloc(input_len, 1, 1);

    simdutf::result result = simdutf::convert_utf8_to_latin1_with_errors(
        reinterpret_cast<const char *>(input),
        input_len,
        latin1_output
    );

    array_init(return_value);

    if (result.error) {
        // Error occurred
        add_assoc_bool(return_value, "success", 0);
        add_assoc_long(return_value, "error_offset", result.count);
        efree(latin1_output);
    } else {
        // Successful conversion
        add_assoc_bool(return_value, "success", 1);
        add_assoc_stringl(return_value, "output", latin1_output, result.count);
        efree(latin1_output);
    }
}
/* }}} */

/* {{{ proto array simdutf_convert_utf8_to_utf16_with_errors(string input)
   Convert UTF-8 string to UTF-16 with error information */
PHP_FUNCTION(simdutf_convert_utf8_to_utf16_with_errors)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    char16_t *utf16_output = (char16_t *)safe_emalloc(input_len, sizeof(char16_t), 1);

    simdutf::result result = simdutf::convert_utf8_to_utf16_with_errors(
        reinterpret_cast<const char *>(input),
        input_len,
        utf16_output
    );

    array_init(return_value);

    if (result.error) {
        add_assoc_bool(return_value, "success", 0);
        add_assoc_long(return_value, "error_offset", result.count);
        efree(utf16_output);
    } else {
        add_assoc_bool(return_value, "success", 1);
        add_assoc_stringl(return_value, "output",
                         (char *)utf16_output,
                         result.count * sizeof(char16_t));
        efree(utf16_output);
    }
}
/* }}} */

/* {{{ proto string simdutf_convert_valid_utf8_to_latin1(string input)
   Convert valid UTF-8 string to Latin1 (no validation) */
PHP_FUNCTION(simdutf_convert_valid_utf8_to_latin1)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    char *latin1_output = (char *)safe_emalloc(input_len, 1, 1);

    size_t written = simdutf::convert_valid_utf8_to_latin1(
        reinterpret_cast<const char *>(input),
        input_len,
        latin1_output
    );

    RETVAL_STRINGL(latin1_output, written);
    efree(latin1_output);
}
/* }}} */


/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(simdutf)
{
#if defined(ZTS) && defined(COMPILE_DL_SIMDUTF_PHP_EXT)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(simdutf)
{
	php_info_print_table_start();
	php_info_print_table_row(2, "simdutf support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ simdutf_php_ext_module_entry */
zend_module_entry simdutf_module_entry = {
	STANDARD_MODULE_HEADER,
	"simdutf",					/* Extension name */
	ext_functions,					/* zend_function_entry */
	NULL,							/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(simdutf),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(simdutf),			/* PHP_MINFO - Module info */
	PHP_SIMDUTF_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

/** {{{ DL support
 */
#ifdef COMPILE_DL_SIMDUTF
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE();
#endif

ZEND_GET_MODULE(simdutf)
#endif
/* }}} */
