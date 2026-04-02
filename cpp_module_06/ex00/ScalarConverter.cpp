
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
  else if(is_double(literal)|| is_float(literal))
   convert_double_float(literal);
  else if(is_char(literal))
    convert_char(literal);
  else
  {
    std::cout << "The data type is invalid for conversion \n"<< "Types you can convert are: \n";
    std::cout << "1- char\n"<< "2- int\n"<< "3- double\n"<< "4- float\n"<< "5- pseudo_literals\n" ;
  }

}


