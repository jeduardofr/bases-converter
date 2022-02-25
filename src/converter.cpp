#include <cmath>
#include <converter/converter.h>
#include <converter/validator.h>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

namespace converter {

uint32_t to_base_10(const char* input, uint32_t base) {
  if (base == 10) {
    return std::stoi(input);
  }

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
  std::vector<char> chars;

  while (as_decimal != 0) {
    uint32_t residue = as_decimal % final_base;
    chars.push_back(value_to_char[residue]);

    as_decimal /= final_base;
  }

  auto size = chars.size();
  char* result_as_string = new char[size + 1];

  int k = 0;
  for (std::vector<char>::reverse_iterator c = chars.rbegin();
       c != chars.rend(); ++c, ++k) {
    result_as_string[k] = *c;
  }
  result_as_string[size] = '\0';

  return result_as_string;
}

}  // namespace converter
