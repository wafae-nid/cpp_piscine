#include "helpers.hpp"

void convert_pseuso_literals(const std::string& literal)
{
  char *end;
  double d = strtod(literal.c_str(), &end);
  int flag = 0;

  std::cout<< "char: impossible \n";
  std::cout<< "int: impossible \n";
  if(literal[0] == '+')
    flag = 1;

  std::cout<< "float: ";
  if(flag)
    std::cout<< literal[0];
  std::cout << static_cast<float>(d) << "f\n";

  std::cout<< "double: ";
  if(flag)
    std::cout<< literal[0];
  std::cout << d << "\n";
}