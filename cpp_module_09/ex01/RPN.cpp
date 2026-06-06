#include "RPN.HPP"

RPN::RPN()
{

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
    return(isdigit(c) || std::isspace(static_cast<unsigned char>(c)) ||
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
std::string RPN::trim(const std::string& s)
{
    size_t start = s.find_first_not_of(" \v\f\t\r\n");
    size_t end   = s.find_last_not_of(" \v\f\t\r\n");
    if (start == std::string::npos)
        return "";
    return s.substr(start, end - start + 1);
}
bool RPN::calculate(char c)
{
    int nbr_2 = rpn_stack.top();
    rpn_stack.pop();

    int nbr_1 = rpn_stack.top();
    rpn_stack.pop();
    int result;

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
    rpn_stack.push(result);
    return(true);
}
bool RPN::RPN_extract(std::string tmp)
{
    if(tmp.size() != 1)
    {
        std::cerr << "ERROR \n";
        return(false);
    }
    if(isdigit(tmp[0]))
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