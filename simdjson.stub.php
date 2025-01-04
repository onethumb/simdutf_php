<?php

/**
 * @generate-class-entries
 * @undocumentable
 */

// validation
function simdutf_validate_utf8(string $string): bool {}
function simdutf_validate_utf8_with_errors(string $string): bool {}


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
