
#include "ClapTrap.hpp"

int main() {
    {
        ClapTrap clappy("clapp_clapp");
        clappy.attack("target");
        clappy.takeDamage(-8);
        clappy.beRepaired(-42);
    }
    std::cout <<"***************************************************\n";
    {
        ClapTrap clap("clap");
        clap.attack("clapped");
        clap.takeDamage(2);
        clap.beRepaired(5);
    }
    return 0;
}
