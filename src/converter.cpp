#include <cstring>
#include <string>
#include <cmath>
#include <converter/converter.h>
#include <converter/validator.h>

namespace converter {

uint32_t to_base_10(const char *input, uint32_t base) {
  if (base == 10) {
    return std::stoi(input);
  }

  uint32_t result = 0;
  auto size = strlen(input);
  for (int i = 0, power = size - 1; i < size; ++i, --power) {
    auto value = base_map[input[i]];

    result += (value * pow(base, power));
  }

  return result;
}

char* convert(const char *input, uint32_t initial_base, uint32_t final_base) {
  char* result = new char[10];
  return result;
}

}

