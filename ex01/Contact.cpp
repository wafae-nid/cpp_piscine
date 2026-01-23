/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:53:48 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/23 17:15:46 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int Contact::imprintable(std::string str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if(!std::isprint(str[i])){
            return(1);
        }
        i++;
    }
    return(0);
}

void Contact::set_contact()
{
 const std::string fields[5] = {
    "First name",
    "Last name",
    "Nickname",
    "Phone number",
    "darkest secret"
    };
 
    for (int i = 0; i < 5; i++) {
        
        std::cout<<fields[i] <<" : ";
        if(!std::getline(std::cin, contact[i]))
        {
            std::cout<< "you successfully exited the program \n";
            exit(0);
        }
        if(contact[i].empty() || imprintable(contact[i]))
        {
            while(contact[i].empty() || imprintable(contact[i]))
            {
                std::cout<< "you can not enter an empty field try again !\n";
                std::cout<<fields[i] <<" : ";
                std::getline(std::cin, contact[i]);   
            }
        }
    }
}
const std::string *Contact::get_contact() const
{
    return(contact);
}