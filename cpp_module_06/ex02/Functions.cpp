#include "Functions.hpp"

Base* generate(void)
{
    Base* ptr;

    int random = rand()%3;

    if(random == 0)
       ptr = new A;
    else if(random == 1)
        ptr = new B;
    else
        ptr = new C;
    return(ptr);
}

void identify(Base* p)
{
    if(dynamic_cast<A*>(p)) 
        std::cout << "its an A type\n";
    else if(dynamic_cast<B*>(p))
        std::cout << "its an B type\n";
    else if(dynamic_cast<C*>(p))
        std::cout << "its an C type\n";
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "its an A type \n";
        return;
    }
    catch(std::exception &e)
    {
    }
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "its a B type\n";
        return;
    }
    catch(std::exception &e)
    {
    }

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "its a C type \n";
        return;
    }
    catch(std::exception &e)
    {
    }
}