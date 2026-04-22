#include "Array.hpp"

Test::Test()
{
    x = 3;
}
template<typename T>
Array<T>::Array()
{
    array = NULL;
    lenght = 0;
}
template<typename T>
Array<T>::Array(unsigned int n)
{
    lenght = n;
    array = new T[n];
    if(array == NULL)
        return;
    for(unsigned int i = 0; i<n ;i++)
    {
        array[i] = T();
    }
}
template<typename T>
Array<T>::Array(const Array& copy)
{
    lenght = copy.size;
    array = new T[lenght];
    for(unsigned int i = 0; i <lenght ; i++)
    {
        array[i]= copy.array[i];
    }
}
template<typename T>
Array<T>& Array<T>::operator=(const Array& copy)
{
    if(this != &copy)
    {
        delete[]array;
        lenght = copy.lenght;
        array = new T[lenght];
        for(unsigned int i = 0; i <lenght ; i++)
        {
            array[i]= copy.array[i];
        }
    }
    return(*this);
}
template<typename T>

Array<T>::~Array()
{
    delete[]array;
}

template<typename T>
const char* Array<T>::IndexIsOutOfBounds::what()const throw()
{
    return "index is out of bounds\n";
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
    if(index < 0 || index > lenght)
        throw(IndexIsOutOfBounds());
    return(array[index]);
}
template<typename T>
const unsigned int& Array<T>::size(void)const
{
    return(lenght);
}
int main( void ) {

    Array<Test> arr(7);
    Array<Test> arr_2(5);
    arr_2 = arr;
    try
    {
        std::cout << arr[6].x <<"\n";
    }
    catch(std::exception &e)
    {
        std::cout << e.what();
    }
    std::cout<< arr.size();
}