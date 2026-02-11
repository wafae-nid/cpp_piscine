#ifndef AMETERIA_HPP
#define AMETERIA_HPP

#include <string>
// #include "ICharacter.hpp"
#include <iostream>

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria(std::string const & type);
        AMateria(const AMateria& copy);
        AMateria& operator=(const AMateria& copy);
        AMateria();
        virtual ~AMateria();

        std::string const & getType() const;
        void setType(std::string const & type);

        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif