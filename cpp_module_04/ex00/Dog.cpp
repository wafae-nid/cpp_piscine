#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog Default constructor is called \n";
}

Dog::Dog(const std::string name)
{
    std::cout << "Dog constructor is called \n";
    type = name;
}

Dog::Dog(const Dog& copy)
{
    std::cout << "Dog copy constructor is called \n";
    type = copy.type;
}

Dog& Dog::operator=(const Dog& copy)
{
    std::cout <<"Dog copy assignment operator is called \n";
    if(this != &copy)
    {
        type = copy.type;
    }
    return(*this);
}

Dog::~Dog()
{
    std::cout <<"Dog destructor is called \n";
}

void Dog::makeSound()const
{
    std::cout << "Dog barks\n";
}