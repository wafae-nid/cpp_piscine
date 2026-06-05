#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <map>
#include <iomanip>

std::map<std::string,float> data_to_map(void);

class BitcoinExchange
{
    private:
        std::map<std::string,float> map_db;
    public:
        BitcoinExchange();
    // BitcoinExchange(const BitcoinExchange& copy);
    // BitcoinExchange& operator=(const BitcoinExchange& copy);

        ~BitcoinExchange();
    
    
};

#endif