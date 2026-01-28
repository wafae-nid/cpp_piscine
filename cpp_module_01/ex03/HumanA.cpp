/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:34:48 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/28 14:26:17 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name_, const Weapon& weapon_): name(name_),weapon(weapon_){};

void HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << "\n";
}