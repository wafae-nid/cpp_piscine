#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardonForm", 25, 5),target("Default_target")
{
}
PresidentialPardonForm::PresidentialPardonForm(const std::string& target_)
:AForm("PresidentialPardonForm", 25, 5),target(target_)
{

}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
:AForm(copy),target(copy.target) // AForm takes only the base portion of the copy 
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
    if(this != &copy)
    {
        AForm::operator=(copy);
        target = copy.target;
    }
    return(*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

const std::string PresidentialPardonForm::getTarget(void)const
{
    return(target);
}

void PresidentialPardonForm::executeAction() const
{
   std::cout << target << " has been pardoned by Zaphod Beeblebrox.\n";
}