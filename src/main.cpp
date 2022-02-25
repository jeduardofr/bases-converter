#include <converter/converter.h>
#include <converter/validator.h>
#include <iostream>

int main(int argc, char **argv) {
  int option;
  char input[80];
  uint32_t initial_base, final_base;
  bool exit = false;

  do {
    std::cout << "1. Calcular número\n";
    std::cout << "2. Salir\n";

    std::cout << "> ";
    std::cin >> option;

    switch (option) {
      case 1: {
        bool control = false;
        std::cout
            << "Ingresa el valor a convertir en un rango de base de 2 a 30\n";
        std::cout << "> ";
        std::cin >> input;

        std::cout << "Ingresa la base de entrada\n";
        std::cout << "> ";
        std::cin >> initial_base;

        std::cout << "Ingresa la base de salida\n";
        std::cout << "> ";
        std::cin >> final_base;

        if (!converter::validate_string(input, initial_base)) {
          std::cout << "El valor que ingresaste usa caracteres no permitidos "
                       "por la base de entrada seleccionada\n\n";
          break;
        }

        auto result = converter::convert(input, initial_base, final_base);
        std::cout << "El valor " << input << " de base " << initial_base
                  << " a base " << final_base << " es " << result << "\n\n";
        delete result;
      } break;
      case 2:
        exit = true;
        break;
      default:
        std::cout << "Opción inválida\n";
    }
  } while (exit != true);

  return 0;
}
