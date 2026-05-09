#include "Form.hpp"

const char* Form::GradeTooLowException::what()const throw()
{
    return "The Grade is too low \n";
}

const char* Form::GradeTooHighException::what()const throw()
{
    return "The Grade is too high\n";
}

Form::Form():name("Default"),is_signed(false),signing_grade(2), execution_grade(5)
{
}

Form::Form(const std::string name_, const unsigned int signing_grade_, const unsigned int execution_grade_)
:name(name_),is_signed(false),signing_grade(signing_grade_),execution_grade(execution_grade_)
{
    if(signing_grade_ < 1 || execution_grade_ < 1)
        throw Form::GradeTooLowException();
    else if(signing_grade_ > 150 || execution_grade_ > 150 )
        throw Form::GradeTooHighException();
}

Form::Form(const Form& copy)
:name(copy.name),is_signed(copy.is_signed),signing_grade(copy.signing_grade),execution_grade(copy.execution_grade)
{
}

Form& Form::operator=(const Form& copy)
{
    if(this != &copy)
    {
        is_signed = copy.is_signed;
    }
    return(*this);
}

Form::~Form()
{
}


const std::string Form::getName(void)const
{
    return(name);
}

bool Form::get_is_signed(void)const
{
    return(is_signed);
}

unsigned int Form::get_signing_grade(void)const
{
    return(signing_grade);
}

unsigned int Form::get_execution_grade(void)const
{
    return(execution_grade);
}

void Form::set_is_signed(bool sign)
{
    is_signed = sign;
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
    if(bureaucrat.getGrade() <= signing_grade)
        is_signed = true;
    else
        throw GradeTooLowException();

}

std::ostream& operator<<(std::ostream& os,const Form& copy)
{
    os << "Form name is : " << copy.getName() << "\n" ;
    os << "Form signing status is : " << copy.get_is_signed() << "\n";
    os << "Form required grade for signing is : " <<  copy.get_signing_grade() << "\n";
    os << "Form required grade for execution is : " <<  copy.get_execution_grade() << "\n";
    return(os);
}

