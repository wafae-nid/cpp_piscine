/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:05:18 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/25 20:53:27 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *zombie;
    zombie = new Zombie[N];
    
    // for(int i = 0; i < N; i++) this could work but u initialize but u r making a stack objet temporaray for each and copy it here extra shit
    // {
    //     zombie[i] = Zombie(name);
    // }
    // return(zombie);
    for(int i = 0; i < N; i++)
    { 
        zombie[i].name_setter(name);
    }
    return(zombie);
}
