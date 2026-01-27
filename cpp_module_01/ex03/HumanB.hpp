/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:43:00 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/26 19:09:17 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
class HumanB
{
    private:
        std::string name;
        Weapon* weapon;
    public:
        HumanB(std::string str);
        void setWeapon(Weapon& weapon_);
        void attack();
};

#endif