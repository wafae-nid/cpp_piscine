
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    {
        ScavTrap  Scav("scav_scav");
        Scav.attack("target");
        Scav.takeDamage(-10);
        Scav.beRepaired(-3);
        Scav.guardGate();

    }
    std::cout <<"***************************************************\n";
    {
        ScavTrap Scavy("scavy");
        Scavy.attack("scav_TARGET");
        Scavy.takeDamage(2);
        Scavy.beRepaired(5);
        Scavy.guardGate();
    }
    return 0;
}