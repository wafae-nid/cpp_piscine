#include "Cure.hpp"


Cure::Cure()
{
    type="cure";
}

Cure::Cure(std::string const & type):AMateria(type)
{
}
Cure::Cure(const Cure& copy)
{
   type = copy.type;
}

Cure& Cure::operator=(const Cure& copy)
{
    if(this != &copy)
    {
        type = copy.type;
    }
    return(*this);
}

Cure::~Cure()
{
}

Cure* Cure::clone() const
{
    Cure *Cure_clone;

    Cure_clone = new Cure;
    Cure_clone->type = type;
    return(Cure_clone);
}
void Cure::use(ICharacter& target)
{
   std::cout << "* heals " << target.getName() << "s wounds *\n";
}