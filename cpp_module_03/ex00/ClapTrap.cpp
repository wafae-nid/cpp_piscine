
#include "ClapTrap.hpp"

ClapTrap::ClapTrap():hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap default constructor is called \n";
}
ClapTrap::ClapTrap(const std::string& name_)
    : name(name_), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap constructor is called \n";
}
ClapTrap::ClapTrap(const ClapTrap& copy)
{
    std::cout << " ClapTrap Copy assignment operator called \n";
    name = copy.name;
    hit_points = copy.hit_points;
    energy_points = copy.energy_points;
    attack_damage = copy.attack_damage;
    
}
ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
   std::cout << " ClapTrap Copy assignment operator called \n";
   if(this != &copy)
   {
      name = copy.name;
        hit_points = copy.hit_points;
        energy_points = copy.energy_points;
        attack_damage = copy.attack_damage;
   }
   return(*this);  
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor is called \n";
}
void ClapTrap::attack(const std::string& target)
{
    if(hit_points > 0 && energy_points > 0)
    {
        std::cout << "ClapTrap " << name << " attacks " << target << " ,causing " << attack_damage << " points of damage!" << "\n";
        energy_points -= 1;
    }
    else
        std::cout << "ClapTrap " << name << " cannot attack " << target <<  "\n";
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if(hit_points > 0)
    {
        if(amount >= hit_points)
            hit_points = 0;
        else
            hit_points -= amount;
        std::cout << "ClapTrap " << name << " takes Damage" <<  " ,causing " << "hit_points to reduce by " << amount << "\n";
    }
    else
        std::cout << "ClapTrap " << name << " can not take Damage"<< "\n";
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if(hit_points > 0 && energy_points > 0)
    {
        hit_points += amount;
        energy_points -= 1;
        std::cout << "ClapTrap " << name << " is repaired" <<  " ,causing " << "hit_points to be raised by " << amount<< "\n";
    }
    else
        std::cout << "ClapTrap " << name << " cannot be repaired" << "\n";  
}