#include "easyfind.hpp"

const char* NotFound::what()const throw()
{
    return "value not found in container";
}

int main()
{
    std::vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    try
    {
        std::vector<int>::iterator it = easyfind(v1, 40);
        std::cout<< *it << "\n";
    }
    catch(std::exception &e)
    {  
        std::cout << e.what()<< "\n";
    }
    try
    {
        std::vector<int>::iterator it = easyfind(v1, 80);
        std::cout<< *it << "\n";
    }
    catch(std::exception &e)
    {  
        std::cout << e.what()<< "\n";
    }
    std::deque<int> deque1;

    deque1.push_back(10);
    deque1.push_back(20);
    deque1.push_back(30);
    deque1.push_back(40);
    deque1.push_back(10);
    try
    {
        std::deque<int>::iterator it = easyfind(deque1, 40);

        std::cout<< *it<< "\n";
    }
    catch(std::exception &e)
    {
        std::cout << e.what()<< "\n";
    }
    return(0);

}