#include "Ice.hpp"


Ice::Ice()
{
    type="ice";
}

Ice::Ice(std::string const & type):AMateria(type)
{
}

Ice::Ice(const Ice& copy)
{
   type = copy.type;
   
}

Ice& Ice::operator=(const Ice& copy)
{
    if(this != &copy)
    {
        type = copy.type;
    }
    return(*this);
}

Ice::~Ice()
{
}

Ice* Ice::clone() const
{
    Ice *Ice_clone;

    Ice_clone = new Ice;
    Ice_clone->type = type;
    return(Ice_clone);
}
void Ice::use(ICharacter& target)
{
   std::cout << "* shoots an ice bolt at " <<  target.getName() << " * \n"; 
}