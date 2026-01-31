/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:53:29 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/31 18:45:57 by wnid-hsa         ###   ########.fr       */
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
void Fixed::setRawBits(int const raw)
{
   RawBits= raw;
}
int Fixed::getRawBits(void)const
{
   return(RawBits);
}
Fixed& Fixed::operator=(const Fixed& copy)
{
   if(this != &copy)
   {
      RawBits = copy.RawBits;
   }
   return(*this);  
}
Fixed::~Fixed(){
   
   std::cout<<"object destroyed \n";
}
