#include "Span.hpp"


int main()
{
    Span span(10);
    
    try
    {
        unsigned int  nbr;
        for(unsigned int i =0; i < 5;i++)
        {
            nbr = i*5;
            span.addNumber(nbr);
        }
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

    try
    {
        unsigned int shortest = span.shortestSpan();
        std::cout<< "shortest span is :";
        std::cout<< shortest<< "\n";
    } 
    catch(std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
    try
    {
        unsigned int longest = span.longestSpan();
        std::cout<< "longest span is :";
        std::cout<< longest<< "\n";
    } 
    catch(std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
    std::deque<int> deque_;
    unsigned int  nbr;
    for(unsigned int i =0; i < 3;i++)
    {
        nbr = i*4;
        deque_.push_back(nbr);
    }
    try
    {
        span.range(deque_.begin(), deque_.end());
        for(unsigned int i =0; i <10 ;i++)
        {
            std::cout << "span index "<< i << ": " ;
            std::cout<< (span.get_vector())[i] << "\n";
        }
    } 
    catch(std::exception &e)
    {
        std::cout << e.what()<< "\n";
    }

}