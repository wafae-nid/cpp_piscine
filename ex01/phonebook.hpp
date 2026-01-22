#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>

class Contact
{
    private :
        std::string contact[5];
        int     inprintable(std::string str);
    public :
        void set_contact();
        const std::string* get_contact() const;
};
class PhoneBook
{
    private :
        Contact book[8];
        static int     count;
        static int     flag;
        void    add();
        void    static_display();
        void    line_display();
        void    dynamic_display();
        void    entery_display(int index);
        void    fetching();
        void    search();
        void    exiting();
    public:
       void run();  
};
#endif