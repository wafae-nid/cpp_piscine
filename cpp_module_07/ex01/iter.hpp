#ifndef ITER_HPP
#define ITER_HPP


#include<iostream>

template<typename T>
void function(T &value)
{
    value = 42;

}
template<typename T>
void print_array(T const &value)
{
    std::cout << value << "\n";
}

template<typename T_1, typename T_2>

void iter(T_1 *array, size_t const &length, T_2 func)
{
    for(size_t i = 0; i< length ; i++)
       func(array[i]);
}

#endif