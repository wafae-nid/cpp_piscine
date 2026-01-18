#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <array>

class Contact
{
    private :
        std::array<std::string, 4> contact;
    public :
        void set_contact();
        const std::array<std::string, 4>& get_contact() const;
};

#endif