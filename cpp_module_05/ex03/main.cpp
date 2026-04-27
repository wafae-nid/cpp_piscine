
#include "Intern.hpp"


struct Simple
{
    Simple()  { std::cout << "Simple constructed\n"; }
    ~Simple() { std::cout << "Simple destroyed\n"; }
};
int main()
{
   Intern intern;
   AForm *aform;

   Simple s;

   try
   {
       aform = intern.makeForm("RobotomyRequestForm", "target");
       std::cout << aform->getName() << "\n";
       delete aform;
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << "Out of memory: " << e.what() << "\n"; // catching new allocation comes just before std::exception
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
}