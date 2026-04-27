#include "Bureaucrat.hpp"


int main()
{
   Bureaucrat bur("wafae",3);
    
    std::cout<< bur << "\n";
    try
    {
      for(int i = 0;i<3;i++)
      {
        bur.increment();
      }
      std::cout << bur;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << "\n";
    }
    try
    {
      bur.decrement();
      std::cout << bur;
    }
    catch (std::exception & e)
   {
     std::cout << e.what() << "\n";
   }
}
