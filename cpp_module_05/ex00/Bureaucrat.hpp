#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public :
        Bureaucrat();
        Bureaucrat(const std::string name_, const int grade_);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat& operator=(const Bureaucrat& copy);
        ~Bureaucrat();

        const std::string getName(void)const;
        int getGrade(void)const; // int is returned by value no need to do const
        // void setName(const std::string& name_); cant have setname name is const
        void setGrade(const int& grade_);

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

        void increment(void);
        void decrement(void);
};
std::ostream& operator<<(std::ostream& os,const Bureaucrat& copy);


#endif