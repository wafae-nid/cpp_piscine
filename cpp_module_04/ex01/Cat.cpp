#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat Default constructor is called \n";
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(const std::string name)
{
    std::cout << "Cat constructor is called \n";
    type = name;
    brain = new Brain();
}

Cat::Cat(const Cat& copy)
{
    std::cout << "Cat copy constructor is called \n";
    type = copy.type;
    brain = new Brain();
    *brain = *copy.brain;

}

Cat& Cat::operator=(const Cat& copy)
{
    std::cout <<"Cat copy assignment operator is called \n";
    if(this != &copy)
    {
        delete(brain);
        brain = new Brain();
        *brain = *copy.brain; 
        type = copy.type;
    }
    return(*this);
}

Cat::~Cat()
{
    std::cout <<"Cat destructor is called \n";
    delete(brain);
}

void Cat::makeSound()const
{
    std::cout << "Cat meows\n";
}