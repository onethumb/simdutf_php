#ifndef PHP_SIMDUTF_LENGTH_H
#define PHP_SIMDUTF_LENGTH_H

#include "../php_simdutf.h"

BEGIN_EXTERN_C()

PHP_FUNCTION(simdutf_utf8_length_from_utf16);
PHP_FUNCTION(simdutf_utf8_length_from_utf16le);
PHP_FUNCTION(simdutf_utf8_length_from_utf16be);
PHP_FUNCTION(simdutf_utf8_length_from_utf32);
PHP_FUNCTION(simdutf_utf8_length_from_latin1);

PHP_FUNCTION(simdutf_latin1_length_from_utf8);
PHP_FUNCTION(simdutf_latin1_length_from_utf16);
PHP_FUNCTION(simdutf_latin1_length_from_utf32);

PHP_FUNCTION(simdutf_utf16_length_from_utf8);
PHP_FUNCTION(simdutf_utf16_length_from_utf32);
PHP_FUNCTION(simdutf_utf16_length_from_latin1);

PHP_FUNCTION(simdutf_utf32_length_from_utf8);
PHP_FUNCTION(simdutf_utf32_length_from_utf16);
PHP_FUNCTION(simdutf_utf32_length_from_utf16le);
PHP_FUNCTION(simdutf_utf32_length_from_utf16be);

void register_simdutf_length_functions(void);

END_EXTERN_C()

#endif /* PHP_SIMDUTF_LENGTH_H */
