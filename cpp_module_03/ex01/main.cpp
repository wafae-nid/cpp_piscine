
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    {
        ScavTrap  Scav("scav_scav");
        Scav.attack("target");
        Scav.takeDamage(21522);
        Scav.beRepaired(12533);
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