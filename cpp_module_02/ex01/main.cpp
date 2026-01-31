/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:13:12 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/31 17:53:58 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
    Fixed fixed;
    fixed.setRawBits(48);
    Fixed fixed_2 = Fixed(fixed);
    
    std::cout << fixed_2.getRawBits() << "\n";
}