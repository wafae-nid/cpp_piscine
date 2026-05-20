#include "Span.hpp"

const char* SpanIsFull::what()const throw()
{
    return "span is full";
}
const char* CantCalculateDistance::what()const throw()
{
    return "Cant calculate distance";
}
Span::Span():N(0)
{

}

Span::Span(unsigned int n):N(n)
{
    
}

Span::Span(const Span& copy):N(copy.N),vec(copy.vec)
{
   
}
Span& Span::operator=(const Span& copy)
{
    if(this != &copy)
    {
        N = copy.get_size();
        vec = copy.get_vector();
    }
    return(*this);
}
Span::~Span()
{

}

void Span::addNumber(int number)
{
    if(vec.size() == N)
        throw SpanIsFull();
    vec.push_back(number);
} 

unsigned int Span::get_size(void) const
{
    return(N);
}
const std::vector<int>& Span::get_vector(void) const
{
    return(vec);
}
unsigned int Span::shortestSpan()
{
    if(vec.size() <2)
        throw CantCalculateDistance();
    std::vector<int> tmp(vec); // you should not sort the original vector
    std::sort(tmp.begin(), tmp.end());
    unsigned int shortest = tmp[1] - tmp[0];
    for(size_t i = 1;i < (tmp.size() -1); i++) // because in loop you do i+1
    {
        unsigned int distance = tmp[i+1] -tmp[i];
        if(distance < shortest)
            shortest = distance;
    }
    return(shortest);   
}

unsigned int Span::longestSpan()
{
    if(vec.size() <2)
        throw CantCalculateDistance();
    std::vector<int> tmp(vec); // you should not sort the original vector
    std::sort(tmp.begin(), tmp.end());
   
    return(tmp[tmp.size() -1] - tmp[0]);
       
}
