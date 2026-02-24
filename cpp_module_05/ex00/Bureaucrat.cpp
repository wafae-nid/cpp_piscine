
#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooLowException:what()const throw()
{
    return "Grade too low \n";
}

const char* Bureaucrat::GradeTooHighException:what()const throw()
{
    return "Grade too high\n";
}
Bureaucrat::Bureaucrat():grade(1),name("Default")
{
}

Bureaucrat::Bureaucrat(const std::string name_, const int grade_)
{
    if(grade_ < 1)
        throw Bureaucrat::GradeTooLowException();
    else if(grade_ > 150)
        throw Bureaucrat::GradeTooHighException();
    name = name_;
    grade = grade_;
}

Bureaucrat::Bureaucrat(constBureaucratl& copy)
{
    name = copy.name;
    grade = copy.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
    if(this != &copy)
    {
        name = copy.name;
        grade = copy.grade;
    }
    return(*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout <<"Bureaucrat destructor is called \n";
}
// const std::string Bureaucrat::getType(void)const
// {
//     return(type);
// }
// void Bureaucrat::settype(const std::string str)
// {
//     type = str;
// }
