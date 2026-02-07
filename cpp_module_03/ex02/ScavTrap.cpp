
#include "ScavTrap.hpp"


ScavTrap::ScavTrap()
{            
    std::cout << "ScavTrap default constructor is called \n";
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
}
ScavTrap::ScavTrap(const ScavTrap& copy)
{
    std::cout << " ScavTrap Copy assignment operator called \n";
    name = copy.name;
    hit_points = copy.hit_points;
    energy_points = copy.energy_points;
    attack_damage = copy.attack_damage;
    
}
ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
   std::cout << " ScavTrap Copy assignment operator called \n";
   if(this != &copy)
   {
      name = copy.name;
        hit_points = copy.hit_points;
        energy_points = copy.energy_points;
        attack_damage = copy.attack_damage;
   }
   return(*this);  
}
ScavTrap::ScavTrap(const std::string& name_):ClapTrap(name_)
{            
    std::cout << "ScavTrap constructor is called \n";
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
}
//  if u dont call a destructor for this class The compiler-generated destructor will call the base class destructor automatically
// BUT, the compiler-generated destructor does nothing extra for the derived part, because you didn’t write anything.

ScavTrap::~ScavTrap()
{
   std::cout << "ScavTrap Destructor is called \n"; 
}
void ScavTrap::attack(const std::string& target)
{
    if(hit_points > 0 && energy_points > 0)
    {
        std::cout << "ScavTrap " << name << " attacks " << target << " ,causing " << attack_damage << " points of damage!" << "\n";
        energy_points--;
    }
    else
        std::cout << "ScavTrap" << name << " cannot attack " << target <<  "\n";
}
void ScavTrap::guardGate()
{
   std::cout << " ScavTrap is now in Gate keeper mode." << "\n"; 
}