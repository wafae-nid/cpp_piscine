#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    public:
        void guardGate();
        ScavTrap();
        ScavTrap(const std::string& name_);
        ScavTrap(const ScavTrap& copy);
        ScavTrap& operator=(const ScavTrap& copy);
        void attack(const std::string& target);

        ~ScavTrap();
};

#endif