#include "Intern.hpp"

const char*  Intern::FormNotFound::what()const throw()
{
    return "No form WITH SUCH NAME exists \n";
}

 Intern:: Intern()
{
}

 Intern:: Intern(const  Intern& copy)
{
    (void)copy;
}

 Intern&  Intern::operator=(const  Intern& copy)
{
    (void)copy;
    return(*this);
}

Intern::~Intern()
{

}

AForm *Intern::ShrubberyCreator(std::string const & target)
{
    return new ShrubberyCreationForm(target);
}
AForm *Intern::RobotomyRequestCreator(std::string const & target)
{
    return new RobotomyRequestForm(target);
}
AForm *Intern::PresidentialPardonFormCreator(std::string const & target)
{
    return new PresidentialPardonForm(target);
}
AForm *Intern::makeForm(const std::string& form_name, const std::string& target)
{
    int i = 0;
    
    AForm *(Intern::*ptr[])(const std::string&)={
        &Intern::ShrubberyCreator,
        &Intern::RobotomyRequestCreator,
        &Intern::PresidentialPardonFormCreator,
    };
    
    std::string str[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon",
    };
    while(i< 3&& str[i].compare(form_name))
        i++;
    if(i<3)
        return(this->*ptr[i])(target);
    throw FormNotFound();

}