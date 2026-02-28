
#include "Intern.hpp"

int main()
{
   Intern intern;
   AForm *aform;


   aform = intern.makeForm("robotomy request", "target");
   std::cout << aform->getName() << "\n";
}