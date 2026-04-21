#include "iter.hpp"



int main( void ) {

    int arr[] = {0,1, 2, 3,4};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    iter(arr, size, print_array<int>);
    iter(arr, size, function<int>);
    iter(arr, size, print_array<int>);
   
}