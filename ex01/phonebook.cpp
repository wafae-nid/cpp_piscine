/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:22:02 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/18 14:04:18 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void Contact::set_contact()
{
    for (int i = 0; i < 4; i++) {
        if(!std::getline(std::cin, contact[i]))
        {
            std::cout<< "you successfully exited the program \n";
            exit(0);
        }
        if(contact[i].empty())
        {
            while(contact[i].empty())
            {
                std::cout<< "you can not enter an empty field try again !\n";
                std::getline(std::cin, contact[i]);   
            }
        }
    }
}
const std::array<std::string, 4>& Contact::get_contact() const
{
    return(contact);
}
int main ()
{
    Contact c1;
    c1.set_contact();
    const std::array<std::string, 4>& input = c1.get_contact(); //refrences in c++ should always be declared and initialized at the same time
    for(int i = 0; i < 4; i++)
    {
        std::cout << input[i];
        std::cout << '\n';  
    }   
}