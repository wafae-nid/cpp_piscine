
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{

    Animal *Animals[100];

    for(int i = 0;i < 100; i++)
    {
        if(i < 50)
        {
            Animals[i] = new Dog();
        }
        else if(i>=50)
        {
            Animals[i] = new Cat();
        }
    }

    std::cout << "***************************************************************\n";
    for(int i = 0;i < 100; i++)
    {
       delete Animals[i];
    }
    
    return 0;
}