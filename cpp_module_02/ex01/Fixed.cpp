/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:53:29 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/02/01 16:53:39 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
   RawBits = 0;
}
Fixed::Fixed(const Fixed& copy)
{
   RawBits = copy.RawBits;
}
Fixed::Fixed(const int nbr)
{
   RawBits = nbr << frac_bits;
}
Fixed::Fixed(const float nbr)
{
   RawBits = roundf(nbr*(1 << frac_bits));
}
void Fixed::setRawBits(int const raw)
{
   RawBits= raw;
}

int Fixed::getRawBits(void)const
{
   return(RawBits);
}
float Fixed::toFloat( void ) const
{
   return(RawBits/float(1 << 8));
}
int Fixed::toInt( void ) const
{
   return(RawBits>> 8);
}
Fixed& Fixed::operator=(const Fixed& copy)
{
   if(this != &copy)
   {
      RawBits = copy.RawBits;
   }
   return(*this);  
}
std::ostream& operator<<(std::ostream& os,const Fixed& copy)
{
  os << copy.toFloat();
  return(os);
}
Fixed::~Fixed(){
   
   std::cout<<"object destroyed \n";
}
