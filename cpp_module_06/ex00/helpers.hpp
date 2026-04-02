#ifndef  HELPERS_HPP
#define  HELPERS_HPP

#include <string>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <climits>

bool is_all_digit(const std::string& literal);
bool is_int(const std::string& literal);
bool is_double(const std::string& literal);
bool is_float(const std::string& literal);
bool is_pseudo_literals(const std::string& literal);
bool is_char(const std::string& literal);

void convert_pseuso_literals(const std::string& literal);
void convert_int(const std::string& literal);
void convert_double_float(const std::string& literal);

#endif