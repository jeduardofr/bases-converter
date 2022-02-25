#include <cstdint>
#include <unordered_map>

#ifndef CONVERTER_VALIDATOR_H
#define CONVERTER_VALIDATOR_H

namespace converter {

static std::unordered_map<char, uint32_t> char_to_value = {
    {'0', 0},  {'1', 1},  {'2', 2},  {'3', 3},  {'4', 4},  {'5', 5},  {'6', 6},
    {'7', 7},  {'8', 8},  {'9', 9},  {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13},
    {'E', 14}, {'F', 15}, {'G', 16}, {'H', 17}, {'I', 18}, {'J', 19}, {'K', 20},
    {'L', 21}, {'M', 22}, {'N', 23}, {'O', 24}, {'P', 25}, {'Q', 26}, {'R', 27},
    {'S', 28}, {'T', 29}, {'U', 30}, {'V', 31},
};

static std::unordered_map<uint32_t, char> value_to_char = {
    {0,  '0'}, {1,  '1'}, {2,  '2'}, {3,  '3'}, {4,  '4'}, {5,  '5'}, {6,  '6'},
    {7,  '7'}, {8,  '8'}, {9,  '9'}, {10, 'A'}, {11, 'B'}, {12, 'C'}, {13, 'D'},
    {14, 'E'}, {15, 'F'}, {16, 'G'}, {17, 'H'}, {18, 'I'}, {19, 'J'}, {20, 'K'},
    {21, 'L'}, {22, 'M'}, {23, 'N'}, {24, 'O'}, {25, 'P'}, {26, 'Q'}, {27, 'R'},
    {28, 'S'}, {29, 'T'}, {30, 'U'}, {31, 'V'},
};

bool validate_string(const char *, uint32_t);

}  // namespace converter

#endif  // CONVERTER_VALIDATOR_H
