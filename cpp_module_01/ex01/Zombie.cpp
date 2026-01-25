/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:06:30 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/25 20:51:54 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << name << ": " << "BraiiiiiiinnnzzzZ...\n";
}
// Zombie::Zombie(std::string zombie_name)
// {
//     name = zombie_name;
// }
void Zombie::name_setter(std::string str)
{
    name = str;
}
Zombie::Zombie()
{
    name = "zombiiiiiiiiiii";
}
Zombie::~Zombie()
{
    std::cout << "zombie " << name << " is dead \n";
}

