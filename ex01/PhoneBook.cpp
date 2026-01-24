/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:22:02 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/24 16:18:11 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    count = 0;
    flag = 0;
}

void PhoneBook::add()
{
   Contact contact;
   contact.set_first_name();
   contact.set_last_name();
   contact.set_nickname();
   contact.set_phone_number();
   contact.set_darkest_secret();

    if(count == 8)
    {
        count = 0;
    }
    if(flag >= 8)
    {
        flag = 8;
    }
    else
        flag++;
    book[count]= contact;
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
    }
    std::cout<< '\n';
    
}
void PhoneBook::static_display()
{
    line_display();
    std::cout<< '|'<< std::setw(10) << "Index"  ;
    std::cout<< '|'<< std::setw(10) << "Fisrt name" ;
    std::cout<< '|'<< std::setw(10) << "Last name" ;
    std::cout<< '|'<< std::setw(10) << "Nickname" << '|' ;
    std::cout<< '\n';
}

void PhoneBook::field_display(std::string str)
{
    if(str.length()> 10)
        std::cout<< '|'<< std::setw(9) << str.substr(0,9)<< '.';
    else
        std::cout<< '|'<< std::setw(10) << str ;
}

void PhoneBook::dynamic_display()
{
    std::string str;
    
    
    for(int i = 0; i < flag; i++)
    {
        line_display();
        std::cout<< '|'<< std::setw(10) << i;
        str = book[i].get_first_name();
        field_display(str);
        str = book[i].get_last_name();
        field_display(str);
        str = book[i].get_nickname();
        field_display(str);
        std::cout << '|';
        std::cout<< '\n';
    }
    line_display();
}

void PhoneBook::entery_display(int index)
{
    std::string str;

    std::cout<< "First name" << " : ";
    str = book[index].get_first_name();
    std::cout<< str << '\n';
    std::cout<< "Last name" << " : ";
    str = book[index].get_last_name();
    std::cout<< str << '\n';
    std::cout<< "Nickname" << " : ";
    str = book[index].get_nickname();
    std::cout<< str << '\n';
    std::cout<< "Phone_number" << " : ";
    str = book[index].get_phone_number();
    std::cout<< str << '\n';
    std::cout<< "Darkest secret" << " : ";
    str = book[index].get_darkest_secret();
    std::cout<< str << '\n';
    
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
    while(input.length() != 1 || !std::isdigit(input.c_str()[0]) || ( std::atoi(input.c_str()) < 0 || std::atoi(input.c_str()) >= flag))
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
    entery_display(std::atoi(input.c_str()));
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

