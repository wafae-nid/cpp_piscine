
#include "Animal.h"

Animal::Animal()
{
    std::cout << "Animal Default constructor is called \n";
}

Animal::Animal(const std::string name):type(name)
{
    std::cout << "Animal constructor is called \n";
}

Animal::Animal(const Animal& copy)
{
    std::cout << "Animal copy constructor is called \n";
    type = copy.type;
}

Animal& Animal::operator=(const Animal& copy)
{
    std::cout <<"Animal copy assignment operator is called \n";
    if(this != &copy)
    {
        type = copy.type;
    }
    return(*this);
}
Animal::~Animal()
{
    std::cout <<"Animal destructor is called \n";
}
void Animal::makeSound()const
{
    std::cout << "Animal makes sound\n";
}
