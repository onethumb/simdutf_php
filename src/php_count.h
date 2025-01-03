#ifndef PHP_SIMDUTF_BASE64_H
#define PHP_SIMDUTF_BASE64_H

#include "../php_simdutf.h"

BEGIN_EXTERN_C()

PHP_FUNCTION(simdutf_count_utf8);
PHP_FUNCTION(simdutf_count_utf16);
PHP_FUNCTION(simdutf_count_utf16le);
PHP_FUNCTION(simdutf_count_utf16be);

END_EXTERN_C()

#endif
