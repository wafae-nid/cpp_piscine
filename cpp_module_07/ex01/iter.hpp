#ifndef ITER_HPP
#define ITER_HPP


#include<iostream>

template<typename T>
void function(T &value)
{
    value = 42;

}
template<typename T_1, typename T_2, typename T_3>

void iter(T_1 *array, T_2 const &length, T_3 func)
{
    for(T_2 i = 0; i< length ; i++)
       func(array[i]);
}

#endif