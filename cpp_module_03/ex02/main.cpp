
#include "FragTrap.hpp"

int main()
{
    {
        FragTrap frog("frog");
        frog.attack("target");
        frog.takeDamage(21522);
        frog.beRepaired(12533);

    }
    std::cout <<"***************************************************\n";
    {
        FragTrap froggy("froggy");
        froggy.attack("scav_TARGET");
        froggy.takeDamage(2);
        froggy.beRepaired(5);
        froggy.highFivesGuys();
    }
    return 0;
}