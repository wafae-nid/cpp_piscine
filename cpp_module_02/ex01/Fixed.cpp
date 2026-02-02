/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:53:29 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/02/02 15:39:36 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
   std::cout << "Default constructor called \n";
   RawBits = 0;
}
Fixed::Fixed(const Fixed& copy)
{
   std::cout << "Copy constructor called \n";
   RawBits = copy.RawBits;
}
Fixed& Fixed::operator=(const Fixed& copy)
{
   std::cout << "Copy assignment operator called \n";
   if(this != &copy)
   {
      RawBits = copy.RawBits;
   }
   return(*this);  
}
Fixed::Fixed(const int nbr)
{
   std::cout << "Int constructor called \n";
   if(nbr > (INT_MAX >> frac_bits))
      RawBits = INT_MAX;
   else if(nbr < (INT_MIN >> frac_bits))
      RawBits = INT_MIN;
   else
      RawBits = nbr << frac_bits;
}
Fixed::Fixed(const float nbr)
{
   std::cout << "Float constructor called \n";
   if(static_cast<int>(roundf(nbr*(1 << frac_bits)))> INT_MAX)
      RawBits = INT_MAX;
   else if(static_cast<int>(roundf(nbr*(1 << frac_bits)))< INT_MIN)
      RawBits = INT_MIN;
   else
   RawBits = static_cast<int>(roundf(nbr*(1 << frac_bits)));
}

void Fixed::setRawBits(int const raw)
{
   std::cout << "setRawBits member function called \n";
   RawBits= raw;
}

int Fixed::getRawBits(void)const
{
   std::cout << "getRawBits member function called \n";
   return(RawBits);
}
float Fixed::toFloat( void ) const
{
   return(static_cast<float>(RawBits)/(1 << 8));
}
int Fixed::toInt( void ) const
{
   return(RawBits>> 8);
}
std::ostream& operator<<(std::ostream& os,const Fixed& copy)
{
  os << copy.toFloat();
  return(os);
}
Fixed::~Fixed(){
   
   std::cout<<"Destructor called \n";
}
