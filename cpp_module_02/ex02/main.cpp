/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:13:12 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/02/02 13:00:38 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


#include <iostream>
#include "Fixed.hpp"

int main()
{
    // long a_ = 4;
    // long b_ = 3;

    // long c_ = (a_ /b_)<<8;
    // std::cout << c_ << "\n";
    
    // // Create Fixed objects
    // Fixed a(10);       // integer constructor
    // Fixed b(3.5f);     // float constructor
    // Fixed c(-2);       // negative int
    // Fixed d(0.25f);    // small float

    // // Print initial values
    // std::cout << "Initial values:" << std::endl;
    // std::cout << "a = " << a << std::endl;
    // std::cout << "b = " << b << std::endl;
    // std::cout << "c = " << c << std::endl;
    // std::cout << "d = " << d << std::endl << std::endl;

    // // Test arithmetic operators
    // Fixed sum = a + b;
    // Fixed diff = a - c;
    // Fixed prod = b * d;
    // Fixed div = b * d;
    // std::cout << "Arithmetic results:" << std::endl;
    // std::cout << "a + b = " << sum << std::endl;
    // std::cout << "a - c = " << diff << std::endl;
    // std::cout << "b * d = " << prod << std::endl << std::endl;
    // std::cout << "b / d = " << div << std::endl << std::endl;
    // // Test comparison operators
    // std::cout << "Comparisons:" << std::endl;
    // std::cout << "a > b: " << (a > b) << std::endl;
    // std::cout << "a < b: " << (a < b) << std::endl;
    // std::cout << "a >= a: " << (a >= a) << std::endl;
    // std::cout << "b <= d: " << (b <= d) << std::endl;
    // std::cout << "c == d: " << (c == d) << std::endl;
    // std::cout << "c != d: " << (c != d) << std::endl << std::endl;

    // // Test conversion to int and float
    // std::cout << "Conversions:" << std::endl;
    // std::cout << "a.toInt() = " << a.toInt() << std::endl;
    // std::cout << "b.toInt() = " << b.toInt() << std::endl;
    // std::cout << "b.toFloat() = " << b.toFloat() << std::endl;
    // std::cout << "d.toFloat() = " << d.toFloat() << std::endl;
    //  Fixed a, b, res;

    // // Normal division
    // a.setRawBits(256*4); // 4.0
    // b.setRawBits(256*2); // 2.0
    // res = a / b;
    // std::cout << "4 / 2 = " << res.getRawBits() / 256.0f << "\n";

    // // Fraction <1
    // a.setRawBits(256*1); // 1.0
    // b.setRawBits(256*2); // 2.0
    // res = a / b;
    // std::cout << "1 / 2 = " << res.getRawBits() / 256.0f << "\n";

    // // Negative number
    // a.setRawBits(-256*3); // -3.0
    // b.setRawBits(256*2);  // 2.0
    // res = a / b;
    // std::cout << "-3 / 2 = " << res.getRawBits() / 256.0f << "\n";

    // // Division by zero
    // a.setRawBits(256*5); // 5.0
    // b.setRawBits(0);     // 0
    // res = a / b;
    // std::cout << "5 / 0 = " << res.getRawBits() / 256.0f << "\n";

    // // Fractional result
    // a.setRawBits(256*3); // 3.0
    // b.setRawBits(256*4); // 4.0
    // res = a / b;
    // std::cout << "3 / 4 = " << res.getRawBits() / 256.0f << "\n";
    // a.setRawBits(256*5); // 5.0
    // b.setRawBits(0);     // 0
    // a =Fixed(25.255f);
    // b = Fixed(26.255f);
    // std::cout << a << "\n";
    // ++a;
    // res = a.min(a,b);
    // std::cout << res <<  "\n";
    int a___ = 222<<8;
    float b___;
    b___ = (a___>>8);
    std::cout << b___<<"\n";
    
    return 0;
}
