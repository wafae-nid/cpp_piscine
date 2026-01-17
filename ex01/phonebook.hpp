#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>

class Contact
{
    private :
        std::string first_name;
        std::string last_name;
        std::string phone_number;
        std::string darkest_sec;
    public :
        void set_first_name(const std::string& value);
        const std::string& get_first_name() const;
        void set_last_name(const std::string& value);
        const std::string& get_last_name() const;
        void set_phone_nbr(const std::string& value);
        const std::string& get_phone_nbr() const;
        void set_dark_sec(const std::string& value);
        const std::string& get_dark_sec() const;
};

#endif