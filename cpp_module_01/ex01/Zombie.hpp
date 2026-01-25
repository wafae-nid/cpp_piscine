/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:06:00 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/25 20:52:05 by wnid-hsa         ###   ########.fr       */
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
        Zombie();
        // Zombie(std::string zombie_name);
        void name_setter(std::string name);
        ~Zombie();   
};

Zombie* zombieHorde(int N, std::string name);

#endif