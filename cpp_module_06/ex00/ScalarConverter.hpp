#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "helpers.hpp"

class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter& operator=(const ScalarConverter& copy);
        ScalarConverter(const ScalarConverter& copy);
    // they r like this just to prevent cpp from generating default ones that are public and will make the class intiniable
    public:
        static void convert(const std::string& literal);
};

#endif