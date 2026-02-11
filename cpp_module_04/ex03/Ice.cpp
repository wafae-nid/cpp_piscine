#include "Ice.hpp"


Ice::Ice()
{
    type="ice";
    std::cout << "Ice default constructor is called \n";
}

Ice::Ice(std::string const & type):AMateria(type)
{
    std::cout << "Ice constructor is called \n";
}

Ice::Ice(const Ice& copy)
{
   std::cout << "Ice copy constructor is called \n";
   type = copy.type;
   
}

Ice& Ice::operator=(const Ice& copy)
{
    std::cout << "Ice copy assignment operator is called \n";
    if(this != &copy)
    {
        type = copy.type;
    }
    return(*this);
}

Ice::~Ice()
{
    std::cout << "Ice destructor is called \n";
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
   std::cout << "Ice: /" "* shoots an ice bolt at " <<  target.getName() << "/* /n"; 
}