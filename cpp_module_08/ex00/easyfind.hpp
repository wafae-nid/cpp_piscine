#ifndef EASYFIND_HPP
#define EASYFIND_HPP


#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <deque>

class NotFound:public std::exception
{
    public:
        virtual const char* what()const throw();
};


template<typename T>

typename T::iterator easyfind(T &container, const int to_find)
{
    typename T::iterator it;
    it =  std::find(container.begin(), container.end(), to_find);
    if(it == container.end())
        throw NotFound();
    return(it);
} 

#endif