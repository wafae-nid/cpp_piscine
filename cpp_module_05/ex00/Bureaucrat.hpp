#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public :
        Bureaucrat();
        Bureaucrat(const std::string name);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat& operator=(const Bureaucrat& copy);
        ~Bureaucrat();

        const std::string getName()const;
        const int getGrade()const;
        void setName(const std::string& name);
        void setGrade(const std::string& grade)const;

       class GradeTooLowException:public std::execption
       {
            public:
                virtual const char* what()const throw();
        };
        class GradeTooHighException:public std::execption
        {
            public:
                virtual const char* what()const throw();
        };
};




#endif