#include <cstring>
#include <converter/validator.h>

namespace converter {

bool validate_string(const char *input, uint32_t base) {
  size_t size = strlen(input);

  for (int i = 0; i < size; ++i) {
    auto c = input[i];
    if (auto value = base_map.find(c); value != base_map.end()) {
      if (value->second >= base) {
        return false;
      }
    } else return false;
  }

  return true;
}
}  // namespace converter
