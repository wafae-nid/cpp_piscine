#include "Bureaucrat.hpp"


int main()
{
   Bureaucrat bur;
  std::cout <<  bur.getName() << "\n";
//  try
//     {
//         bur.setGrade(1);
//     }
//     catch (std::exception & e)
//     {
//         std::cout << e.what() << "\n";
//     }
    try
    {
        bur.increment();
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << "\n";
    }
  std::cout << bur;
}