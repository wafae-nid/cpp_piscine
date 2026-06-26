#include "MutantStack.hpp"


int main()
{
    MutantStack<int> mstack;

    mstack.push(10);
    mstack.push(20);
    mstack.push(30);
    mstack.push(40);
    

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    while (it != ite)
    {
        *it = 50 + *it;
        ++it;
    };

    it = mstack.begin();
     while (it != ite)
    {
       std::cout << *it<< "\n";
        ++it;
    };
   const MutantStack<int> c_mstack(mstack);
    MutantStack<int>::const_iterator c_it = c_mstack.begin();
    MutantStack<int>::const_iterator c_ite = c_mstack.end();
      while (c_it != c_ite)
    {
       std::cout << *c_it<< "\n";
        ++c_it;
    };

}