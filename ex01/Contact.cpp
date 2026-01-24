/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:53:48 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/24 16:31:03 by wnid-hsa         ###   ########.fr       */
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

void Contact::set_first_name()
{
    std::cout<<"First name" <<" : ";
    if(!std::getline(std::cin, first_name))
    {
        std::cout<< "you successfully exited the program \n";
        exit(0);
    }
    if(first_name.empty() || imprintable(first_name))
    {
        while(first_name.empty() || imprintable(first_name))
        {
            std::cout<< "you can not enter an empty field try again !\n";
            std::cout<<"First name"<<" : ";
            std::getline(std::cin, first_name);   
        }
    }
}

void Contact::set_last_name()
{
    std::cout<<"Last name" <<" : ";
    if(!std::getline(std::cin, last_name))
    {
        std::cout<< "you successfully exited the program \n";
        exit(0);
    }
    if(last_name.empty() || imprintable(last_name))
    {
        while(last_name.empty() || imprintable(last_name))
        {
            std::cout<< "you can not enter an empty field try again !\n";
            std::cout<<"last name"<<" : ";
            std::getline(std::cin, last_name);   
        }
    }
}
void Contact::set_nickname()
{
    std::cout<<"Nickname" <<" : ";
    if(!std::getline(std::cin, nickname))
    {
        std::cout<< "you successfully exited the program \n";
        exit(0);
    }
    if(nickname.empty() || imprintable(nickname))
    {
        while(nickname.empty() || imprintable(nickname))
        {
            std::cout<< "you can not enter an empty field try again !\n";
            std::cout<<"Nickname"<<" : ";
            std::getline(std::cin, nickname);   
        }
    }
}
void Contact::set_phone_number()
{
    std::cout<<"Phone number" <<" : ";
    if(!std::getline(std::cin, phone_number))
    {
        std::cout<< "you successfully exited the program \n";
        exit(0);
    }
    if(phone_number.empty() || imprintable(phone_number))
    {
        while(phone_number.empty() || imprintable(phone_number))
        {
            std::cout<< "you can not enter an empty field try again !\n";
            std::cout<<"Phone number" <<" : ";
            std::getline(std::cin, phone_number);
        }
    }
}
void Contact::set_darkest_secret()
{
    std::cout<<"Darkest secret" <<" : ";
    if(!std::getline(std::cin, darkest_secret))
    {
        std::cout<< "you successfully exited the program \n";
        exit(0);
    }
    if(darkest_secret.empty() || imprintable(darkest_secret))
    {
        while(darkest_secret.empty() || imprintable(darkest_secret))
        {
            std::cout<< "you can not enter an empty field try again !\n";
            std::cout<<"Darkest secret"<<" : ";
            std::getline(std::cin, darkest_secret);   
        }
    }
}
const std::string Contact::get_first_name()const
{
    return(first_name);
}
const std::string Contact::get_last_name()const
{
    return(last_name);
}
const std::string Contact::get_nickname()const
{
    return(nickname);
}
const std::string Contact::get_phone_number()const
{
    return(phone_number);
}
const std::string Contact::get_darkest_secret()const
{
    return(darkest_secret);
}