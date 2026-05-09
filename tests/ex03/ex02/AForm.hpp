#ifndef AForm_HPP
#define AForm_HPP

#include <string>
#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"

class AForm
{
    private: // the attributes are still private so the derived cant cheat the system like shrubery if they were just procted might chnaegd them and that will pass so they must be rules for all shruberies
        const std::string name;
        bool  is_signed;
        const unsigned int signing_grade;
        const unsigned int execution_grade;
    
    public:
        AForm();
        AForm(const std::string name_, const unsigned int signing_grade_, const unsigned int execution_grade_);
        AForm(const AForm& copy);
        AForm& operator=(const AForm& copy);
        ~AForm();


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
    virtual void executeAction() const = 0;
};
std::ostream& operator<<(std::ostream& os,const AForm& copy);

#endif