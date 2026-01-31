/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:13:12 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/02/01 00:03:36 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
    Fixed fixed;
    Fixed fixed_2 = Fixed(25245);
    std::cout << fixed_2.getRawBits() << "\n";
    std::cout << "[" << fixed_2.toInt() << "]"<< "\n";
    Fixed fixed_3 = Fixed(25.6666f);
    std::cout << fixed_3.toFloat()<< "\n";
    std::cout << fixed_3.getRawBits() << "\n";
}

