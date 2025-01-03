extern "C" {
#include "php.h"
#include "zend_exceptions.h"
}

#include "src/simdutf.h"
#include "php_validate.h"

PHP_FUNCTION(simdutf_validate_utf8) {
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    if (ZSTR_LEN(string) == 0) {
        GC_ADD_FLAGS(string, IS_STR_VALID_UTF8);
        RETURN_TRUE;
    }

    if (UNEXPECTED(ZSTR_VAL(string)[0] == '\0')) {
        RETURN_FALSE;
    }

    if (ZSTR_IS_VALID_UTF8(string)) {
        RETURN_TRUE;
    }

    if (UNEXPECTED(ZSTR_VAL(string) == NULL)) {
        zend_throw_exception(NULL, "Invalid string pointer", 0);
        RETURN_THROWS();
    }

    bool is_ok = simdutf::validate_utf8(ZSTR_VAL(string), ZSTR_LEN(string));

    if (EXPECTED(is_ok)) {
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

