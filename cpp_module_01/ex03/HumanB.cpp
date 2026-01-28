/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:42:19 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/28 14:18:03 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string str)
{
    name = str;
     weapon = NULL; 
}
void HumanB::attack()
{
    if(weapon)
        std::cout << name << " attacks with their " << weapon->getType() << "\n";
    else
       std::cout << name << " has no weapon \n"; 
}
void HumanB::setWeapon(Weapon& weapon_)
{
    weapon = &weapon_;
}