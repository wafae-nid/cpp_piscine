#include "Array.hpp"

Test::Test()
{
    x = 3;
}
template<typename T>
Array<T>::Array()
{
    array = NULL;
    size = 0;
}
template<typename T>
Array<T>::Array(unsigned int n)
{
    size = n;
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
    size = copy.size;
    array = new T[size];
    for(unsigned int i = 0; i <size ; i++)
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
        size = copy.size;
        array = new T[size];
        for(unsigned int i = 0; i <size ; i++)
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

int main( void ) {

    Array<Test> arr(7);
    Array<Test> arr_2(5);
    arr_2 = arr;

    for(int i =0;i<7;i++)
    {
        std::cout<< arr_2.array[i].x << "\n";
    }
}