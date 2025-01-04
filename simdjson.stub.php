<?php

/**
 * @generate-class-entries
 * @undocumentable
 */

// validation
function simdutf_validate_utf8(string $string): bool {}
function simdutf_validate_ascii(string $string): bool {}
function simdutf_validate_utf16(string $string): bool {}
function simdutf_validate_utf16le(string $string): bool {}
function simdutf_validate_utf16be(string $string): bool {}
function simdutf_validate_utf32(string $string): bool {}

// validation with errors
function simdutf_validate_utf8_with_errors(string $string): bool {}
function simdutf_validate_ascii_with_errors(string $string): bool {}
function simdutf_validate_utf16_with_errors(string $string): bool {}
function simdutf_validate_utf16le_with_errors(string $string): bool {}
function simdutf_validate_utf16be_with_errors(string $string): bool {}
function simdutf_validate_utf32_with_errors(string $string): bool {}

// base64
function simdutf_binary_to_base64(string $string): string {}
function simdutf_base64_to_binary(string $string): string {}


// count
function simdutf_count_utf8(string $string): int {}
function simdutf_count_utf16(string $string): int {}
function simdutf_count_utf16le(string $string): int {}
function simdutf_count_utf16be(string $string): int {}


// convert latin1
function simdutf_convert_latin1_to_utf8(string $string): string {}
function simdutf_convert_latin1_to_utf16le(string $string): string {}
function simdutf_convert_latin1_to_utf16be(string $string): string {}
function simdutf_convert_latin1_to_utf32(string $string): string {}


// convert utf8
function simdutf_convert_utf8_to_latin1(string $string): string {}
function simdutf_convert_utf8_to_utf16(string $string): string {}
function simdutf_convert_utf8_to_utf16le(string $string): string {}
function simdutf_convert_utf8_to_utf16be(string $string): string {}
function simdutf_convert_utf8_to_utf32(string $string): string {}


// convert utf8 with errors
function simdutf_convert_utf8_to_latin1_with_errors(string $string): string {}
function simdutf_convert_utf8_to_utf16_with_errors(string $string): string {}
function simdutf_convert_utf8_to_utf16le_with_errors(string $string): string {}
function simdutf_convert_utf8_to_utf16be_with_errors(string $string): string {}
function simdutf_convert_utf8_to_utf32_with_errors(string $string): string {}


// convert valid utf8
function simdutf_convert_valid_utf8_to_latin1(string $string): string {}
function simdutf_convert_valid_utf8_to_utf16(string $string): string {}
function simdutf_convert_valid_utf8_to_utf16le(string $string): string {}
function simdutf_convert_valid_utf8_to_utf16be(string $string): string {}
function simdutf_convert_valid_utf8_to_utf32(string $string): string {}


// utf8 length
function simdutf_utf8_length_from_utf16(string $string): int {}
function simdutf_utf8_length_from_utf16le(string $string): int {}
function simdutf_utf8_length_from_utf16be(string $string): int {}
function simdutf_utf8_length_from_utf32(string $string): int {}
function simdutf_utf8_length_from_latin1(string $string): int {}

// latin1 length
function simdutf_latin1_length_from_utf8(string $string): int {}
function simdutf_latin1_length_from_utf16(string $string): int {}
function simdutf_latin1_length_from_utf32(string $string): int {}

// uft16 length
function simdutf_utf16_length_from_utf8(string $string): int {}
function simdutf_utf16_length_from_utf32(string $string): int {}
function simdutf_utf16_length_from_latin1(string $string): int {}

// utf32 length
function simdutf_utf32_length_from_utf8(string $string): int {}
function simdutf_utf32_length_from_utf16(string $string): int {}
function simdutf_utf32_length_from_utf16le(string $string): int {}
function simdutf_utf32_length_from_utf16be(string $string): int {}
