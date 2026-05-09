#include "Serializer.hpp"

int main()
{
    Data data;
    Data* Serialized;
    uintptr_t raw;

    Data* ptr;
    ptr = &data;

    ptr->value = 2;
    raw = Serializer::serialize(ptr);
    std::cout << raw << "\n";
    Serialized = Serializer::deserialize(raw);
    if(ptr == Serialized)
    {
      std::cout<< "worked\n";
      std::cout << Serialized->value <<"\n";
    }
    else
      std::cout<<"failed\n";

}