
/**
 * Convert possibly broken UTF-32 string into UTF-8 string and stop on error.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-32 string to convert
 * @param length        the length of the string in 4-byte code units (char32_t)
 * @param utf8_buffer   the pointer to buffer that can hold conversion result
 * @return a result pair struct (of type simdutf::result containing the two
 * fields error and count) with an error code and either position of the error
 * (in the input in code units) if any, or the number of char written if
 * successful.
 */
simdutf_warn_unused result convert_utf32_to_utf8_with_errors(
    const char32_t *input, size_t length, char *utf8_buffer) noexcept;

/**
 * Convert possibly broken UTF-32 string into Latin1 string and stop on error.
 * If the string cannot be represented as Latin1, an error is returned.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-32 string to convert
 * @param length        the length of the string in 4-byte code units (char32_t)
 * @param latin1_buffer   the pointer to buffer that can hold conversion result
 * @return a result pair struct (of type simdutf::result containing the two
 * fields error and count) with an error code and either position of the error
 * (in the input in code units) if any, or the number of char written if
 * successful.
 */
simdutf_warn_unused result convert_utf32_to_latin1_with_errors(
    const char32_t *input, size_t length, char *latin1_buffer) noexcept;

/**
 * Using native endianness, convert possibly broken UTF-32 string into UTF-16
 * string and stop on error.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-32 string to convert
 * @param length        the length of the string in 4-byte code units (char32_t)
 * @param utf16_buffer   the pointer to buffer that can hold conversion result
 * @return a result pair struct (of type simdutf::result containing the two
 * fields error and count) with an error code and either position of the error
 * (in the input in code units) if any, or the number of char16_t written if
 * successful.
 */
simdutf_warn_unused result convert_utf32_to_utf16_with_errors(
    const char32_t *input, size_t length, char16_t *utf16_buffer) noexcept;

/**
 * Convert possibly broken UTF-32 string into UTF-16LE string and stop on error.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-32 string to convert
 * @param length        the length of the string in 4-byte code units (char32_t)
 * @param utf16_buffer   the pointer to buffer that can hold conversion result
 * @return a result pair struct (of type simdutf::result containing the two
 * fields error and count) with an error code and either position of the error
 * (in the input in code units) if any, or the number of char16_t written if
 * successful.
 */
simdutf_warn_unused result convert_utf32_to_utf16le_with_errors(
    const char32_t *input, size_t length, char16_t *utf16_buffer) noexcept;

/**
 * Convert possibly broken UTF-32 string into UTF-16BE string and stop on error.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-32 string to convert
 * @param length        the length of the string in 4-byte code units (char32_t)
 * @param utf16_buffer   the pointer to buffer that can hold conversion result
 * @return a result pair struct (of type simdutf::result containing the two
 * fields error and count) with an error code and either position of the error
 * (in the input in code units) if any, or the number of char16_t written if
 * successful.
 */
simdutf_warn_unused result convert_utf32_to_utf16be_with_errors(
    const char32_t *input, size_t length, char16_t *utf16_buffer) noexcept;
