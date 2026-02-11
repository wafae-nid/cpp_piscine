#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    Ice ice;
    std::cout << ice.getType() << "\n";

    Ice *clone;
    clone = ice.clone();
    std::cout << clone->getType() << "\n";

    std::cout << "********************************\n";
    Cure cure;
    std::cout << cure.getType() << "\n";
    Cure *clone_;
    clone_ = cure.clone();
    std::cout << clone_->getType() << "\n";
}