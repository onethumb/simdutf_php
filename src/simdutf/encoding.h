/**
 * Autodetect the encoding of the input, a single encoding is recommended.
 * E.g., the function might return simdutf::encoding_type::UTF8,
 * simdutf::encoding_type::UTF16_LE, simdutf::encoding_type::UTF16_BE, or
 * simdutf::encoding_type::UTF32_LE.
 *
 * @param input the string to analyze.
 * @param length the length of the string in bytes.
 * @return the detected encoding type
 */
simdutf_warn_unused simdutf::encoding_type
autodetect_encoding(const char *input, size_t length) noexcept;
simdutf_really_inline simdutf_warn_unused simdutf::encoding_type
autodetect_encoding(const uint8_t *input, size_t length) noexcept {
  return autodetect_encoding(reinterpret_cast<const char *>(input), length);
}

/**
 * Autodetect the possible encodings of the input in one pass.
 * E.g., if the input might be UTF-16LE or UTF-8, this function returns
 * the value (simdutf::encoding_type::UTF8 | simdutf::encoding_type::UTF16_LE).
 *
 * Overridden by each implementation.
 *
 * @param input the string to analyze.
 * @param length the length of the string in bytes.
 * @return the detected encoding type
 */
simdutf_warn_unused int detect_encodings(const char *input,
                                         size_t length) noexcept;
simdutf_really_inline simdutf_warn_unused int
detect_encodings(const uint8_t *input, size_t length) noexcept {
  return detect_encodings(reinterpret_cast<const char *>(input), length);
}
