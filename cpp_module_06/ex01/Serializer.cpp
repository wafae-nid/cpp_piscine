
#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer& copy)
{
  (void)copy;
  // name  is const you cant change it but its okay if its in initialization list 
   
}

Serializer& Serializer::operator=(const Serializer& copy)
{
  (void)copy;
  return(*this);
}

Serializer::~Serializer()
{
}
uintptr_t Serializer::serialize(Data* ptr)
{
  return(reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
  return(reinterpret_cast<Data*>(raw)) ;
}




