extern "C" {
#include "php.h"
#include "zend_exceptions.h"
#include "zend_smart_str.h"
#include "ext/spl/spl_exceptions.h"
}

#include "src/simdutf.h"
#include "php_convert.h"

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
