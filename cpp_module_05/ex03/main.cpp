
#include "Intern.hpp"

int main()
{
   Intern intern;
   AForm *aform;


   try
   {

       aform = intern.makeForm("robttttt", "target");
       std::cout << aform->getName() << "\n";
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << "\n";
    }
}