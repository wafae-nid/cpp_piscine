
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
  {
    convert_pseuso_literals(literal);
    return;
  }
  else if(is_char(literal))
  {
    convert_char(literal);
    return;
  }

  char *end;
  double d = strtod(literal.c_str(), &end);
  if(end == literal.c_str())
  {
    std::cout << "The data type is invalid for conversion \n"<< "Types you can convert are: \n";
    std::cout << "1- char\n"<< "2- int\n"<< "3- double\n"<< "4- float\n"<< "5- pseudo_literals\n" ;
      return;
  }
  if ((*end == 'f' || *end == 'F') && *(end + 1) == '\0')
  {
    convert_number(d);
    return;
  }
  if (*end != '\0')
  {
    std::cout << "The data type is invalid for conversion \n" << "Types you can convert are: \n";
    std::cout << "1- char\n" << "2- int\n" << "3- double\n" << "4- float\n" << "5- pseudo_literals\n";
    return;
  }
  else
    convert_number(d);
}


