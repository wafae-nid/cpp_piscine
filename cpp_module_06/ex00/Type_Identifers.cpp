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

std::string toLowerStr(std::string s)
{
    for (size_t i = 0; i < s.size(); i++)
        s[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(s[i])));
    return s;
}