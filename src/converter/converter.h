#include <cstdint>
#include <unordered_map>

#ifndef CONVERTER_CONVERTER_H
#define CONVERTER_CONVERTER_H

namespace converter {

uint32_t to_base_10(const char*, uint32_t);
char* convert(const char*, uint32_t, uint32_t);

}  // namespace converter

#endif  // CONVERTER_VALIDATOR_H

