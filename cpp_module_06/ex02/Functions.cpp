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
    if(dynamic_cast<A*>(p)) //because if type casting fails it returns NULLptr else it reaturns the type u want
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
        dynamic_cast<A&>(p);
        std::cout << "its an A reference \n";
        return;
    }
    catch(std::exception &e)
    {
        std::cout << e.what()<< "\n";
    }
    try
    {
        dynamic_cast<B&>(p);
        std::cout << "its an B reference \n";
        return;
    }
    catch(std::exception &e)
    {
        std::cout << e.what()<< "\n";
    }

    try
    {
        dynamic_cast<C&>(p);
        std::cout << "its an B reference \n";
        return; // i need return because catching happens here so this function doesnt stop
    }
    catch(std::exception &e)
    {
        std::cout << e.what()<< "\n";
    }
}