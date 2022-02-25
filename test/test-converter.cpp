#include <cstdio>
#include <converter/converter.h>
#include <gtest/gtest.h>

namespace converter {

void check_convertion(const char *input, uint32_t initial_base, uint32_t final_base, const char* output);
void check_decimal_convertion(const char *input, uint32_t base, uint32_t result);

TEST(test_converter, any_base_to_base_10) {
  check_decimal_convertion("10110", 2, 22);
  check_decimal_convertion("1220111", 3, 1390);
  check_decimal_convertion("2033300", 4, 9200);
  check_decimal_convertion("10340", 5, 720);
  check_decimal_convertion("114144", 6, 10000);
  check_decimal_convertion("1023", 7, 360);
  check_decimal_convertion("07123", 8, 3667);
  check_decimal_convertion("01", 10, 1);
  check_decimal_convertion("8CA", 14, 1746);
  check_decimal_convertion("1572", 16, 5490);
  check_decimal_convertion("4FC9", 27, 90000);
  check_decimal_convertion("2U", 31, 92);
  check_decimal_convertion("2V", 32, 95);
}

TEST(test_converter, base_2_to_base_10) {
  // check_convertion("1F8A", 16, 10, "8074");
  check_convertion("185623", 10, 2, "101101010100010111");
}

void check_convertion(const char *input, uint32_t initial_base, uint32_t final_base, const char* output) {
  char* result  = converter::convert(input, initial_base, final_base);
  EXPECT_STREQ(result, output);
  delete result;
}

void check_decimal_convertion(const char *input, uint32_t base, uint32_t result) {
  auto n = converter::to_base_10(input, base);
  EXPECT_EQ(n, result);
}

}  // namespace converter
