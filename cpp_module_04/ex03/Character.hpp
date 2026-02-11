#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character: public ICharacter
{
    private : 
        AMateria *slots[4];
        AMateria *collection[4];
        std::string name;
    public :
        Character();
        Character(const std::string& name);
        Character(const Character& copy);
        Character& operator=(const Character& copy);
        ~Character();
    
        std::string const & getName() const;
        void setName(const std::string& name);
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

}




#eCharacter