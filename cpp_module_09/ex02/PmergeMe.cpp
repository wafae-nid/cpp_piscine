#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}
PmergeMe::~PmergeMe()
{

}

bool PmergeMe::parse_input(std::string str)
{
    if (str.empty())
     return false;
    for(size_t i = 0; i < str.size(); i++)
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return(false);
    }
    return(true);
}
 void PmergeMe::run(char **argv, int argc)
 {
    for(int i = 1; i < argc; i++)
    {
        if(!parse_input(argv[i]))
        {
            std::cerr << "ERROR \n";
            return; 
        }
        char *end;
        long nbr = strtol(argv[i], &end, 10);
        if(*end !='\0' ||nbr >INT_MAX )
        {
            std::cerr << "ERROR \n";
            return; 
        }
        vec.push_back(nbr);
        deq.push_back(nbr);
    }
 }