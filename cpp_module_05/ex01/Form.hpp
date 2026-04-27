#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string name;
        bool  is_signed;
        const unsigned int signing_grade;
        const unsigned int execution_grade;
    
    public:
        Form();
        Form(const std::string name_, const unsigned int signing_grade_, const unsigned int execution_grade_);
        Form(const Form& copy);
        Form& operator=(const Form& copy);
        ~Form();


        class GradeTooLowException:public std::exception
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

    // void set_is_signed(bool sign);
    void beSigned(Bureaucrat& bureaucrat);
};
std::ostream& operator<<(std::ostream& os,const Form& copy);

#endif