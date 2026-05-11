#include "Array.hpp"

class Test
{
    public:
        int x;
        Test();
};

Test::Test()
{
    x = 3;
}
// template<typename T>
// Array<T>::Array(): array(NULL), length(0)
// {

// }

// template<typename T>
// Array<T>::Array(unsigned int n)
// {
//     length = n;
//     array = new T[n];
//     for(unsigned int i = 0; i<n ;i++)
//     {
//         array[i] = T();
//     }
// }

// template<typename T>
// Array<T>::Array(const Array& copy)
// {
//     length = copy.length;
//     array = new T[length];
//     for(unsigned int i = 0; i <length ; i++)
//     {
//         array[i]= copy.array[i];
//     }
// }

// template<typename T>
// Array<T>& Array<T>::operator=(const Array& copy)
// {
//     if(this != &copy)
//     {
//         delete[]array;
//         length = copy.length;
//         array = new T[length];
//         for(unsigned int i = 0; i <length ; i++)
//         {
//             array[i]= copy.array[i];
//         }
//     }
//     return(*this);
// }

// template<typename T>

// Array<T>::~Array()
// {
//     delete[]array;
// }

// template<typename T>
// const char* Array<T>::IndexIsOutOfBounds::what()const throw()
// {
//     return "index is out of bounds";
// }

// template<typename T>
// T& Array<T>::operator[](unsigned int index)
// {
//     if(index >= length)
//         throw(IndexIsOutOfBounds());
//     return(array[index]);
// }

// template<typename T>
// const T& Array<T>::operator[](unsigned int index)const
// {
//     if(index >= length)
//         throw(IndexIsOutOfBounds());
//     return(array[index]);
// }
// template<typename T>
// unsigned int Array<T>::size(void)const
// {
//     return(length);
// }

int main()
{
    try
    {
        std::cout << "CONSTRUCTION TEST\n";

        Array<int> a;
        std::cout << "a is an empty array size: " << a.size() << "\n";

        Array<int> b(5);
        std::cout << "Size of b: " << b.size() << "\n";

        for (unsigned int i = 0; i < b.size(); i++)
            b[i] = i * 10;

        std::cout << "ASSIGNMENT TEST\n";
        std::cout << "assigning b to a\n";

        a = b;
        std::cout << "size of a is now :" << a.size() <<"\n";
        std::cout << "content of a is now : \n";
        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i] <<"\n";

        std::cout << "deep copy test \n";
        std::cout <<"we change a[0] to 999\n";

        a[0] = 999;
        std::cout << "a[0] : "<< a[0] << "\n";

        std::cout <<  "b[0] : " << b[0] << "\n";

        std::cout << "out of bound test\n";
        try
        {
            std::cout << a[10] <<"\n";
        }
        catch(std::exception &e)
        {
            std::cout << e.what();
        }
        std::cout << "lets change index 2 in a \n";
        a[2]=1000;
        std::cout << a[2] << "\n";
    }
    catch(std::bad_alloc &e)
    {
         std::cout << "bad_alloc: " << e.what() << "\n";
    }
}