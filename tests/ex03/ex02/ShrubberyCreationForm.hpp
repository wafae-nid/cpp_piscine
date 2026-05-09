#ifndef SHRUBBERYCREATIOMFORM_HPP
#define SHRUBBERYCREATIOMFORM_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm:public AForm
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& target_);
        ShrubberyCreationForm(const ShrubberyCreationForm& copy);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
        ~ShrubberyCreationForm();
        const std::string getTarget(void)const;
        void executeAction() const; 
};


#endif