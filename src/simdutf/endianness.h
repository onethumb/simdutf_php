/**
 * Change the endianness of the input. Can be used to go from UTF-16LE to
 * UTF-16BE or from UTF-16BE to UTF-16LE.
 *
 * This function does not validate the input.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16 string to process
 * @param length        the length of the string in 2-byte code units (char16_t)
 * @param output        the pointer to buffer that can hold the conversion
 * result
 */
void change_endianness_utf16(const char16_t *input, size_t length,
                             char16_t *output) noexcept;
