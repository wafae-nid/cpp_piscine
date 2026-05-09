
#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Default constructor is called \n";
}
Brain::Brain(const Brain& copy)
{
    std::cout << "Brain copy constructor is called \n";
    for(int i = 0; i<100; i++)
    {
        ideas[i] = copy.ideas[i];
    }
}
Brain& Brain::operator=(const Brain& copy)
{
    std::cout <<"Brain copy assignment operator is called \n";
    if(this != &copy)
    { 
        for(int i = 0; i<100; i++)
        {
            ideas[i] = copy.ideas[i];
        }
    }
    return(*this);
}
Brain::~Brain()
{
    std::cout <<"Brain destructor is called \n";
}

std::string Brain::getidea(int index)const    // no need for const as the std::string already returns a value they r two different copies
{
    if (index < 0 || index >= 100)
    {
        std::cout<< "index out of range function getidea gonna return empty string\n ";
        return "";
    }
    return(ideas[index]);
}

void  Brain::setidea(int index, const std::string& str) // search why passing reference here is better 
{
    if (index < 0 || index >= 100)
    {
        std::cout<< "index out of range function setidea gonna return\n ";
        return ;
    }
    ideas[index] = str;
}
