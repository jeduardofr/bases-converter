#include <json-parser/lex.h>

namespace json_parser {

void lexer::parse_next_token() {
  switch (this->input_[0]) {
    case '\0':
      this->current_token_.type = token_type::end_of_file;
      break;

    case ':':
    case ',':
    case '{':
    case '[':
    case '}':
    case ']':
      this->current_token_.type = static_cast<token_type>(*this->input_);
      this->input_ += 1;
      break;

    case '"':
      this->parse_string();
      break;
  }

  this->skip_whitespace();
}

void lexer::parse_string() {
  this->current_token_.type = token_type::string;
  this->input_ += 1;

  while (*this->input_ != '"' || *(this->input_ - 1) == '\\') this->input_ += 1;

  this->input_ += 1;
}

void lexer::skip_whitespace() {
  while (*this->input_ == ' ') this->input_ += 1;
}

}  // namespace json_parser
