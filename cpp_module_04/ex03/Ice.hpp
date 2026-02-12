#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice: public AMateria
{
    public :
    
        Ice(std::string const & type);
        Ice(const Ice& copy);
        Ice& operator=(const Ice& copy);
        Ice();
        ~Ice();
        Ice* clone() const;
        void use(ICharacter& target);
};


#endif