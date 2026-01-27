/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:32:00 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/27 22:17:01 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug()
{
    std::cout << "I love having extra bacon for my \
7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n"; 
}

void Harl::info()
{
   std::cout << "I cannot believe adding extra bacon costs more money. You didn't put \
enough bacon in my burger! If you did, I wouldn't be asking for more!\n" ;
}

void Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for \
years, whereas you started working here just last month.\n";
}

void Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}
void Harl::complain(std::string level)
{
    int i = 0;
    
    void(Harl::*ptr[])()={
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
    };
    
    std::string str[] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR",
    };
    while(str[i].compare(level))
        i++;
    (this->*ptr[i])();
}