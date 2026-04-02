#include "ScalarConverter.hpp"

int main(int argc , char **argv)
{
  std::string literal;

  if(argc != 2)
  {
    std::cout << "ERROR! invalid number of arguments\n";
    exit(1);
  }
  literal = argv[1];
  ScalarConverter::convert(literal);
}