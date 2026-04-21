#ifndef HEADER_HPP
#define HEADER_HPP


#include<iostream>

template<typename T>

void swap(T &value_1, T &value_2)
{
    T tmp;
    tmp = value_1;
    value_1 = value_2;
    value_2 = tmp;
}
template<typename T>

T min(T const &value_1, T const &value_2)
{
    if((value_1 >= value_2))
        return(value_2);
    else 
        return(value_1);
}
template<typename T>

T max(T const &value_1, T const &value_2)
{
    if((value_1 <= value_2))
        return(value_2);
    else 
        return(value_1);
}

#endif