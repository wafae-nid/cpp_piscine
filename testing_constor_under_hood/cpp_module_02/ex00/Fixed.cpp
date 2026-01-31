/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:53:29 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/31 17:53:19 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::frac_bits = 0;

Fixed::Fixed()
{
   frac_bits++;
   std::cout<< frac_bits << "object made \n"; 
   RawBits = 0;
}
Fixed::Fixed(const Fixed& copy)
{
   frac_bits++;
   std::cout<< frac_bits << "object made \n"; 
   RawBits = copy.RawBits;
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
   
   std::cout<< frac_bits <<"object destroyed \n";
}
