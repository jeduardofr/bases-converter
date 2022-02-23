#include <iostream>
#include <json-parser/lex.h>

int main(int argc, char **argv) {
  json_parser::lexer lexer = json_parser::lexer("hello");
  std::cout << &lexer << std::endl;

  return 0;
}
