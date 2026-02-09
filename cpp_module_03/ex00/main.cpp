
#include "ClapTrap.hpp"

int main() {
    {
        ClapTrap clappy("clapp_clapp");
        clappy.attack("target");
        clappy.takeDamage(21522);
        clappy.beRepaired(12533);
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
