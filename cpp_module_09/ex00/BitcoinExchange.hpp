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
        void processInput(const std::string& file);
        void data_search(std::ifstream& input);
        void processLine(std::string line);
        bool is_valid_date(std::string date);
        bool is_valid_year(std::string year);
        bool is_all_digit(std::string year);
        bool is_valid_month(std::string month);
        bool is_valid_day(std::string day);
        std::string trim(const std::string& s);
        float parse_value(const std::string& val_str, bool& valid);
};

#endif