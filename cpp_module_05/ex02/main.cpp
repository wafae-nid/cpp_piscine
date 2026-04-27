#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
int main()
{
    Bureaucrat Burr("wafae",3);

    //  std::cout << stro.get_signing_grade();
    RobotomyRequestForm robot;
    try
    {
        robot.execute(Burr);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << "\n";
    }
    try
    {
        Burr.signAForm(robot);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
    PresidentialPardonForm form;
    try
    {
        form.execute(Burr);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << "\n";
    }
    ShrubberyCreationForm shrubbery; 
    try
    {
        shrubbery.execute(Burr);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
    
}
