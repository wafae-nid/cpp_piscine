#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"

class AForm
{
    private:
        const std::string name;
        bool  is_signed;
        const unsigned int signing_grade;
        const unsigned int execution_grade;
    
    public:
        AForm();
        AForm(const std::string name_, const unsigned int signing_grade_, const unsigned int execution_grade_);
        AForm(const AForm& copy);
        AForm& operator=(const AForm& copy);
        virtual ~AForm();


        class GradeTooLowException:public std::exception
       {
            public:
                virtual const char* what()const throw();
        };
        class FormUnsignedException:public std::exception
        {
            public:
                virtual const char* what()const throw();
        };
        class GradeTooHighException:public std::exception
        {
            public:
                virtual const char* what()const throw();
        };

    const std::string getName(void)const;
    bool get_is_signed(void)const;
    unsigned int get_signing_grade(void)const;
    unsigned int get_execution_grade(void)const;

    void set_is_signed(bool sign);
    void beSigned(Bureaucrat& bureaucrat);
    void execute(Bureaucrat const & executor) const;
    protected:
        virtual void executeAction() const = 0;
};
std::ostream& operator<<(std::ostream& os,const AForm& copy);

#endif