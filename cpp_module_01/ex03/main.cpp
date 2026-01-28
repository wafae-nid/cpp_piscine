/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:43:17 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/28 14:23:30 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
   {
      Weapon club = Weapon("crude spiked club");
      HumanA bob("Bob", club);
      bob.attack();
      club.setType("some other type of club");
      bob.attack();
   }
   {
      Weapon club = Weapon("crude spiked club");
      HumanB jim("Jim");
      jim.setWeapon(club);
      jim.attack();
      club.setType("some other type of club");
      jim.attack();
   }

   // {
      // Weapon club = Weapon("crude spiked club"); try this too
      // HumanA bob("Bob", club);
      // bob.attack();
      // club.setType("some other type of club");
      // bob.attack();
      // HumanB jim("Jim");
      // jim.setWeapon(club);
      // jim.attack();
      // club.setType("some other type of club");
      // jim.attack();
   // }
   return 0;
}