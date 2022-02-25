#include <converter/validator.h>
#include <cstring>

namespace converter {

bool validate_string(const char *input, uint32_t base) {
  size_t size = strlen(input);

  for (int i = 0; i < size; ++i) {
    auto c = input[i];
    if (auto value = char_to_value.find(c); value != char_to_value.end()) {
      if (value->second >= base) {
        return false;
      }
    } else
      return false;
  }

  return true;
}
}  // namespace converter
