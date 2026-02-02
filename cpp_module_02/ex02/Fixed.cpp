/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:53:29 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/02/02 01:10:57 by wnid-hsa         ###   ########.fr       */
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
   return(static_cast<float>(RawBits)/(1 << 8));
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
bool Fixed::operator>(const Fixed& copy)const
{
   return(this->RawBits > copy.RawBits);
}
bool Fixed::operator<(const Fixed& copy)const
{
   return(this->RawBits < copy.RawBits);
}
bool Fixed::operator<=(const Fixed& copy)const
{
   return(this->RawBits <= copy.RawBits);
}
bool Fixed::operator>=(const Fixed& copy)const
{
   return(this->RawBits >= copy.RawBits);
}
bool Fixed::operator==(const Fixed& copy)const
{
   return(this->RawBits == copy.RawBits);
}
bool Fixed::operator!=(const Fixed& copy)const
{
   return(this->RawBits != copy.RawBits);
}
Fixed Fixed::operator+(const Fixed& copy) const// HERE WE CANT RETURN A REFERENCE AS THIS VALUE WILL NOT BE AVAILABLE AFTER THIS {} SO RETURNING IT AS REF WILL GIVE  AREF TO A NON VALID OBJECT
{
   Fixed fixed;
   int   res;
   res = this->RawBits + copy.RawBits;
   fixed.setRawBits(res);
   return(fixed); 
}
Fixed Fixed::operator-(const Fixed& copy)const // HERE WE CANT RETURN A REFERENCE AS THIS VALUE WILL NOT BE AVAILABLE AFTER THIS {} SO RETURNING IT AS REF WILL GIVE  AREF TO A NON VALID OBJECT
{
   Fixed fixed;
   int   res;
   res = this->RawBits - copy.RawBits;
   fixed.setRawBits(res);
   return(fixed); 
}
Fixed Fixed::operator*(const Fixed& copy)const// i promise to not modify this;
{
   Fixed fixed;
   long long   res;
   res = ((((long long)this->RawBits)*((long long)copy.RawBits))>>8);// int *int will be stored as int before being passed to the long so this wont prevent overflow 
   if (res > INT_MAX)
       res = INT_MAX;
   if (res < INT_MIN) 
      res = INT_MIN;
   fixed.setRawBits((int)res);
   return(fixed); 
}
Fixed Fixed::operator/(const Fixed& copy)const
{
   Fixed fixed;
   long long   res;
   if (copy.RawBits == 0)
   {
      fixed.setRawBits(0);
      return fixed;
   }
   res = (((long long)this->RawBits)<< 8 )/(long long)copy.RawBits;
   if (res > INT_MAX)
       res = INT_MAX;
   if (res < INT_MIN) 
      res = INT_MIN;
   fixed.setRawBits((int)res);
   return(fixed); 
}
Fixed& Fixed::operator++()
{
   long long   res;
   
   res = this->RawBits + 1;
   if (res > INT_MAX)
       res = INT_MAX;
   if (res < INT_MIN) 
      res = INT_MIN;
   this->setRawBits((int)res);
   return(*this); 
}
Fixed Fixed::operator++(int) //search why this temp copy lifetime is extented because it is bent to const ref
{
   Fixed old_this = *this;
   long long   res;
   res = this->RawBits + 1;
   this->setRawBits((int)res);
   return(old_this);
}
Fixed& Fixed::operator--() 
{ 
   long long   res;
   
   res = this->RawBits - 1;
   if (res > INT_MAX)
       res = INT_MAX;
   if (res < INT_MIN) 
      res = INT_MIN;
   this->setRawBits((int)res);
   return(*this); 
  
}

Fixed Fixed::operator--(int) 
{
   Fixed old_this = *this;
   long long   res;
   res = this->RawBits -1;
   this->setRawBits((int)res);
   return(old_this);
}

std::ostream& operator<<(std::ostream& os,const Fixed& copy)
{
  os << copy.toFloat();
  return(os);
}
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
   if(a<=b)
      return(a);
   return(b);
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
   if(a<=b)
      return(a);
   return(b);
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
   if(a>=b)
      return(a);
   return(b);
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
   if(a>=b)
      return(a);
   return(b);
}
Fixed::~Fixed(){
   
   std::cout<<"object destroyed \n";
}
