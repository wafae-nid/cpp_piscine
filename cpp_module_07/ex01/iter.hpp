#ifndef ITER_HPP
#define ITER_HPP


#include<iostream>

template<typename T>
void increment(T &x)
{
    x++;
}

template<typename T>
void print_array(T const &x)
{
    std::cout << x << "\n";
}

template<typename T, typename F>

void iter(T *array, const size_t length, F func)
{
    if (!array)
        return;
    for(size_t i = 0; i< length ; i++)
       func(array[i]);
}

#endif