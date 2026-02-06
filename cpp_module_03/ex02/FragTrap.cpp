
#include "FragTrap.hpp"

FragTrap::FragTrap():ClapTrap()
{            
    std::cout << "FragTrap default constructor is called \n";
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
}
FragTrap::FragTrap(const std::string& name_):ClapTrap(name_)
{
    std::cout << "FragTrap constructor is called \n";
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
}
FragTrap::FragTrap(const FragTrap& copy)
{
    std::cout << " FragTrap Copy assignment operator called \n";
    name = copy.name;
    hit_points = copy.hit_points;
    energy_points = copy.energy_points;
    attack_damage = copy.attack_damage;
    
}
FragTrap& FragTrap::operator=(const FragTrap& copy)
{
   std::cout << " FragTrap Copy assignment operator called \n";
   if(this != &copy)
   {
      name = copy.name;
        hit_points = copy.hit_points;
        energy_points = copy.energy_points;
        attack_damage = copy.attack_damage;
   }
   return(*this);  
}
FragTrap::~FragTrap()
{
   std::cout << "FragTrap Destructor is called \n"; 
}
void FragTrap::highFivesGuys(void)
{
    std::cout << "Hey! Give me a high five! \n";
}