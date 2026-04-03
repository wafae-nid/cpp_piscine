#include "Serializer.hpp"

int main()
{
    Data data;
    Data* Serialized;
    uintptr_t raw;

    Data* ptr;
    ptr = &data;

    raw = Serializer::serialize(ptr);
    Serialized = Serializer::deserialize(raw);
    if(ptr == Serialized)
      std::cout<< "worked\n";
    else
      std::cout<<"failed\n";

}