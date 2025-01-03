
/**
 * Convert Latin1 string into UTF8 string.
 *
 * This function is suitable to work with inputs from untrusted sources.
 *
 * @param input         the Latin1 string to convert
 * @param length        the length of the string in bytes
 * @param utf8_output   the pointer to buffer that can hold conversion result
 * @return the number of written char; 0 if conversion is not possible
 */
simdutf_warn_unused size_t convert_latin1_to_utf8(const char *input,
                                                  size_t length,
                                                  char *utf8_output) noexcept;

/**
 * Convert Latin1 string into UTF8 string with output limit.
 *
 * This function is suitable to work with inputs from untrusted sources.
 *
 * @param input         the Latin1 string to convert
 * @param length        the length of the string in bytes
 * @param utf8_output  	the pointer to buffer that can hold conversion result
 * @param utf8_len      the maximum output length
 * @return the number of written char; 0 if conversion is not possible
 */
simdutf_warn_unused size_t
convert_latin1_to_utf8_safe(const char *input, size_t length, char *utf8_output,
                            size_t utf8_len) noexcept;

/**
 * Convert possibly Latin1 string into UTF-16LE string.
 *
 * This function is suitable to work with inputs from untrusted sources.
 *
 * @param input         the Latin1  string to convert
 * @param length        the length of the string in bytes
 * @param utf16_buffer  the pointer to buffer that can hold conversion result
 * @return the number of written char16_t; 0 if conversion is not possible
 */
simdutf_warn_unused size_t convert_latin1_to_utf16le(
    const char *input, size_t length, char16_t *utf16_output) noexcept;

/**
 * Convert Latin1 string into UTF-16BE string.
 *
 * This function is suitable to work with inputs from untrusted sources.
 *
 * @param input         the Latin1 string to convert
 * @param length        the length of the string in bytes
 * @param utf16_buffer  the pointer to buffer that can hold conversion result
 * @return the number of written char16_t; 0 if conversion is not possible
 */
simdutf_warn_unused size_t convert_latin1_to_utf16be(
    const char *input, size_t length, char16_t *utf16_output) noexcept;

/**
 * Convert Latin1 string into UTF-32 string.
 *
 * This function is suitable to work with inputs from untrusted sources.
 *
 * @param input         the Latin1 string to convert
 * @param length        the length of the string in bytes
 * @param utf32_buffer  the pointer to buffer that can hold conversion result
 * @return the number of written char32_t; 0 if conversion is not possible
 */
simdutf_warn_unused size_t convert_latin1_to_utf32(
    const char *input, size_t length, char32_t *utf32_buffer) noexcept;
