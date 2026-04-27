
#include "Bureaucrat.hpp"
#include "Form.hpp"

const char* Bureaucrat::GradeTooLowException::what()const throw()
{
    return "Bureaucrat Grade too low \n";
}

const char* Bureaucrat::GradeTooHighException::what()const throw()
{
    return "Bureaucrat Grade too high\n";
}
Bureaucrat::Bureaucrat():name("Default"),grade(1)
{
}

Bureaucrat::Bureaucrat(const std::string name_, const unsigned int grade_):name(name_)
{
    if(grade_ < 1)
        throw Bureaucrat::GradeTooHighException();
    else if(grade_ > 150)
        throw Bureaucrat::GradeTooLowException();
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

unsigned int Bureaucrat::getGrade()const
{
    return(grade);
}

void Bureaucrat::increment(void)
{
    int grade_;

    grade_ =getGrade() - 1;  
    if(grade_ < 1)
        throw Bureaucrat::GradeTooHighException();
    grade = grade_;
}

void Bureaucrat::decrement(void)
{
   int grade_;

    grade_ =getGrade() + 1;  
    if(grade_ > 150)
        throw Bureaucrat::GradeTooLowException();
    grade = grade_;
}

void  Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << "\n";
    }
    catch (std::exception & e)
    {
        std::cout << name <<  " couldn’t sign " << form.getName() << " because " << e.what() << "\n" ;
    }

}

std::ostream& operator<<(std::ostream& os,const Bureaucrat& copy)
{
   os << copy.getName() << ", bureaucrat grade " << copy.getGrade();
   return(os);
}

