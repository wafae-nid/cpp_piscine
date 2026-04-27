#include "Form.hpp"


int main()
{
    
    Form form("format", 2, 15);
    Bureaucrat Bur("burrito", 3);
    
    Bur.signForm(form);
    try
    {
        Bur.increment();
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << "\n";
    }
    Bur.signForm(form);
}