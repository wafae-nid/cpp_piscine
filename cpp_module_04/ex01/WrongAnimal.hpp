#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP


#include <string>
#include <iostream>

class WrongAnimal
{
    protected :
      std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const std::string name);
        WrongAnimal(const WrongAnimal& copy);
        WrongAnimal& operator=(const WrongAnimal& copy);
        ~WrongAnimal();

        const std::string getType(void)const;
        void  settype(const std::string str);
        void makeSound()const;

};


#endif