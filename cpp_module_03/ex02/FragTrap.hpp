#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap: public ClapTrap
{
    public :
    FragTrap();
    FragTrap(const std::string& name_);
    FragTrap(const FragTrap& copy);
    FragTrap& operator=(const FragTrap& copy);
    ~FragTrap();
    void highFivesGuys(void);
};

#endif