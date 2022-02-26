#include <cmath>
#include <converter/converter.h>
#include <converter/validator.h>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

namespace converter {

uint32_t to_base_10(const char* input, uint32_t base) {
  uint32_t result = 0;
  auto size = strlen(input);
  for (int i = 0, power = size - 1; i < size; ++i, --power) {
    auto value = char_to_value[input[i]];

    result += (value * pow(base, power));
  }

  return result;
}

char* convert(const char* input, uint32_t initial_base, uint32_t final_base) {
  auto as_decimal = to_base_10(input, initial_base);
  std::string str = "";

  while (as_decimal != 0) {
    uint32_t residue = as_decimal % final_base;
    str = value_to_char[residue] + str;

    as_decimal /= final_base;
  }

  char* result = new char[str.size() + 1];
  std::copy(str.begin(), str.end(), result);
  result[str.size()] = '\0';
  return result;
}

}  // namespace converter
