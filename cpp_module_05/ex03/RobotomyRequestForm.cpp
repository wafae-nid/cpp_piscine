#include "RobotomyRequestForm.hpp"

bool RobotomyRequestForm::seeded = false;
RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm", 72, 45),target("Default_target")
{
    if(!seeded)
    {
        std::srand(std::time(NULL));
        seeded = true;
    }
}
RobotomyRequestForm::RobotomyRequestForm(const std::string& target_)
:AForm("RobotomyRequestForm", 72, 45),target(target_)
{
     if(!seeded)
    {
        std::srand(std::time(NULL));
        seeded = true;
    }
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
:AForm(copy),target(copy.target) // AForm takes only the base portion of the copy 
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
    if(this != &copy)
    {
        AForm::operator=(copy);
        target = copy.target;
    }
    return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

const std::string RobotomyRequestForm::getTarget(void)const
{
    return(target);
}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "ddzzzzzzzz....drilling noises.....\n";
    if (std::rand() % 2)
        std::cout << target << " has been robotomized successfully.\n";
    else
        std::cout << "Robotomy failed on " << target << ".\n";
}
