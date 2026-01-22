#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
    private :
        Contact book[8];
        int     count;
        int     flag;

        void    add();
        void    static_display();
        void    line_display();
        void    dynamic_display();
        void    entery_display(int index);
        void    fetching();
        void    search();
        void    exiting();
    public:
        PhoneBook();
        void run();  
};

#endif