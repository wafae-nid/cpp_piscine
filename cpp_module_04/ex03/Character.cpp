#include "Character.hpp"
#include "AMateria.hpp" // now we need full definitions as we already have just forward defenition of that class in header to avoid circular including

Character::Character()
{
    for(int i =0; i<4; i++)
    {
        slots[i] = NULL;
        collection[i] = NULL; // we want our slots to be epty at construction not have garbage value
    }
}

Character::Character(std::string const & name_): name(name_)
{
     for(int i =0; i<4; i++)
    {
        slots[i] = NULL;
        collection[i] = NULL; // we want our slots to be epty at construction not have garbage value
    }
}

Character::Character(const Character& copy)
{
   name = copy.name;
   for(int i = 0 ; i < 4; i++)
   {
        if(copy.slots[i] == NULL) // so this doesnt crash when derefrencing null
            slots[i] = NULL;
        else
            slots[i] = copy.slots[i]->clone(); // u cant use NEW AMATERIA AMATERIA IS ABSTRACT;
   }   
}
 
Character& Character::operator=(const Character& copy)
{
    if(this != &copy)
    {
        name = copy.name;
        for(int i = 0 ; i < 4; i++)
        {
            if(slots[i])
                delete slots[i];
            if(copy.slots[i] == NULL) // so this doesnt crash when derefrencing null
                slots[i] = NULL;
            else
                slots[i] = copy.slots[i]->clone();
        }
    }
    return(*this);
}
Character::~Character()
{
   
    // delete slots[]; wrong slots is not made by new[] to be able to be deleted by slots[]

    for(int i = 0; i < 4 ; i++)
    {
        if(slots[i])
            delete slots[i];
        if(collection[i])
            delete collection[i];
    }
}

void Character::setName(const std::string& name_)
{
    name = name_;
}
std::string const & Character::getName() const
{
    return(name);
}

void Character::equip(AMateria* m)
{
    int i;

    i = 0;
    while(i< 4 && slots[i])
    {
        i++;
    }
    if(i < 4)
        slots[i] = m;
}
void Character::unequip(int idx)
{
    if(idx < 0 || idx >=4)
        return;

    if(slots[idx])
    {
        collection[idx] = slots[idx];
        slots[idx]= NULL;
    }
}
void Character::use(int idx, ICharacter& target) // when to use ICharacter and when to use character
{
    if (idx < 0 || idx >= 4 || slots[idx] == NULL)
        return;
    slots[idx]->use(target);
} 