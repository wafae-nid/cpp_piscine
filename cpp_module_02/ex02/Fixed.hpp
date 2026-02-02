/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:53:43 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/02/02 01:09:58 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP


#include <iostream>
#include <cmath>
#include <climits>

class Fixed
{
    private:
        int RawBits;
        static const int frac_bits = 8;
    public:
        Fixed();
        Fixed(const Fixed& copy);
        Fixed(const int nbr);
        Fixed(const float number);
        ~Fixed();
        Fixed& operator=(const Fixed& copy);
        bool operator>(const Fixed& copy)const;
        bool operator<(const Fixed& copy)const;
        bool operator<=(const Fixed& copy)const;
        bool operator>=(const Fixed& copy)const;
        bool operator==(const Fixed& copy)const;
        bool operator!=(const Fixed& copy)const;
        Fixed operator+(const Fixed& copy)const;
        Fixed operator-(const Fixed& copy)const;
        Fixed operator*(const Fixed& copy)const;
        Fixed operator/(const Fixed& copy)const;
        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
        float toFloat( void ) const;
        int toInt( void ) const;
        void setRawBits(int const raw);
        int getRawBits(void)const;
        
};
std::ostream& operator<<(std::ostream& os,const Fixed& copy);

#endif