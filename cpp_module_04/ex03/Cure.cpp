#include "Cure.hpp"


Cure::Cure()
{
    type="cure";
    std::cout << "Cure default constructor is called \n";
}

Cure::Cure(std::string const & type):AMateria(type)
{
    std::cout << "Cure constructor is called \n";
}
Cure::Cure(const Cure& copy)
{
   std::cout << "Cure copy constructor is called \n";
   type = copy.type;
   
}

Cure& Cure::operator=(const Cure& copy)
{
    std::cout << "Cure copy assignment operator is called \n";
    if(this != &copy)
    {
        type = copy.type;
    }
    return(*this);
}

Cure::~Cure()
{
    std::cout << "Cure destructor is called \n";
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
   std::cout << " Cure: * heals " << target.getName() << "s wounds *\n";
}