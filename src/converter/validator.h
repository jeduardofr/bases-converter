#include <cstdint>
#include <unordered_map>

#ifndef CONVERTER_VALIDATOR_H
#define CONVERTER_VALIDATOR_H

namespace converter {

static std::unordered_map<char, uint32_t> base_map = {
  {'0', 0},
  {'1', 1},
  {'2', 2},
  {'3', 3},
  {'4', 4},
  {'5', 5},
  {'6', 6},
  {'7', 7},
  {'8', 8},
  {'9', 9},
  {'A', 10},
  {'B', 11},
  {'C', 12},
  {'D', 13},
  {'E', 14},
  {'F', 15},
  {'G', 16},
  {'H', 17},
  {'I', 18},
  {'J', 19},
  {'K', 20},
  {'L', 21},
  {'M', 22},
  {'N', 23},
  {'O', 24},
  {'P', 25},
  {'Q', 26},
  {'R', 27},
  {'S', 28},
  {'T', 29},
  {'U', 30},
  {'V', 31},
};

bool validate_string(const char *, uint32_t);

}  // namespace converter

#endif  // CONVERTER_VALIDATOR_H
