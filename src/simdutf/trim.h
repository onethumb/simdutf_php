/**
 * Given a valid UTF-8 string having a possibly truncated last character,
 * this function checks the end of string. If the last character is truncated
 * (or partial), then it returns a shorter length (shorter by 1 to 3 bytes) so
 * that the short UTF-8 strings only contain complete characters. If there is no
 * truncated character, the original length is returned.
 *
 * This function assumes that the input string is valid UTF-8, but possibly
 * truncated.
 *
 * @param input         the UTF-8 string to process
 * @param length        the length of the string in bytes
 * @return the length of the string in bytes, possibly shorter by 1 to 3 bytes
 */
simdutf_warn_unused size_t trim_partial_utf8(const char *input, size_t length);

/**
 * Given a valid UTF-16BE string having a possibly truncated last character,
 * this function checks the end of string. If the last character is truncated
 * (or partial), then it returns a shorter length (shorter by 1 unit) so that
 * the short UTF-16BE strings only contain complete characters. If there is no
 * truncated character, the original length is returned.
 *
 * This function assumes that the input string is valid UTF-16BE, but possibly
 * truncated.
 *
 * @param input         the UTF-16BE string to process
 * @param length        the length of the string in bytes
 * @return the length of the string in bytes, possibly shorter by 1 unit
 */
simdutf_warn_unused size_t trim_partial_utf16be(const char16_t *input,
                                                size_t length);

/**
 * Given a valid UTF-16LE string having a possibly truncated last character,
 * this function checks the end of string. If the last character is truncated
 * (or partial), then it returns a shorter length (shorter by 1 unit) so that
 * the short UTF-16LE strings only contain complete characters. If there is no
 * truncated character, the original length is returned.
 *
 * This function assumes that the input string is valid UTF-16LE, but possibly
 * truncated.
 *
 * @param input         the UTF-16LE string to process
 * @param length        the length of the string in bytes
 * @return the length of the string in unit, possibly shorter by 1 unit
 */
simdutf_warn_unused size_t trim_partial_utf16le(const char16_t *input,
                                                size_t length);

/**
 * Given a valid UTF-16 string having a possibly truncated last character,
 * this function checks the end of string. If the last character is truncated
 * (or partial), then it returns a shorter length (shorter by 1 unit) so that
 * the short UTF-16 strings only contain complete characters. If there is no
 * truncated character, the original length is returned.
 *
 * This function assumes that the input string is valid UTF-16, but possibly
 * truncated. We use the native endianness.
 *
 * @param input         the UTF-16 string to process
 * @param length        the length of the string in bytes
 * @return the length of the string in unit, possibly shorter by 1 unit
 */
simdutf_warn_unused size_t trim_partial_utf16(const char16_t *input,
                                              size_t length);
