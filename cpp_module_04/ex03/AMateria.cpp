#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout << "AMateria default constructor is called \n";
}

AMateria::AMateria(std::string const & type): type(type)
{
    std::cout << "AMateria constructor is called \n";
}

AMateria::AMateria(const AMateria& copy)
{
   std::cout << "AMateria copy constructor is called \n";
   type = copy.type;
   
}

AMateria& AMateria::operator=(const AMateria& copy)
{
    std::cout << "AMateria copy assignment operator is called \n";
    if(this != &copy)
    {
        type = copy.type;
    }
    return(*this);
}
AMateria::~AMateria()
{
    std::cout << "AMateria destructor is called \n";
}

 std::string const & AMateria::getType() const
{
    return(type);
}

void AMateria::setType(std::string const & type)
{
    type = type;
}