#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal Default constructor is called \n";
}

WrongAnimal::WrongAnimal(const std::string name):type(name)
{
    std::cout << "WrongAnimal constructor is called \n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
    std::cout << " WrongAnimal copy constructor is called \n";
    type = copy.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy)
{
    std::cout <<" WrongAnimal copy assignment operator is called \n";
    if(this != &copy)
    {
        type = copy.type;
    }
    return(*this);
}
WrongAnimal::~WrongAnimal()
{
    std::cout <<" WrongAnimal destructor is called \n";
}

const std::string WrongAnimal::getType(void)const
{
    return(type);
}
void WrongAnimal::settype(const std::string str)
{
    type = str;
}
void WrongAnimal::makeSound()const
{
    std::cout << "WrongAnimal makes sound\n";
}