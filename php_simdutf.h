/*
  +----------------------------------------------------------------------+
  | simdutf_php                                                         |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.0 of the Apache license,    |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.apache.org/licenses/LICENSE-2.0.html                      |
  +----------------------------------------------------------------------+
  | Author: Jinxi Wang  <1054636713@qq.com>                              |
  +----------------------------------------------------------------------+
*/

#ifndef PHP_SIMDUTF_H
#define PHP_SIMDUTF_H

/*
 * Error constant implementation notes:
 *
 * - 0 always means success, and non-0 is a failure condition.
 * - Prefix these with SIMDUTF_PHP_ERR_ to distinguish them from other values.
 * - The error codes (value or labels) belonging to the C simdutf project may change in the future.
 *
 *   Maybe these should be exposed as extern const once there's a project that needs the other values.
 *   For now, they're also exposed as `REGISTER_LONG_CONSTANT("SIMDUTF_ERR_" #errcode, (val), CONST_PERSISTENT)`
 */
#define SIMDUTF_PHP_ERR_SUCCESS 0
#define SIMDUTF_PHP_ERR_INVALID_PHP_PROPERTY 255
#define SIMDUTF_PHP_ERR_KEY_COUNT_NOT_COUNTABLE 254

/*
 * Put all of the publicly visible functionality and macros into the same header file
 * (On windows, the include paths used by the c compiler may be different)
 */
#include "Zend/zend.h"
#include "Zend/zend_portability.h"

/*
 * All code in this header file should be changed to go within BEGIN_EXTERN_C/END_EXTERN_C macros
 * (both header definitions, and C++ declarations, including function implementations),
 * so that pecls written in C can use this functionality without separate C++ files to load bindings.h.
 *
 * This header file deliberately does not depend on other header files in this project,
 * to make including this header file easier for other PECLs (avoid include path issues)
 *
 * BEGIN_EXTERN_C is needed for symbols to be mangled using C rules instead of C++ rules in all includers.
 * (This macro can be used from both C and C++ source files)
 */
BEGIN_EXTERN_C()

extern zend_module_entry simdutf_module_entry;
#define phpext_simdutf_ptr &simdutf_module_entry

#define PHP_SIMDUTF_VERSION                  "1.0.0dev"
/**
 * PHP_SIMDUTF_VERSION_ID has the same format as PHP_VERSION_ID: Major version * 10000 + Minor version * 100 + Patch version.
 * This is meant for use by PECL extensions that depend on simdutf.
 * (e.g. 4.5.6dev and 4.5.6 would be 40506)
 */
#define PHP_SIMDUTF_VERSION_ID               10000

#define SIMDUTF_SUPPORT_URL                  "https://github.com/awesomized/simdutf_php"

PHP_MINIT_FUNCTION(simdutf);
PHP_MSHUTDOWN_FUNCTION(simdutf);
PHP_RINIT_FUNCTION(simdutf);
PHP_RSHUTDOWN_FUNCTION(simdutf);
PHP_MINFO_FUNCTION(simdutf);

#ifdef ZTS
#ifdef COMPILE_DL_SIMDUTF
ZEND_TSRMLS_CACHE_EXTERN()
#endif
#endif

/* Only the functions and variables defined with PHP_SIMDUTF_API can be loaded by other PECLs */
#ifdef PHP_WIN32
#	define PHP_SIMDUTF_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_SIMDUTF_API __attribute__ ((visibility("default")))
#else
#	define PHP_SIMDUTF_API /* nothing special */
#endif

PHP_FUNCTION(simdutf_validate_utf8);
PHP_FUNCTION(simdutf_validate_utf8_with_errors);
PHP_FUNCTION(simdutf_binary_to_base64);
PHP_FUNCTION(simdutf_base64_to_binary);
PHP_FUNCTION(simdutf_convert_utf8_to_latin1);
PHP_FUNCTION(simdutf_convert_utf8_to_utf16);
PHP_FUNCTION(simdutf_convert_utf8_to_utf16le);
PHP_FUNCTION(simdutf_convert_utf8_to_utf16be);
PHP_FUNCTION(simdutf_convert_utf8_to_utf32);
PHP_FUNCTION(simdutf_convert_utf8_to_latin1_with_errors);
PHP_FUNCTION(simdutf_convert_utf8_to_utf16_with_errors);
PHP_FUNCTION(simdutf_convert_utf8_to_utf16le_with_errors);
PHP_FUNCTION(simdutf_convert_utf8_to_utf16be_with_errors);
PHP_FUNCTION(simdutf_convert_utf8_to_utf32_with_errors);
PHP_FUNCTION(simdutf_convert_valid_utf8_to_latin1);
PHP_FUNCTION(simdutf_convert_valid_utf8_to_utf16);
PHP_FUNCTION(simdutf_convert_valid_utf8_to_utf16le);
PHP_FUNCTION(simdutf_convert_valid_utf8_to_utf16be);
PHP_FUNCTION(simdutf_convert_valid_utf8_to_utf32);

END_EXTERN_C()

#endif
