
#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name_):ClapTrap(name_)
{
    std::cout << "FragTrap constructor is called \n";
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
}
FragTrap::~FragTrap()
{
   std::cout << "FragTrap Destructor is called \n"; 
}
void FragTrap::highFivesGuys(void)
{
    std::cout << "Hey! Give me a high five! \n";
}