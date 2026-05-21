#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP


#include <stack>
#include <deque>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
       MutantStack() : std::stack<T>() {}
       MutantStack(const MutantStack<T>& copy):std::stack<T>(copy) {}

       MutantStack<T>& operator=(const MutantStack<T>& copy)
       {
           if(this != &copy)
              std::stack<T>::operator=(copy);
            return *this;
       }

        ~MutantStack() {}

        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin()
        {
            return this->c.begin();
        }

        iterator end()
        {
            return this->c.end();
        }
};

#endif