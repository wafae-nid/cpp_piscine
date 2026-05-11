#include "iter.hpp"

void append_exclamation(std::string &s)
{
    s += "!";
}

int main()
{
    // ===== INT TEST =====
    int arr[] = {1, 2, 3, 4};

    std::cout << "Before iter:\n";
    iter(arr, 4,  print_array<int>);

    iter(arr, 4, increment<int>);

    std::cout << "After increment:\n";
    iter(arr, 4, print_array<int>);

   // ===== FLOAT TEST =====
    float farr[] = {1.5f, 2.5f, 3.5f};

    std::cout << "Float test:\n";
    std::cout << "Before iter:\n";
    iter(farr, 3, print_array<float>);
    iter(farr, 3, increment<float>);
    std::cout << "After increment:\n";
    iter(farr, 3, print_array<float>);

    // ===== STRING TEST =====
    std::string sarr[] = {"hello", "world"};

    std::cout << "String test:\n";
    iter(sarr, 2, print_array<std::string>); // std::string dont support ++ opertor thats why i cant test with that function
    iter(sarr,2,append_exclamation);
    iter(sarr, 2, print_array<std::string>);
    
}