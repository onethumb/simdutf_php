
/**
 * Return the number of bytes that this Latin1 string would require in UTF-8
 * format.
 *
 * @param input         the Latin1 string to convert
 * @param length        the length of the string bytes
 * @return the number of bytes required to encode the Latin1 string as UTF-8
 */
simdutf_warn_unused size_t utf8_length_from_latin1(const char *input,
                                                   size_t length) noexcept;

/**
 * Compute the number of bytes that this UTF-8 string would require in Latin1
 * format.
 *
 * This function does not validate the input. It is acceptable to pass invalid
 * UTF-8 strings but in such cases the result is implementation defined.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-8 string to convert
 * @param length        the length of the string in byte
 * @return the number of bytes required to encode the UTF-8 string as Latin1
 */
simdutf_warn_unused size_t latin1_length_from_utf8(const char *input,
                                                   size_t length) noexcept;

/**
 * Compute the number of 2-byte code units that this UTF-8 string would require
 * in UTF-16LE format.
 *
 * This function does not validate the input. It is acceptable to pass invalid
 * UTF-8 strings but in such cases the result is implementation defined.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-8 string to process
 * @param length        the length of the string in bytes
 * @return the number of char16_t code units required to encode the UTF-8 string
 * as UTF-16LE
 */
simdutf_warn_unused size_t utf16_length_from_utf8(const char *input,
                                                  size_t length) noexcept;

/**
 * Compute the number of 4-byte code units that this UTF-8 string would require
 * in UTF-32 format.
 *
 * This function is equivalent to count_utf8
 *
 * This function does not validate the input. It is acceptable to pass invalid
 * UTF-8 strings but in such cases the result is implementation defined.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-8 string to process
 * @param length        the length of the string in bytes
 * @return the number of char32_t code units required to encode the UTF-8 string
 * as UTF-32
 */
simdutf_warn_unused size_t utf32_length_from_utf8(const char *input,
                                                  size_t length) noexcept;

/*
 * Compute the number of bytes that this UTF-16LE/BE string would require in
 * Latin1 format.
 *
 * This function does not validate the input. It is acceptable to pass invalid
 * UTF-16 strings but in such cases the result is implementation defined.
 *
 * This function is not BOM-aware.
 *
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @return the number of bytes required to encode the UTF-16LE string as Latin1
 */
simdutf_warn_unused size_t latin1_length_from_utf16(size_t length) noexcept;

/**
 * Using native endianness; Compute the number of bytes that this UTF-16
 * string would require in UTF-8 format.
 *
 * This function does not validate the input. It is acceptable to pass invalid
 * UTF-16 strings but in such cases the result is implementation defined.
 *
 * @param input         the UTF-16 string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @return the number of bytes required to encode the UTF-16LE string as UTF-8
 */
simdutf_warn_unused size_t utf8_length_from_utf16(const char16_t *input,
                                                  size_t length) noexcept;

/**
 * Compute the number of bytes that this UTF-16LE string would require in UTF-8
 * format.
 *
 * This function does not validate the input. It is acceptable to pass invalid
 * UTF-16 strings but in such cases the result is implementation defined.
 *
 * @param input         the UTF-16LE string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @return the number of bytes required to encode the UTF-16LE string as UTF-8
 */
simdutf_warn_unused size_t utf8_length_from_utf16le(const char16_t *input,
                                                    size_t length) noexcept;

/**
 * Compute the number of bytes that this UTF-16BE string would require in UTF-8
 * format.
 *
 * This function does not validate the input. It is acceptable to pass invalid
 * UTF-16 strings but in such cases the result is implementation defined.
 *
 * @param input         the UTF-16BE string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @return the number of bytes required to encode the UTF-16BE string as UTF-8
 */
simdutf_warn_unused size_t utf8_length_from_utf16be(const char16_t *input,
                                                    size_t length) noexcept;


/**
 * Compute the number of bytes that this UTF-32 string would require in UTF-8
 * format.
 *
 * This function does not validate the input. It is acceptable to pass invalid
 * UTF-32 strings but in such cases the result is implementation defined.
 *
 * @param input         the UTF-32 string to convert
 * @param length        the length of the string in 4-byte code units (char32_t)
 * @return the number of bytes required to encode the UTF-32 string as UTF-8
 */
simdutf_warn_unused size_t utf8_length_from_utf32(const char32_t *input,
                                                  size_t length) noexcept;

/**
 * Compute the number of two-byte code units that this UTF-32 string would
 * require in UTF-16 format.
 *
 * This function does not validate the input. It is acceptable to pass invalid
 * UTF-32 strings but in such cases the result is implementation defined.
 *
 * @param input         the UTF-32 string to convert
 * @param length        the length of the string in 4-byte code units (char32_t)
 * @return the number of bytes required to encode the UTF-32 string as UTF-16
 */
simdutf_warn_unused size_t utf16_length_from_utf32(const char32_t *input,
                                                   size_t length) noexcept;

/**
 * Using native endianness; Compute the number of bytes that this UTF-16
 * string would require in UTF-32 format.
 *
 * This function is equivalent to count_utf16.
 *
 * This function does not validate the input. It is acceptable to pass invalid
 * UTF-16 strings but in such cases the result is implementation defined.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16 string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @return the number of bytes required to encode the UTF-16LE string as UTF-32
 */
simdutf_warn_unused size_t utf32_length_from_utf16(const char16_t *input,
                                                   size_t length) noexcept;

/**
 * Compute the number of bytes that this UTF-16LE string would require in UTF-32
 * format.
 *
 * This function is equivalent to count_utf16le.
 *
 * This function does not validate the input. It is acceptable to pass invalid
 * UTF-16 strings but in such cases the result is implementation defined.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16LE string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @return the number of bytes required to encode the UTF-16LE string as UTF-32
 */
simdutf_warn_unused size_t utf32_length_from_utf16le(const char16_t *input,
                                                     size_t length) noexcept;

/**
 * Compute the number of bytes that this UTF-16BE string would require in UTF-32
 * format.
 *
 * This function is equivalent to count_utf16be.
 *
 * This function does not validate the input. It is acceptable to pass invalid
 * UTF-16 strings but in such cases the result is implementation defined.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16BE string to convert
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @return the number of bytes required to encode the UTF-16BE string as UTF-32
 */
simdutf_warn_unused size_t utf32_length_from_utf16be(const char16_t *input,
                                                     size_t length) noexcept;
