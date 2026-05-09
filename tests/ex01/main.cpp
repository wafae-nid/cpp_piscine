#include "Form.hpp"


int main()
{
    
    try
    {
        Form form("format", 2, 15);
        Bureaucrat Bur("burrito", 3);
        Bur.signForm(form);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << "\n";
    }
}