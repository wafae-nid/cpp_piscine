
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
  (void)copy;
  // name  is const you cant change it but its okay if its in initialization list 
   
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
  (void)copy;
  return(*this);
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const std::string& literal)
{
  convert_pseuso_literals(literal);
}


