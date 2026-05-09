#include "helpers.hpp"


bool is_pseudo_literals(const std::string& literal)
{
  return(literal == "nan" || literal == "inf" || literal == "+inf" ||
        literal == "-inf" ||literal == "nanf" || literal == "inff" ||
        literal == "+inff" ||literal == "-inff");
}

bool is_char(const std::string& literal)
{
  return (literal.length() == 1 && !std::isdigit(literal[0]));
}
