#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const & type_): type(type_)
{
}

AMateria::AMateria(const AMateria& copy)
{
   type = copy.type;
   
}

AMateria& AMateria::operator=(const AMateria& copy)
{
    if(this != &copy)
    {
        type = copy.type;
    }
    return(*this);
}
AMateria::~AMateria()
{
}
 std::string const & AMateria::getType() const
{
    return(type);
}

void AMateria::setType(std::string const & type_)
{
    type = type_;
}
void AMateria::use(ICharacter& target)
{
    (void) target; // just to silence linker error there is implementations in each child class
}