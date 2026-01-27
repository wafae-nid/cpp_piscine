/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Weapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:53:09 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/26 16:12:15 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string str)
{
    type = str;
}
const std::string& Weapon::getType()const
{
    return(type);
}
void Weapon::setType(std::string str)
{
    type = str;
}
