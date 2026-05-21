#ifndef SPAN_HPP
#define SPAN_HPP


#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
class SpanIsFull:public std::exception
{
    public:
        virtual const char* what()const throw();
};
class CantCalculateDistance:public std::exception
{   
    public:
        virtual const char* what()const throw();
};

class Span 
{
    public:
        Span();
        Span(unsigned int n);
        Span(const Span& copy);
        Span& operator=(const Span& copy);
        ~Span();
        
        void addNumber(int number);
        unsigned int shortestSpan();
        unsigned int longestSpan();

        unsigned int get_size(void) const;
        const std::vector<int>& get_vector(void) const;

        template<typename T>

        void range(T begin, T end)
        {
            size_t dist = std::distance(begin, end);
            if (vec.size() + dist > N)
                throw SpanIsFull();
            vec.insert(vec.end(), begin, end);
        }

    private :
        unsigned int N;
        std::vector<int> vec;
};

#endif