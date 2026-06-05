#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cout << "Error: could not open file.\n";
        return(1);
    }
    
    BitcoinExchange bit;
    std::string str = argv[1];
    bit.processInput(str);
    return(0);
}