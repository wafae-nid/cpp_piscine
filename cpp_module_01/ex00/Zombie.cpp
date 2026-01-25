/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:18:32 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/25 17:46:15 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"


void Zombie::announce(void)
{
    std::cout << name << ": " << "BraiiiiiiinnnzzzZ...\n";
}
Zombie::Zombie(std::string zombie_name)
{
    name = zombie_name;
}
Zombie::~Zombie()
{
    std::cout << "zombie " << name << " is dead \n";
}

