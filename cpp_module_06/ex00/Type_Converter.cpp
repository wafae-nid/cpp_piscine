#include "helpers.hpp"

void convert_pseuso_literals(const std::string& literal)
{

  std::cout<< "char: impossible \n";
  std::cout<< "int: impossible \n";
  if(literal == "nan" || literal == "inf" || literal == "+inf" || literal == "-inf" )
  {
    std::cout<< "float: " << literal << "f\n";
    std::cout<< "double: " << literal << "\n";
  }
  else if (literal == "nanf" || literal == "+inff" || literal == "-inff" || literal == "inff")
  {
    std::cout<< "float: " << literal << "\n";
    std::cout << "double: " << literal.substr(0, literal.size() - 1) << "\n";
  }

}

void convert_number(double d)
{

  if (std::isnan(d) || std::isinf(d))
  {
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: " << static_cast<float>(d) << "f\n";
    std::cout << "double: " << d << "\n";
        return;
  }

  bool has_no_frac = false;

  has_no_frac = (std::floor(d) == d);
    
  std::cout << "char: ";
  if (d < 0 || d > 127 )
    std::cout << "impossible\n";
  
  else
  {
    char c = static_cast<char>(d) ;
    if(!std::isprint(static_cast<unsigned char>(c)))
      std::cout << "Non displayable\n";
    else
      std::cout << "'" << c << "'\n";
  }

  std::cout << "int: ";
  if(d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
    std::cout << "impossible\n";
  else
    std::cout << static_cast<int>(d) << "\n";  
   
  std::cout << "float: "<< static_cast<float>(d) ;
  if(has_no_frac && (!std::isinf(static_cast<float>(d))))
    std::cout<< ".0f\n";
  else
    std::cout<< "f\n";

  std::cout << "double: "<< d ;
  if(has_no_frac)
    std::cout << ".0\n";
  else
    std::cout << "\n";
       
}

void convert_char(const std::string& literal)
{

    char c = literal[0];

    std::cout << "char: ";
    if (c < 32 || c > 126)
      std::cout << "Non displayable\n";
    else
      std::cout << "'" << c << "' \n";
    
    std::cout << "int: ";
    std::cout << static_cast<int>(c) << "\n";  
    
    std::cout << "float: "<< static_cast<float>(c) ;
    std::cout<< ".0f\n";
    
    std::cout << "double: "<< static_cast<double>(c) ;
    std::cout << ".0\n";

}