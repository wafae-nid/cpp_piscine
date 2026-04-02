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

void convert_int(const std::string& literal)
{
    char *end;

    double d = strtod(literal.c_str(), &end);

    if(d > INT_MAX || d < INT_MIN)
    {
        std::cout<< "ERROR ! \n" << "This literal overflows as int try an other string literal\n";
        return;
    }
    std::cout << "char: ";
    if (static_cast<char>(d) < 32 || static_cast<char>(d)> 126)
      std::cout << "Non displayable\n";
    else
      std::cout << "'" << static_cast<char>(d) << "' \n";
    std::cout << "int: "<< static_cast<int>(d) << "\n";
    std::cout << "float: "<< static_cast<float>(d) << ".0f\n";
    std::cout << "double: "<< d << ".0\n";

}

void convert_double_float(const std::string& literal)
{
    char *end;

    double d = strtod(literal.c_str(), &end);
    int flag = 0;

    if (d == static_cast<int>(d))
        flag = 1;
    
    std::cout << "char: ";
    if (d < 0 || d > 127)
        std::cout << "impossible\n";
    else if (static_cast<char>(d) < 32 || static_cast<char>(d)> 126)
      std::cout << "Non displayable\n";
    else
      std::cout << "'" << static_cast<char>(d) << "' \n";
    
    std::cout << "int: ";
    if(d > INT_MAX || d < INT_MIN)
       std::cout << "impossible\n";
    else
     std::cout << static_cast<int>(d) << "\n";  
    
    std::cout << "float: "<< static_cast<float>(d) ;
    if(flag)
        std::cout<< ".0f\n";
    else
        std::cout<< "f\n";
    
    std::cout << "double: "<< d ;
    if(flag)
       std::cout << ".0\n";
    else
       std::cout << "\n";
       
}