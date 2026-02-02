/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:53:29 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/02/02 15:35:27 by wnid-hsa         ###   ########.fr       */
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
   // setRawBits(copy.RawBits);
}
Fixed& Fixed::operator=(const Fixed& copy)
{
   std::cout << "Copy assignment operator called \n";
   if(this != &copy)
   {
      RawBits = copy.getRawBits();
      // RawBits = copy.RawBits;
   }
   return(*this);  
}
int Fixed::getRawBits(void)const
{
   std::cout << "getRawBits member function called \n";
   return(RawBits);
}
void Fixed::setRawBits(int const raw)
{
   std::cout << "setRawBits member function called \n";
   RawBits= raw;
}
Fixed::~Fixed(){
   
   std::cout<<"Destructor called \n";
}

