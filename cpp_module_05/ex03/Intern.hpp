#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


class Intern
{
    public:
        Intern();
        Intern(const  Intern& copy);
        Intern&  operator=(const  Intern& copy);
        ~Intern();
        AForm *makeForm(const std::string& form_name, const std::string& target);
        class FormNotFound:public std::exception // exceptions should be public so the external code can catch them not private ;
       {
            public:
                virtual const char* what()const throw();
        };
    private:
        AForm *PresidentialPardonFormCreator(std::string const & target);
        AForm *RobotomyRequestCreator(std::string const & target);
        AForm *ShrubberyCreator(std::string const & target);
    
};


#endif