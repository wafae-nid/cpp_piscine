/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:22:02 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/18 19:38:21 by wnid-hsa         ###   ########.fr       */
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
int PhoneBook::count = 0;

void PhoneBook::add()
{
   Contact contact;
   
   contact.set_contact();
   if(count == 3)
    count = 0;
   book[count] = contact;
//    std::cout<< count;
//    std::cout<<'\n';
//    std::cout<< book[count].get_contact()[0];
   count++; 
}
void PhoneBook::exiting()
{
    std::cout<< "you exited phonebook all contacts are forever lost\n";
    exit(1);
}
void PhoneBook::line_display()
{
    std::cout<< '+';
    for(int i = 0; i < 4; i++)
    {
        std::cout<< std::string(10,'-')<< '+';
    }
    std::cout<< '\n';
    
}
void PhoneBook::static_display()
{
    line_display();
    std::cout<< '|'<< std::setw(10) << "index"  ;
    std::cout<< '|'<< std::setw(10) << "fisrt name" ;
    std::cout<< '|'<< std::setw(10) << "last name" ;
    std::cout<< '|'<< std::setw(10) << "nickname" << '|' ;
    std::cout<< '\n';
}

void PhoneBook::dynamic_display()
{
    std::string str;
    
    for(int i = 0; i < count; i++)
    {
        line_display();
        std::cout<< '|'<< std::setw(10) << i;
        for(int j = 0; j < 3;j++)
        {
            str = book[i].get_contact()[j];
            if(str.length()> 10)
                std::cout<< '|'<< std::setw(9) << str.substr(0,9)<< '.';
            else
                std::cout<< '|'<< std::setw(10) << str ;
        }
        std::cout << '|';
        std::cout<< '\n';
    }
    line_display();
}
void PhoneBook::search()
{
    static_display();
    dynamic_display();
}
PhoneBook::PhoneBook()
{
    std::string input;
    while(1)
    {
        if(!std::getline(std::cin, input))
        {
            std::cout<<"you successfully exited the PhoneBook\n";
            exit(0);
        }
        if(input.compare("ADD") == 0)
            add();
        else if(input.compare("SEARCH") == 0)
            // std::cout<<"search\n";
           search();
        else if(input.compare("EXIT") == 0)
            exiting();
        
    }
}

int main ()
{
   
    PhoneBook phonebook;
    return(0);   
}