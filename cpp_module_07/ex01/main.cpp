#include "iter.hpp"



int main( void ) {

    int arr[] = {0,1, 2, 3,4};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    for(size_t i = 0; i < size ; i++)
    {
        std::cout << arr[i]<< "\n"; 
    }
    iter(arr, size, function<int>);
    for(size_t i = 0; i < size ; i++)
    {
        std::cout << arr[i]<< "\n"; 
    }
}