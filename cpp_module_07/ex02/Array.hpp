#ifndef ARRAY_HPP
#define ARRAY_HPP

#include<iostream>
#include <exception>

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
        ~Array();


        T& operator[](unsigned int n);

        class  IndexIsOutOfBounds:public std::exception
       {
            public:
                virtual const char* what()const throw();
        };

        const unsigned int& size(void)const;   
    private:
       unsigned int lenght;

};

#endif