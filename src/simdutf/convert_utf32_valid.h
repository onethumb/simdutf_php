/**
   * Convert valid UTF-32 string into Latin1 string.
   *
   * This function assumes that the input string is valid UTF-32 and can be
   * represented as Latin1. If you violate this assumption, the result is
   * implementation defined and may include system-dependent behavior such as
   * crashes.
   *
   * This function is for expert users only and not part of our public API. Use
   * convert_utf32_to_latin1 instead.
   *
   * This function is not BOM-aware.
   *
   * @param input         the UTF-32 string to convert
   * @param length        the length of the string in 4-byte code units
   * (char32_t)
   * @param latin1_buffer   the pointer to buffer that can hold the conversion
   * result
   * @return number of written code units; 0 if conversion is not possible
   */
  simdutf_warn_unused virtual size_t
  convert_valid_utf32_to_latin1(const char32_t *input, size_t length,
                                char *latin1_buffer) const noexcept = 0;

  /**
   * Convert valid UTF-32 string into UTF-8 string.
   *
   * This function assumes that the input string is valid UTF-32.
   *
   * This function is not BOM-aware.
   *
   * @param input         the UTF-32 string to convert
   * @param length        the length of the string in 4-byte code units
   * (char32_t)
   * @param utf8_buffer   the pointer to buffer that can hold the conversion
   * result
   * @return number of written code units; 0 if conversion is not possible
   */
  simdutf_warn_unused virtual size_t
  convert_valid_utf32_to_utf8(const char32_t *input, size_t length,
                              char *utf8_buffer) const noexcept = 0;

  /**
   * Convert valid UTF-32 string into UTF-16LE string.
   *
   * This function assumes that the input string is valid UTF-32.
   *
   * This function is not BOM-aware.
   *
   * @param input         the UTF-32 string to convert
   * @param length        the length of the string in 4-byte code units
   * (char32_t)
   * @param utf16_buffer   the pointer to buffer that can hold the conversion
   * result
   * @return number of written code units; 0 if conversion is not possible
   */
  simdutf_warn_unused virtual size_t
  convert_valid_utf32_to_utf16le(const char32_t *input, size_t length,
                                 char16_t *utf16_buffer) const noexcept = 0;

  /**
   * Convert valid UTF-32 string into UTF-16BE string.
   *
   * This function assumes that the input string is valid UTF-32.
   *
   * This function is not BOM-aware.
   *
   * @param input         the UTF-32 string to convert
   * @param length        the length of the string in 4-byte code units
   * (char32_t)
   * @param utf16_buffer   the pointer to buffer that can hold the conversion
   * result
   * @return number of written code units; 0 if conversion is not possible
   */
  simdutf_warn_unused virtual size_t
  convert_valid_utf32_to_utf16be(const char32_t *input, size_t length,
                                 char16_t *utf16_buffer) const noexcept = 0;


/**
 * Using native endianness, convert valid UTF-32 string into a UTF-16 string.
 *
 * This function assumes that the input string is valid UTF-32.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-32 string to convert
 * @param length        the length of the string in 4-byte code units (char32_t)
 * @param utf16_buffer   the pointer to buffer that can hold the conversion
 * result
 * @return number of written code units; 0 if conversion is not possible
 */
simdutf_warn_unused size_t convert_valid_utf32_to_utf16(
    const char32_t *input, size_t length, char16_t *utf16_buffer) noexcept;
