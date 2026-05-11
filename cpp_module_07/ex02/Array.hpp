#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>


template<typename T>
class Array
{
public:
    Array();
    Array(unsigned int n);
    Array(const Array& copy);
    Array& operator=(const Array& copy);
    ~Array();

    T& operator[](unsigned int index);
    
    const T& operator[](unsigned int index) const;

    class IndexIsOutOfBounds : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    unsigned int size() const;

private:
    T* array;
    unsigned int length;
};

#include "Array.tpp"

#endif