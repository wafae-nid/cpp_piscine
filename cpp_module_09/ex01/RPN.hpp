#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <cctype>
#include <stack>
#include <sstream>
class RPN
{
    private:
        std::stack<int> rpn_stack;
    public :
        RPN();
        ~RPN();

        void RPN_run(std::string input);
        bool is_operator(char c);
        bool is_valid_char(char c);
        bool calculate(char c);
        bool is_valid_string(std::string input);
        void RPN_core(std::string input);
        bool RPN_extract(std::string tmp);
        std::string trim(const std::string& s);
};


#endif