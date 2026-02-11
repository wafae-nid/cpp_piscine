#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat Default constructor is called \n";
}

WrongCat::WrongCat(const std::string name):WrongAnimal(name)
{
    std::cout << "WrongCat constructor is called \n";
    type = name;
}

WrongCat::WrongCat(const WrongCat& copy)
{
    std::cout << "WrongCat copy constructor is called \n";
    type = copy.type;
}

WrongCat& WrongCat::operator=(const WrongCat& copy)
{
    std::cout <<"WrongCat copy assignment operator is called \n";
    if(this != &copy)
    {
        type = copy.type;
    }
    return(*this);
}
WrongCat::~WrongCat()
{
    std::cout <<"WrongCat destructor is called \n";
}

void WrongCat::makeSound()const
{
    std::cout << "WrongCat meows\n";
}