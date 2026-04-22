#ifndef ARRAY_HPP
#define ARRAY_HPP


#include<iostream>


class Test
{
    public:
        int x;
        Test();
};
template<typename T>
class Array
{
    public:
        T *array;
        Array();
        Array(unsigned int n);
        Array(const Array& copy);
        Array& operator=(const Array& copy);

    private:
       unsigned int size;


};

#endif