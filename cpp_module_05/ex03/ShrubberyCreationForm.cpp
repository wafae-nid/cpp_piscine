#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():AForm("ShrubberyCreationForm", 145, 137),target("Default_target")
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target_)
:AForm("ShrubberyCreationForm", 145, 137),target(target_)
{

}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
:AForm(copy),target(copy.target) // AForm takes only the base portion of the copy 
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
    if(this != &copy)
    {
        AForm::operator=(copy);
        target = copy.target;
    }
    return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const std::string ShrubberyCreationForm::getTarget(void)const
{
    return(target);
}

void ShrubberyCreationForm::executeAction() const
{
    std::string file_name;

    file_name = target + "_shrubbery";
   std::ofstream file(file_name.c_str());
    if (!file)
        throw std::runtime_error("Cannot create shrubbery file");
    file << "    *\n" << "   ***\n" << "  *****\n" << " *******\n" << "    |\n" << "    |\n"; 
}