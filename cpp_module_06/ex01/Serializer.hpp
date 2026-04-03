#ifndef Serializer_HPP
#define Serializer_HPP

#include <string>
#include <iostream>
#include <cctype>

#include "Data.hpp"

class Serializer
{
    private:
        Serializer();
        ~Serializer();
        Serializer& operator=(const Serializer& copy);
        Serializer(const Serializer& copy);
    // they r like this just to prevent cpp from generating default ones that are public and will make the class intiniable
    public:
        static uintptr_t serialize(Data* ptr);
       static Data* deserialize(uintptr_t raw);
};

#endif