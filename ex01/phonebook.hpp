#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <array>
#include <iomanip>

class Contact
{
    private :
        std::array<std::string, 4> contact;
    public :
        void set_contact();
        const std::array<std::string, 4>& get_contact() const;
};
class PhoneBook
{
    private :
        Contact book[8];
        static int     count;
        void    add();
        void    static_display();
        void    line_display();
        void    dynamic_display();
        void    search();
        void    exiting();
    public:
       PhoneBook();  
};
#endif