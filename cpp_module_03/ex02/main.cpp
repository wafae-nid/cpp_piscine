
#include "FragTrap.hpp"

int main()
{
    {
        FragTrap frog("frog");
        frog.attack("target");
        frog.takeDamage(-22);
        frog.beRepaired(-3);

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