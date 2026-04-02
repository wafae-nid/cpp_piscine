#include "helpers.hpp"

bool is_all_digit(const std::string& literal)
{
  size_t i = 0;
  while(i< literal.length())
  {
    if(!(std::isdigit(static_cast<unsigned char>(literal[i])))) // to prevent giving isdigit negative values
      return(false);
    i++;
  }
  return(true);
}

bool is_int(const std::string& literal)
{
  size_t i = 0;
  if(literal.empty())
    return(false);
  if(literal[i] == '-' || literal[i] == '+' )
  {
    if(literal.length() == 1)
      return(false);
    i++;
  }
  return(is_all_digit((literal.substr(i))));
}

bool is_double(const std::string& literal)
{
  std::string nbr;
  std::string frac_part;
  std::string int_part;
  size_t pos;

  if(literal.empty())
    return(false);
  if((literal[0]== '+') || (literal[0]== '-'))
    nbr = literal.substr(1);
  else
    nbr = literal;
  pos = nbr.find('.');
  if(pos==std::string::npos)
    return(false);
  int_part = nbr.substr(0,pos);
  frac_part = nbr.substr(pos+1);   
  if((int_part.empty()) && (frac_part.empty()))
      return(false);
  if((!int_part.empty())&&(!is_all_digit(int_part)))
    return(false);
  if((!frac_part.empty())&&(!is_all_digit(frac_part)))
    return(false);
  return(true);
}

bool is_float(const std::string& literal)
{
  std::string double_part;
    if (literal.empty())
      return(false);
    if (literal[literal.length() - 1] != 'f')
      return(false);
    double_part = literal.substr(0, literal.length() - 1);
    return(is_double(double_part));
}

bool is_pseudo_literals(const std::string& literal)
{
  return(literal == "nan" ||literal == "inf" ||literal == "+inf" ||
        literal == "-inf" ||literal == "nanf" ||literal == "inff" ||
        literal == "+inff" ||literal == "-inff");
}

bool is_char(const std::string& literal)
{
  return (literal.length() == 1 && !std::isdigit(literal[0]));
}
