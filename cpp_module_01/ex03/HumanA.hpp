/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    HumanA.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:58:06 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/26 15:59:55 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon& weapon;
    public:
        HumanA(std::string name, Weapon& weapon);
        void attack();
};

#endif