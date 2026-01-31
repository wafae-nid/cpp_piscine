/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:53:43 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/31 23:55:59 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP


#include <iostream>
#include <cmath>

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
        float toFloat( void ) const;
        int toInt( void ) const;
        void setRawBits(int const raw);
        int getRawBits(void)const;
           
};

#endif