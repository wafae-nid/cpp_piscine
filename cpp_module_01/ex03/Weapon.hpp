/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:46:01 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/26 16:04:31 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
    private:
        std::string type;
    public:
       Weapon(std::string str);
       const std::string& getType()const;
       void setType(std::string str);  
};

#endif