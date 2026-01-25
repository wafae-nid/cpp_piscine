/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:18:18 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/25 17:16:09 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
class Zombie
{
    private:
        std::string name;
    public:
        void announce(void);
        Zombie(std::string zombie_name);
        ~Zombie();   
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif