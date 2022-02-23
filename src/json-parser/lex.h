#ifndef JSON_PARSER_LEX_H
#define JSON_PARSER_LEX_H

namespace json_parser {

enum class token_type {
  // Basic Symbols
  colon = ':',
  comma = ',',
  left_curly = '{',
  right_curly = '}',
  left_square = '[',
  right_square = ']',
  quotation_mark = '"',

  end_of_file,

  // Types
  string,
};

struct token {
  token_type type;
};

// Documents for reference: 
// - https://www.rfc-editor.org/rfc/pdfrfc/rfc2119.txt.pdf (MUST, MUST NOT, etc.)
// - https://www.rfc-editor.org/rfc/pdfrfc/rfc5234.txt.pdf (ABNF)
// - https://www.rfc-editor.org/rfc/pdfrfc/rfc4627.txt.pdf (JSON - old)
// - https://www.rfc-editor.org/rfc/pdfrfc/rfc7159.txt.pdf (JSON - updated)
class lexer {
 public:
  lexer(const char *input) : input_(input) {
    this->skip_whitespace();
    this->parse_next_token();
  }

  void parse_next_token();
  const token &peek() { return this->current_token_; }
  void skip() { this->parse_next_token(); }
  void skip_whitespace();
  void parse_string();

 private:
  const char *input_;
  token current_token_;
};
}  // namespace json_parser

#endif  // JSON_PARSER_LEX_H
