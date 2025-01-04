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

#include "Zend/zend.h"
#include "Zend/zend_portability.h"

BEGIN_EXTERN_C()

/* Error constants */
#define SIMDUTF_PHP_ERR_SUCCESS 0
#define SIMDUTF_PHP_ERR_INVALID_PHP_PROPERTY 255
#define SIMDUTF_PHP_ERR_KEY_COUNT_NOT_COUNTABLE 254

extern zend_module_entry simdutf_module_entry;
#define phpext_simdutf_ptr &simdutf_module_entry

#define PHP_SIMDUTF_VERSION                  "1.0.0dev"
#define PHP_SIMDUTF_VERSION_ID               10000
#define SIMDUTF_SUPPORT_URL                  "https://github.com/awesomized/simdutf_php"

/* API visibility */
#ifdef PHP_WIN32
#   define PHP_SIMDUTF_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#   define PHP_SIMDUTF_API __attribute__ ((visibility("default")))
#else
#   define PHP_SIMDUTF_API /* nothing special */
#endif

/* Module functions */
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

/* Include component headers */
#include "src/php_base64.h"
#include "src/php_validate.h"
#include "src/php_convert_latin1.h"
#include "src/php_convert_utf8.h"
#include "src/php_count.h"
#include "src/php_length.h"

END_EXTERN_C()

#endif /* PHP_SIMDUTF_H */
