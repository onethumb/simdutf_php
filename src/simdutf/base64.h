/**
 * Convert a base64 input to a binary output.
 *
 * This function follows the WHATWG forgiving-base64 format, which means that it
 * will ignore any ASCII spaces in the input. You may provide a padded input
 * (with one or two equal signs at the end) or an unpadded input (without any
 * equal signs at the end).
 *
 * See https://infra.spec.whatwg.org/#forgiving-base64-decode
 *
 * This function will fail in case of invalid input. When last_chunk_options =
 * loose, there are two possible reasons for failure: the input contains a
 * number of base64 characters that when divided by 4, leaves a single remainder
 * character (BASE64_INPUT_REMAINDER), or the input contains a character that is
 * not a valid base64 character (INVALID_BASE64_CHARACTER).
 *
 * When the error is INVALID_BASE64_CHARACTER, r.count contains the index in the
 * input where the invalid character was found. When the error is
 * BASE64_INPUT_REMAINDER, then r.count contains the number of bytes decoded.
 *
 * The default option (simdutf::base64_default) expects the characters `+` and
 * `/` as part of its alphabet. The URL option (simdutf::base64_url) expects the
 * characters `-` and `_` as part of its alphabet.
 *
 * The padding (`=`) is validated if present. There may be at most two padding
 * characters at the end of the input. If there are any padding characters, the
 * total number of characters (excluding spaces but including padding
 * characters) must be divisible by four.
 *
 * You should call this function with a buffer that is at least
 * maximal_binary_length_from_base64(input, length) bytes long. If you fail to
 * provide that much space, the function may cause a buffer overflow.
 *
 * Advanced users may want to taylor how the last chunk is handled. By default,
 * we use a loose (forgiving) approach but we also support a strict approach
 * as well as a stop_before_partial approach, as per the following proposal:
 *
 * https://tc39.es/proposal-arraybuffer-base64/spec/#sec-frombase64
 *
 * @param input         the base64 string to process
 * @param length        the length of the string in bytes
 * @param output        the pointer to buffer that can hold the conversion
 * result (should be at least maximal_binary_length_from_base64(input, length)
 * bytes long).
 * @param options       the base64 options to use, usually base64_default or
 * base64_url, and base64_default by default.
 * @param last_chunk_options the last chunk handling options,
 * last_chunk_handling_options::loose by default
 * but can also be last_chunk_handling_options::strict or
 * last_chunk_handling_options::stop_before_partial.
 * @return a result pair struct (of type simdutf::result containing the two
 * fields error and count) with an error code and either position of the error
 * (in the input in bytes) if any, or the number of bytes written if successful.
 */
simdutf_warn_unused result base64_to_binary(
    const char *input, size_t length, char *output,
    base64_options options = base64_default,
    last_chunk_handling_options last_chunk_options = loose) noexcept;


/**
 * Convert a binary input to a base64 output.
 *
 * The default option (simdutf::base64_default) uses the characters `+` and `/`
 * as part of its alphabet. Further, it adds padding (`=`) at the end of the
 * output to ensure that the output length is a multiple of four.
 *
 * The URL option (simdutf::base64_url) uses the characters `-` and `_` as part
 * of its alphabet. No padding is added at the end of the output.
 *
 * This function always succeeds.
 *
 * @param input         the binary to process
 * @param length        the length of the input in bytes
 * @param output        the pointer to buffer that can hold the conversion
 * result (should be at least base64_length_from_binary(length) bytes long)
 * @param options       the base64 options to use, can be base64_default or
 * base64_url, is base64_default by default.
 * @return number of written bytes, will be equal to
 * base64_length_from_binary(length, options)
 */
size_t binary_to_base64(const char *input, size_t length, char *output,
                        base64_options options = base64_default) noexcept;

/**
 * Convert a base64 input to a binary output.
 *
 * This function follows the WHATWG forgiving-base64 format, which means that it
 * will ignore any ASCII spaces in the input. You may provide a padded input
 * (with one or two equal signs at the end) or an unpadded input (without any
 * equal signs at the end).
 *
 * See https://infra.spec.whatwg.org/#forgiving-base64-decode
 *
 * This function will fail in case of invalid input. When last_chunk_options =
 * loose, there are three possible reasons for failure: the input contains a
 * number of base64 characters that when divided by 4, leaves a single remainder
 * character (BASE64_INPUT_REMAINDER), the input contains a character that is
 * not a valid base64 character (INVALID_BASE64_CHARACTER), or the output buffer
 * is too small (OUTPUT_BUFFER_TOO_SMALL).
 *
 * When OUTPUT_BUFFER_TOO_SMALL, we return both the number of bytes written
 * and the number of units processed, see description of the parameters and
 * returned value.
 *
 * When the error is INVALID_BASE64_CHARACTER, r.count contains the index in the
 * input where the invalid character was found. When the error is
 * BASE64_INPUT_REMAINDER, then r.count contains the number of bytes decoded.
 *
 * The default option (simdutf::base64_default) expects the characters `+` and
 * `/` as part of its alphabet. The URL option (simdutf::base64_url) expects the
 * characters `-` and `_` as part of its alphabet.
 *
 * The padding (`=`) is validated if present. There may be at most two padding
 * characters at the end of the input. If there are any padding characters, the
 * total number of characters (excluding spaces but including padding
 * characters) must be divisible by four.
 *
 * The INVALID_BASE64_CHARACTER cases are considered fatal and you are expected
 * to discard the output.
 *
 * Advanced users may want to taylor how the last chunk is handled. By default,
 * we use a loose (forgiving) approach but we also support a strict approach
 * as well as a stop_before_partial approach, as per the following proposal:
 *
 * https://tc39.es/proposal-arraybuffer-base64/spec/#sec-frombase64
 *
 * @param input         the base64 string to process
 * @param length        the length of the string in bytes
 * @param output        the pointer to buffer that can hold the conversion
 * result.
 * @param outlen        the number of bytes that can be written in the output
 * buffer. Upon return, it is modified to reflect how many bytes were written.
 * @param options       the base64 options to use, can be base64_default or
 * base64_url, is base64_default by default.
 * @param last_chunk_options the last chunk handling options,
 * last_chunk_handling_options::loose by default
 * but can also be last_chunk_handling_options::strict or
 * last_chunk_handling_options::stop_before_partial.
 * @return a result pair struct (of type simdutf::result containing the two
 * fields error and count) with an error code and position of the
 * INVALID_BASE64_CHARACTER error (in the input in units) if any, or the number
 * of units processed if successful.
 */
simdutf_warn_unused result
base64_to_binary_safe(const char *input, size_t length, char *output,
                      size_t &outlen, base64_options options = base64_default,
                      last_chunk_handling_options last_chunk_options =
                          last_chunk_handling_options::loose) noexcept;
