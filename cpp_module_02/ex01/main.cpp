/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:13:12 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/02/02 15:37:45 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// int main()
// {
//     Fixed fixed;
//     Fixed fixed_2 = Fixed(25245);
//     std::cout << fixed_2.getRawBits() << "\n";
//     std::cout << "[" << fixed_2.toInt() << "]"<< "\n";
//     Fixed fixed_3 = Fixed(25.6666f);
//     std::cout << "***********" << "\n";
//     std::cout << fixed_3 << "\n";
//     std::cout << "***********" << "\n";
//     std::cout << fixed_3.toFloat()<< "\n";
//     std::cout << fixed_3.getRawBits() << "\n";
// }

int main( void ) {
Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );
a = Fixed( 1234.4321f );
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
return 0;
}