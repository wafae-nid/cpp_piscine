#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
int main()
{
    Bureaucrat Burr;

    //  std::cout << stro.get_signing_grade();
    try
    {
        RobotomyRequestForm robot;
        robot.execute(Burr);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << "\n";
    }
    try
    {
        PresidentialPardonForm form;
        form.execute(Burr);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << "\n";
    }
}
