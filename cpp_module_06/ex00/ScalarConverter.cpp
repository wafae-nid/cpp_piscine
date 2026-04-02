
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
  if(is_pseudo_literals(literal))
   convert_pseuso_literals(literal);
  else if(is_int(literal))
   convert_int(literal);
  else if(is_double(literal))
   convert_double(literal);
   

}


