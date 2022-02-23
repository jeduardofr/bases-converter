#include <gtest/gtest.h>
#include <json-parser/lex.h>

namespace json_parser {

void check_token(const char *input, token_type type);

TEST(text_lex, lex_basic_symbols) {
  check_token("{", token_type::left_curly);
  check_token("}", token_type::right_curly);
  check_token("[", token_type::left_square);
  check_token("]", token_type::right_square);
  check_token(":", token_type::colon);
  check_token(",", token_type::comma);
}

TEST(text_lex, lex_symbols_with_any_amount_of_whitespace) {
  check_token(" { ", token_type::left_curly);
  check_token("     } ", token_type::right_curly);
}

TEST(text_lex, lex_strings) {
  check_token(R"("hello")", token_type::string);
  check_token(R"("hello  world")", token_type::string);
  check_token(R"("Something completely")", token_type::string);
  check_token(R"("_hello_")", token_type::string);
}

TEST(text_lex, lex_string_with_reverse_solidus) {
  check_token(R"("hello \"world\" ")", token_type::string);
  check_token(R"("reverse \\ escaping \"")", token_type::string);
  check_token(R"("reverse \\\" escaping \"")", token_type::string);
}

void check_token(const char *input, token_type type) {
  auto lexer = json_parser::lexer(input);
  EXPECT_EQ(lexer.peek().type, type);
  lexer.skip();
  EXPECT_EQ(lexer.peek().type, token_type::end_of_file);
}
}  // namespace json_parser
