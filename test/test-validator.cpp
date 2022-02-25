#include <converter/validator.h>
#include <gtest/gtest.h>

namespace converter {

void check_string(const char *input, uint32_t base, bool expected);

TEST(test_validator, base2) {
  check_string("01", 2, true);
  check_string("23456789ABCDEFGHIJKLMNOPQRSTUV", 2, false);
}

TEST(test_validator, base3) {
  check_string("012", 3, true);
  check_string("3456789ABCDEFGHIJKLMNOPQRSTUV", 3, false);
}

TEST(test_validator, base4) {
  check_string("0123", 4, true);
  check_string("456789ABCDEFGHIJKLMNOPQRSTUV", 4, false);
}

TEST(test_validator, base5) {
  check_string("01234", 5, true);
  check_string("56789ABCDEFGHIJKLMNOPQRSTUV", 5, false);
}

TEST(test_validator, base6) {
  check_string("012345", 6, true);
  check_string("6789ABCDEFGHIJKLMNOPQRSTUV", 6, false);
}

TEST(test_validator, base7) {
  check_string("0123456", 7, true);
  check_string("789ABCDEFGHIJKLMNOPQRSTUV", 7, false);
}

TEST(test_validator, base8) {
  check_string("01234567", 8, true);
  check_string("89ABCDEFGHIJKLMNOPQRSTUV", 8, false);
}

TEST(test_validator, base9) {
  check_string("012345678", 9, true);
  check_string("9ABCDEFGHIJKLMNOPQRSTUV", 9, false);
}

TEST(test_validator, base10) {
  check_string("0123456789", 10, true);
  check_string("ABCDEFGHIJKLMNOPQRSTUV", 10, false);
}

TEST(test_validator, base11) {
  check_string("0123456789A", 11, true);
  check_string("BCDEFGHIJKLMNOPQRSTUV", 11, false);
}

TEST(test_validator, base12) {
  check_string("0123456789AB", 12, true);
  check_string("CDEFGHIJKLMNOPQRSTUV", 12, false);
}

TEST(test_validator, base13) {
  check_string("0123456789ABC", 13, true);
  check_string("DEFGHIJKLMNOPQRSTUV", 13, false);
}

TEST(test_validator, base14) {
  check_string("0123456789ABCD", 14, true);
  check_string("EFGHIJKLMNOPQRSTUV", 14, false);
}

TEST(test_validator, base15) {
  check_string("0123456789ABCDE", 15, true);
  check_string("FGHIJKLMNOPQRSTUV", 15, false);
}

TEST(test_validator, base16) {
  check_string("0123456789ABCDEF", 16, true);
  check_string("GHIJKLMNOPQRSTUV", 16, false);
}

TEST(test_validator, base17) {
  check_string("0123456789ABCDEFG", 17, true);
  check_string("HIJKLMNOPQRSTUV", 17, false);
}

TEST(test_validator, base18) {
  check_string("0123456789ABCDEFGH", 18, true);
  check_string("IJKLMNOPQRSTUV", 18, false);
}

TEST(test_validator, base19) {
  check_string("0123456789ABCDEFGHI", 19, true);
  check_string("JKLMNOPQRSTUV", 19, false);
}

TEST(test_validator, base20) {
  check_string("0123456789ABCDEFGHIJ", 20, true);
  check_string("KLMNOPQRSTUV", 20, false);
}

TEST(test_validator, base21) {
  check_string("0123456789ABCDEFGHIJK", 21, true);
  check_string("LMNOPQRSTUV", 21, false);
}

TEST(test_validator, base22) {
  check_string("0123456789ABCDEFGHIJKL", 22, true);
  check_string("MNOPQRSTUV", 22, false);
}

TEST(test_validator, base23) {
  check_string("0123456789ABCDEFGHIJKLM", 23, true);
  check_string("NOPQRSTUV", 23, false);
}

TEST(test_validator, base24) {
  check_string("0123456789ABCDEFGHIJKLMN", 24, true);
  check_string("OPQRSTUV", 24, false);
}

TEST(test_validator, base25) {
  check_string("0123456789ABCDEFGHIJKLMNO", 25, true);
  check_string("PQRSTUV", 25, false);
}

TEST(test_validator, base26) {
  check_string("0123456789ABCDEFGHIJKLMNOP", 26, true);
  check_string("QRSTUV", 26, false);
}

TEST(test_validator, base27) {
  check_string("0123456789ABCDEFGHIJKLMNOPQ", 27, true);
  check_string("RSTUV", 27, false);
}

TEST(test_validator, base28) {
  check_string("0123456789ABCDEFGHIJKLMNOPQR", 28, true);
  check_string("STUV", 28, false);
}

TEST(test_validator, base29) {
  check_string("0123456789ABCDEFGHIJKLMNOPQRS", 29, true);
  check_string("TUV", 29, false);
}

TEST(test_validator, base30) {
  check_string("0123456789ABCDEFGHIJKLMNOPQRST", 30, true);
  check_string("UV", 30, false);
}

TEST(test_validator, base31) {
  check_string("0123456789ABCDEFGHIJKLMNOPQRSTU", 31, true);
  check_string("V", 31, false);
}

TEST(test_validator, base32) {
  check_string("0123456789ABCDEFGHIJKLMNOPQRSTUV", 32, true);
  check_string("W", 32, false);
}

void check_string(const char *input, uint32_t base, bool expected) {
  auto res = converter::validate_string(input, base);
  EXPECT_EQ(res, expected);
}
}  // namespace converter
