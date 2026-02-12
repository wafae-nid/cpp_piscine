#ifndef CURE_HPP
#define CURE_HPP


#include "AMateria.hpp"
#include "Character.hpp"

class Cure: public AMateria
{
    public :
        Cure(std::string const & type);
        Cure(const Cure& copy);
        Cure& operator=(const Cure& copy);
        Cure();
        ~Cure();
        Cure* clone() const;
        void use(ICharacter& target);
};

#endif