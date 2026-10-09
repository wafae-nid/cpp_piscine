#include "RPN.hpp"

RPN::RPN()
{

}
RPN::RPN(const RPN& other) : rpn_stack(other.rpn_stack)
{
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        rpn_stack = other.rpn_stack;
    return *this;
}
RPN::~RPN()
{

}
bool RPN::is_operator(char c)
{
    return(c == '-' || c == '+' || c == '*' || c == '/');
}
bool RPN::is_valid_char(char c)
{
    return(isdigit(static_cast<unsigned char>(c)) || std::isspace(static_cast<unsigned char>(c)) ||
                 is_operator(c));
    
}
bool RPN::is_valid_string(std::string input)
{
    for(size_t i = 0; i < input.size(); i++)
    {
        if(!is_valid_char(input[i]))
            return(0);
    }
    return(1);
}

bool RPN::calculate(char c)
{
    long nbr_2 = rpn_stack.top();
    rpn_stack.pop();

    long nbr_1 = rpn_stack.top();
    rpn_stack.pop();
    long result = 0 ;

    if(c == '+')
        result = nbr_1 + nbr_2;
    else if(c == '-')
        result = nbr_1 - nbr_2;
    else if (c == '*')
        result = nbr_1 * nbr_2;
    else if(c == '/')
    {
        if(nbr_2 == 0)
        {
            std::cerr << "ERROR \n";
            return(false);
        }
         result = (nbr_1 / nbr_2);
    }
    if(result > INT_MAX || result < INT_MIN)
    {
        std::cerr << "ERROR \n";
            return(false);
    }
    rpn_stack.push(static_cast<int>(result));
    return(true);
}
bool RPN::RPN_extract(std::string tmp)
{
    if(tmp.size() != 1)
    {
        std::cerr << "ERROR \n";
        return(false);
    }
    if(isdigit(static_cast<unsigned char>(tmp[0])))
    {
        int nbr = tmp[0] -'0';
        rpn_stack.push(nbr);
    }
    else if(is_operator(tmp[0]))
    {
        if(rpn_stack.size()< 2)
        {
            std::cerr << "ERROR \n";
            return(false);
        }
        return(calculate(tmp[0])); 
    }
    return(true);

}
void RPN::RPN_core(std::string input)
{
    std::istringstream iss(input);
    std::string tmp ;

    while (iss >> tmp)
    {
        if (!RPN_extract(tmp))
            return;
    }
    if (rpn_stack.size() != 1)
        std::cerr << "ERROR\n";
    else
        std::cout << rpn_stack.top() << std::endl;
}
void RPN::RPN_run(std::string input)
{
    if(!is_valid_string(input))
        std::cerr<< "ERROR \n";
    else
       RPN_core(input);
}