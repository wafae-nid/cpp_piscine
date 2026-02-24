
#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooLowException::what()const throw()
{
    return "Grade too low \n";
}

const char* Bureaucrat::GradeTooHighException::what()const throw()
{
    return "Grade too high\n";
}
Bureaucrat::Bureaucrat():name("Default"),grade(1)
{
}

Bureaucrat::Bureaucrat(const std::string name_, const int grade_):name(name_)
{
    if(grade_ < 1)
        throw Bureaucrat::GradeTooLowException();
    else if(grade_ > 150)
        throw Bureaucrat::GradeTooHighException();
    grade = grade_;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy):name(copy.name),grade(copy.grade)
{
  // name  is const you cant change it but its okay if its in initialization list 
   
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
    if(this != &copy)
    {
        // name = copy.name; // cant assign name cause its const and assignment operator can take only assignable members
        grade = copy.grade;
    }
    return(*this);
}

Bureaucrat::~Bureaucrat()
{
}

const std::string Bureaucrat::getName()const
{
    return(name);
}

int Bureaucrat::getGrade()const
{
    return(grade);
}

void Bureaucrat::setGrade(const int& grade_)
{
     if(grade_ < 1)
        throw Bureaucrat::GradeTooLowException();
    else if(grade_ > 150)
        throw Bureaucrat::GradeTooHighException();
    grade = grade_;
}

void Bureaucrat::increment(void)
{
    long long grade_;

    grade_ =getGrade() - 1;  
    if(grade_ < 1)
        throw Bureaucrat::GradeTooLowException();
    grade = static_cast<int>(grade_);
}

void Bureaucrat::decrement(void)
{
    long long grade_;

    grade_ =getGrade() + 1;  
    if(grade_ > 150)
        throw Bureaucrat::GradeTooHighException();
    grade = static_cast<int>(grade_);
}
std::ostream& operator<<(std::ostream& os,const Bureaucrat& copy)
{
   std::cout << copy.getName() << ", bureaucrat grade " << copy.getGrade();
   return(os);
}

