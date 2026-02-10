#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog Default constructor is called \n";
    type = "Dog";
    brain = new Brain();
}

Dog::Dog(const std::string name)
{
    std::cout << "Dog constructor is called \n";
    type = name;
    brain = new Brain();
}

Dog::Dog(const Dog& copy)
{
    std::cout << "Dog copy constructor is called \n";
    type = copy.type;
    brain = new Brain();
    *brain = *copy.brain;

}

Dog& Dog::operator=(const Dog& copy)
{
    std::cout <<"Dog copy assignment operator is called \n";
    if(this != &copy)
    {
        delete(brain);
        brain = new Brain();
        *brain = *copy.brain; 
        type = copy.type;
    }
    return(*this);
}

Dog::~Dog()
{
    std::cout <<"Dog destructor is called \n";
    delete(brain);
}

void Dog::makeSound()const
{
    std::cout << "Dog barks\n";
}