#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

class Animal
{
    protected :
      std::string type;
    public:
        Animal();
        Animal(const std::string name);
        Animal(const Animal& copy);
        Animal& operator=(const Animal& copy);
        ~Animal();
        virtual void makeSound()const;

};




#endif