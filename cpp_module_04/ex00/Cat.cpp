#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat Default constructor is called \n";
}

Cat::Cat(const std::string name):Animal(name)
{
    std::cout << "Cat constructor is called \n";
    type = name;
}

Cat::Cat(const Cat& copy)
{
    std::cout << "Cat copy constructor is called \n";
    type = copy.type;
}

Cat& Cat::operator=(const Cat& copy)
{
    std::cout <<"Cat copy assignment operator is called \n";
    if(this != &copy)
    {
        type = copy.type;
    }
    return(*this);
}

Cat::~Cat()
{
    std::cout <<"Cat destructor is called \n";
}

void Cat::makeSound()const
{
    std::cout << "Cat meows\n";
}