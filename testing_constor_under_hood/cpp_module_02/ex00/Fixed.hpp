/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:53:43 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/31 17:18:25 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP


#include <iostream>

class Fixed
{
    private:
        int RawBits;
        // static const int frac_bits = 8;
         static int frac_bits;
    public:
        Fixed();
        Fixed(const Fixed& copy);
        ~Fixed();
        Fixed& operator=(const Fixed& copy);
        void setRawBits(int const raw);
        int getRawBits(void)const;
           
};

#endif