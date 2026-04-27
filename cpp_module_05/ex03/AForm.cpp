#include "AForm.hpp"

const char* AForm::GradeTooLowException::what()const throw()
{
    return "The Grade is too low \n";
}

const char* AForm::GradeTooHighException::what()const throw()
{
    return "The Grade is too high\n";
}
const char* AForm::FormUnsignedException::what()const throw()
{
    return "The Form is unsigned \n";
}

AForm::AForm():name("Default"),is_signed(false),signing_grade(2), execution_grade(5)
{
}

AForm::AForm(const std::string name_, const unsigned int signing_grade_, const unsigned int execution_grade_)
:name(name_),is_signed(false),signing_grade(signing_grade_),execution_grade(execution_grade_)
{
    if(signing_grade_ < 1 || execution_grade_ < 1)
        throw AForm::GradeTooHighException();
    else if(signing_grade_ > 150 || execution_grade_ > 150 )
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& copy)
:name(copy.name),is_signed(copy.is_signed),signing_grade(copy.signing_grade),execution_grade(copy.execution_grade)
{
}

AForm& AForm::operator=(const AForm& copy)
{
    if(this != &copy)
    {
        is_signed = copy.is_signed;
    }
    return(*this);
}

AForm::~AForm()
{
}


const std::string AForm::getName(void)const
{
    return(name);
}

bool AForm::get_is_signed(void)const
{
    return(is_signed);
}

unsigned int AForm::get_signing_grade(void)const
{
    return(signing_grade);
}

unsigned int AForm::get_execution_grade(void)const
{
    return(execution_grade);
}

void AForm::set_is_signed(bool sign)
{
    is_signed = sign;
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
    if(bureaucrat.getGrade() <= signing_grade)
        is_signed = true;
    else
        throw GradeTooLowException();

}
void AForm::execute(Bureaucrat const & executor) const
{
    if(!is_signed)
        throw FormUnsignedException();
    if(executor.getGrade() > execution_grade)
        throw GradeTooLowException();
    executeAction();
}
std::ostream& operator<<(std::ostream& os,const AForm& copy)
{
    os << "AForm name is : " << copy.getName() << "\n" ;
    os << "AForm signing status is : " << copy.get_is_signed() << "\n";
    os << "AForm required grade for signing is : " <<  copy.get_signing_grade() << "\n";
    os << "AForm required grade for execution is : " <<  copy.get_execution_grade() << "\n";
    return(os);
}

