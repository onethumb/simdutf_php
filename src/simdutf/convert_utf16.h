
/**
 * Using native endianness, convert possibly broken UTF-16 string into UTF-8
 * string.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16 string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @param utf8_buffer   the pointer to buffer that can hold conversion result
 * @return number of written code units; 0 if input is not a valid UTF-16LE
 * string
 */
simdutf_warn_unused size_t convert_utf16_to_utf8(const char16_t *input,
                                                 size_t length,
                                                 char *utf8_buffer) noexcept;

/**
 * Using native endianness, convert possibly broken UTF-16 string into Latin1
 * string.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16 string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @param latin1_buffer   the pointer to buffer that can hold conversion result
 * @return number of written code units; 0 if input is not a valid UTF-16 string
 * or if it cannot be represented as Latin1
 */
simdutf_warn_unused size_t convert_utf16_to_latin1(
    const char16_t *input, size_t length, char *latin1_buffer) noexcept;

/**
 * Convert possibly broken UTF-16LE string into Latin1 string.
 * If the string cannot be represented as Latin1, an error
 * is returned.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16LE string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @param latin1_buffer   the pointer to buffer that can hold conversion result
 * @return number of written code units; 0 if input is not a valid UTF-16LE
 * string or if it cannot be represented as Latin1
 */
simdutf_warn_unused size_t convert_utf16le_to_latin1(
    const char16_t *input, size_t length, char *latin1_buffer) noexcept;

/**
 * Convert possibly broken UTF-16BE string into Latin1 string.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16BE string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @param latin1_buffer   the pointer to buffer that can hold conversion result
 * @return number of written code units; 0 if input is not a valid UTF-16BE
 * string or if it cannot be represented as Latin1
 */
simdutf_warn_unused size_t convert_utf16be_to_latin1(
    const char16_t *input, size_t length, char *latin1_buffer) noexcept;

/**
 * Convert possibly broken UTF-16LE string into UTF-8 string.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16LE string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @param utf8_buffer   the pointer to buffer that can hold conversion result
 * @return number of written code units; 0 if input is not a valid UTF-16LE
 * string
 */
simdutf_warn_unused size_t convert_utf16le_to_utf8(const char16_t *input,
                                                   size_t length,
                                                   char *utf8_buffer) noexcept;

/**
 * Convert possibly broken UTF-16BE string into UTF-8 string.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16BE string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @param utf8_buffer   the pointer to buffer that can hold conversion result
 * @return number of written code units; 0 if input is not a valid UTF-16LE
 * string
 */
simdutf_warn_unused size_t convert_utf16be_to_utf8(const char16_t *input,
                                                   size_t length,
                                                   char *utf8_buffer) noexcept;

/**
 * Using native endianness, convert possibly broken UTF-16 string into Latin1
 * string.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16 string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @param latin1_buffer   the pointer to buffer that can hold conversion result
 * @return a result pair struct (of type simdutf::result containing the two
 * fields error and count) with an error code and either position of the error
 * (in the input in code units) if any, or the number of char written if
 * successful.
 */
simdutf_warn_unused result convert_utf16_to_latin1_with_errors(
    const char16_t *input, size_t length, char *latin1_buffer) noexcept;

/**
 * Convert possibly broken UTF-16LE string into Latin1 string.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16LE string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @param latin1_buffer   the pointer to buffer that can hold conversion result
 * @return a result pair struct (of type simdutf::result containing the two
 * fields error and count) with an error code and either position of the error
 * (in the input in code units) if any, or the number of char written if
 * successful.
 */
simdutf_warn_unused result convert_utf16le_to_latin1_with_errors(
    const char16_t *input, size_t length, char *latin1_buffer) noexcept;

/**
 * Convert possibly broken UTF-16BE string into Latin1 string.
 * If the string cannot be represented as Latin1, an error
 * is returned.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16BE string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @param latin1_buffer   the pointer to buffer that can hold conversion result
 * @return a result pair struct (of type simdutf::result containing the two
 * fields error and count) with an error code and either position of the error
 * (in the input in code units) if any, or the number of char written if
 * successful.
 */
simdutf_warn_unused result convert_utf16be_to_latin1_with_errors(
    const char16_t *input, size_t length, char *latin1_buffer) noexcept;

/**
 * Using native endianness, convert possibly broken UTF-16 string into UTF-8
 * string and stop on error.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16 string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @param utf8_buffer   the pointer to buffer that can hold conversion result
 * @return a result pair struct (of type simdutf::result containing the two
 * fields error and count) with an error code and either position of the error
 * (in the input in code units) if any, or the number of char written if
 * successful.
 */
