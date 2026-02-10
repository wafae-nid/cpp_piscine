#ifndef ANIMAL_HPP
#define ANIMAL_HPP

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
        virtual~Animal(); // it needs to be virtual so if u called delete on animal that points on cat it will call destructor of cat not animal

        const std::string getType(void)const;
        void  settype(const std::string str);
        virtual void makeSound()const;


};




#endif