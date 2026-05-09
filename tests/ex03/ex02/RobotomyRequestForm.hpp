#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"
#include <ctime>
#include <cstdlib>

class RobotomyRequestForm:public AForm
{
    private:
        std::string target;
        static bool seeded;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target_);
        RobotomyRequestForm(const RobotomyRequestForm& copy);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
        ~RobotomyRequestForm();
        const std::string getTarget(void)const;
        void executeAction() const; 
};


#endif