simdutf_warn_unused result convert_utf16_to_utf8_with_errors(
    const char16_t *input, size_t length, char *utf8_buffer) noexcept;

/**
 * Convert possibly broken UTF-16LE string into UTF-8 string and stop on error.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16LE string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @param utf8_buffer   the pointer to buffer that can hold conversion result
 * @return a result pair struct (of type simdutf::result containing the two
 * fields error and count) with an error code and either position of the error
 * (in the input in code units) if any, or the number of char written if
 * successful.
 */
simdutf_warn_unused result convert_utf16le_to_utf8_with_errors(
    const char16_t *input, size_t length, char *utf8_buffer) noexcept;

/**
 * Convert possibly broken UTF-16BE string into UTF-8 string and stop on error.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16BE string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @param utf8_buffer   the pointer to buffer that can hold conversion result
 * @return a result pair struct (of type simdutf::result containing the two
 * fields error and count) with an error code and either position of the error
 * (in the input in code units) if any, or the number of char written if
 * successful.
 */
simdutf_warn_unused result convert_utf16be_to_utf8_with_errors(
    const char16_t *input, size_t length, char *utf8_buffer) noexcept;

/**
 * Using native endianness, convert valid UTF-16 string into UTF-8 string.
 *
 * This function assumes that the input string is valid UTF-16LE.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16 string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @param utf8_buffer   the pointer to buffer that can hold the conversion
 * result
 * @return number of written code units; 0 if conversion is not possible
 */
simdutf_warn_unused size_t convert_valid_utf16_to_utf8(
    const char16_t *input, size_t length, char *utf8_buffer) noexcept;

/**
 * Using native endianness, convert UTF-16 string into Latin1 string.
 *
 * This function assumes that the input string is valid UTF-16 and that it can
 * be represented as Latin1. If you violate this assumption, the result is
 * implementation defined and may include system-dependent behavior such as
 * crashes.
 *
 * This function is for expert users only and not part of our public API. Use
 * convert_utf16_to_latin1 instead. The function may be removed from the library
 * in the future.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16 string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @param latin1_buffer   the pointer to buffer that can hold conversion result
 * @return number of written code units; 0 if conversion is not possible
 */
simdutf_warn_unused size_t convert_valid_utf16_to_latin1(
    const char16_t *input, size_t length, char *latin1_buffer) noexcept;

/**
 * Convert valid UTF-16LE string into Latin1 string.
 *
 * This function assumes that the input string is valid UTF-16LE and that it can
 * be represented as Latin1. If you violate this assumption, the result is
 * implementation defined and may include system-dependent behavior such as
 * crashes.
 *
 * This function is for expert users only and not part of our public API. Use
 * convert_utf16le_to_latin1 instead. The function may be removed from the
 * library in the future.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16LE string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @param latin1_buffer   the pointer to buffer that can hold conversion result
 * @return number of written code units; 0 if conversion is not possible
 */
simdutf_warn_unused size_t convert_valid_utf16le_to_latin1(
    const char16_t *input, size_t length, char *latin1_buffer) noexcept;

/**
 * Convert valid UTF-16BE string into Latin1 string.
 *
 * This function assumes that the input string is valid UTF-16BE and that it can
 * be represented as Latin1. If you violate this assumption, the result is
 * implementation defined and may include system-dependent behavior such as
 * crashes.
 *
 * This function is for expert users only and not part of our public API. Use
 * convert_utf16be_to_latin1 instead. The function may be removed from the
 * library in the future.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16BE string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @param latin1_buffer   the pointer to buffer that can hold conversion result
 * @return number of written code units; 0 if conversion is not possible
 */
simdutf_warn_unused size_t convert_valid_utf16be_to_latin1(
    const char16_t *input, size_t length, char *latin1_buffer) noexcept;

/**
 * Convert valid UTF-16LE string into UTF-8 string.
 *
 * This function assumes that the input string is valid UTF-16LE and that it can
 * be represented as Latin1.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16LE string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @param utf8_buffer   the pointer to buffer that can hold the conversion
 * result
 * @return number of written code units; 0 if conversion is not possible
 */
simdutf_warn_unused size_t convert_valid_utf16le_to_utf8(
    const char16_t *input, size_t length, char *utf8_buffer) noexcept;

