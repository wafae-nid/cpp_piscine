#include "Span.hpp"


int main()
{
    Span span(5);
    
    span.addNumber(10);
    std::vector<int> vector = span.get_vector();
    
}