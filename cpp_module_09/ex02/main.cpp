#include "PmergeMe.hpp"

bool parse_input(std::string str)
{
    for(size_t i = 0; i < str.size(); i++)
    {
        if(!isdigit(str[i]))
            return(false);
    }
    return(true);
}
int main(int argc, char **argv)
{
    PmergeMe pmerge;
    pmerge.run(argv,argc);
    
}