/**
 * Convert valid UTF-16BE string into UTF-8 string.
 *
 * This function assumes that the input string is valid UTF-16BE.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16BE string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @param utf8_buffer   the pointer to buffer that can hold the conversion
 * result
 * @return number of written code units; 0 if conversion is not possible
 */
simdutf_warn_unused size_t convert_valid_utf16be_to_utf8(
    const char16_t *input, size_t length, char *utf8_buffer) noexcept;

/**
 * Using native endianness, convert possibly broken UTF-16 string into UTF-32
 * string.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16 string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @param utf32_buffer   the pointer to buffer that can hold conversion result
 * @return number of written code units; 0 if input is not a valid UTF-16LE
 * string
 */
simdutf_warn_unused size_t convert_utf16_to_utf32(
    const char16_t *input, size_t length, char32_t *utf32_buffer) noexcept;

/**
 * Convert possibly broken UTF-16LE string into UTF-32 string.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16LE string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @param utf32_buffer   the pointer to buffer that can hold conversion result
 * @return number of written code units; 0 if input is not a valid UTF-16LE
 * string
 */
simdutf_warn_unused size_t convert_utf16le_to_utf32(
    const char16_t *input, size_t length, char32_t *utf32_buffer) noexcept;

/**
 * Convert possibly broken UTF-16BE string into UTF-32 string.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16BE string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @param utf32_buffer   the pointer to buffer that can hold conversion result
 * @return number of written code units; 0 if input is not a valid UTF-16LE
 * string
 */
simdutf_warn_unused size_t convert_utf16be_to_utf32(
    const char16_t *input, size_t length, char32_t *utf32_buffer) noexcept;

/**
 * Using native endianness, convert possibly broken UTF-16 string into
 * UTF-32 string and stop on error.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16 string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @param utf32_buffer   the pointer to buffer that can hold conversion result
 * @return a result pair struct (of type simdutf::result containing the two
 * fields error and count) with an error code and either position of the error
 * (in the input in code units) if any, or the number of char32_t written if
 * successful.
 */
simdutf_warn_unused result convert_utf16_to_utf32_with_errors(
    const char16_t *input, size_t length, char32_t *utf32_buffer) noexcept;

/**
 * Convert possibly broken UTF-16LE string into UTF-32 string and stop on error.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16LE string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @param utf32_buffer   the pointer to buffer that can hold conversion result
 * @return a result pair struct (of type simdutf::result containing the two
 * fields error and count) with an error code and either position of the error
 * (in the input in code units) if any, or the number of char32_t written if
 * successful.
 */
simdutf_warn_unused result convert_utf16le_to_utf32_with_errors(
    const char16_t *input, size_t length, char32_t *utf32_buffer) noexcept;

/**
 * Convert possibly broken UTF-16BE string into UTF-32 string and stop on error.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16BE string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @param utf32_buffer   the pointer to buffer that can hold conversion result
 * @return a result pair struct (of type simdutf::result containing the two
 * fields error and count) with an error code and either position of the error
 * (in the input in code units) if any, or the number of char32_t written if
 * successful.
 */
simdutf_warn_unused result convert_utf16be_to_utf32_with_errors(
    const char16_t *input, size_t length, char32_t *utf32_buffer) noexcept;

/**
 * Using native endianness, convert valid UTF-16 string into UTF-32 string.
 *
 * This function assumes that the input string is valid UTF-16 (native
 * endianness).
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16 string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @param utf32_buffer   the pointer to buffer that can hold the conversion
 * result
 * @return number of written code units; 0 if conversion is not possible
 */
simdutf_warn_unused size_t convert_valid_utf16_to_utf32(
    const char16_t *input, size_t length, char32_t *utf32_buffer) noexcept;

/**
 * Convert valid UTF-16LE string into UTF-32 string.
 *
 * This function assumes that the input string is valid UTF-16LE.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16LE string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @param utf32_buffer   the pointer to buffer that can hold the conversion
 * result
 * @return number of written code units; 0 if conversion is not possible
 */
simdutf_warn_unused size_t convert_valid_utf16le_to_utf32(
    const char16_t *input, size_t length, char32_t *utf32_buffer) noexcept;

/**
 * Convert valid UTF-16BE string into UTF-32 string.
 *
 * This function assumes that the input string is valid UTF-16LE.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16BE string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @param utf32_buffer   the pointer to buffer that can hold the conversion
 * result
 * @return number of written code units; 0 if conversion is not possible
 */
simdutf_warn_unused size_t convert_valid_utf16be_to_utf32(
    const char16_t *input, size_t length, char32_t *utf32_buffer) noexcept;
