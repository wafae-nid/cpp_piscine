#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP


#include <string>
#include <iostream>

class AMateria;

//If you inherit privately, your class hides the interface, and other code cannot use it polymorphically. 
class ICharacter
{
    public:
        virtual ~ICharacter() {}
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};

#endif