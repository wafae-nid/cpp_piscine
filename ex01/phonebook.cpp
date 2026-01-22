/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:22:02 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/22 09:38:54 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void Contact::set_contact()
{
  const std::array<std::string, 5> fields = {
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
        if(contact[i].empty())
        {
            while(contact[i].empty())
            {
                std::cout<< "you can not enter an empty field try again !\n";
                std::cout<<fields[i] <<" : ";
                std::getline(std::cin, contact[i]);   
            }
        }
    }
}
const std::array<std::string, 5>& Contact::get_contact() const
{
    return(contact);
}
int PhoneBook::count = 0;
int PhoneBook::flag = 0;

void PhoneBook::add()
{
   Contact contact;
   
   contact.set_contact();
   flag = 1;
   if(count == 8)
    count = 0;
   book[count] = contact;
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
        for(int j = 0; j< 10; j++)
        {
            std::cout<< '-';
        }
        std::cout<<'+';
        // std::cout<< std::string(10,'-')<< '+';// use an other function to display ue line ;
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
void PhoneBook::entery_display(int index)
{
    std::string str;
    const std::array<std::string, 5> fields = {
        "First name",
        "Last name",
        "Nickname",
        "Phone number",
        "darkest secret"
    };
    for (int i = 0; i < 5; i++) 
    {
        std::cout<< fields[i] << " : ";
        str = book[index].get_contact()[i];
        std::cout<< str ;
        std::cout<<'\n';
    }
    
}
void PhoneBook::fetching()
{
    std::string input;
    
    std::cout<< "choose an index \n";
    if(!std::getline(std::cin, input))
    {
        std::cout<< "you successfully exited the program \n";
        exit(0);
    }
    while(input.length() != 1 || ( std::stoi(input) < 0 || std::stoi(input) >= count))
    {
        std::cout<< "try again no entery has this index\n";
        if(!std::getline(std::cin, input))
        {
            std::cout<< "you successfully exited the program \n";
            exit(0);
        }
    }
    
    line_display();
    std::cout<< '\n';
    entery_display(std::stoi(input));
    std::cout<< '\n';
    line_display();
}
void PhoneBook::search()
{
    
    static_display();
    dynamic_display();
    fetching(); 
}
void PhoneBook::run()
{
    std::string input;
    while(1)
    {
        std::cout<< "enter one of the following commands : \n" << "1 - ADD \n" << "2 - SEARCH \n" << "3 - EXIT \n";
        if(!std::getline(std::cin, input))
        {
            std::cout<<"you successfully exited the PhoneBook\n";
            exit(0);
        }
        if(input.compare("ADD") == 0)
            add();
        else if(input.compare("SEARCH") == 0)
        {
            if(flag)
                search();
            else
                std::cout<<"PhoneBook is empty please ADD a contact \n";
        }
        else if(input.compare("EXIT") == 0)
            exiting();
    }
}

int main ()
{
    PhoneBook phonebook; // change the constructor so the object can be fully created and just add a run function
    phonebook.run();
    return(0);   
}