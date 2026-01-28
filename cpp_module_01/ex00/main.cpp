/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:06:57 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/28 12:54:10 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *zombie;
    
    std::cout<< "******heap*******\n";
    {
        zombie = newZombie("wafae");
        zombie->announce();
        delete(zombie);
    }
    {
        zombie = newZombie("wnid-hsa");
        zombie->announce();
        delete(zombie);
    }
    {
        zombie = newZombie("42 student");
        zombie->announce();
        delete(zombie);
    }
    std::cout<< "******stack*******\n";
    {
        randomChump("polite zombie");
        randomChump("zombieee");
    }
    {
        randomChump("random_zombie");   
    }
}