
#include "ScavTrap.hpp"


// ScavTrap::ScavTrap():ClapTrap("wafae")
// {
//     std::cout << "ScavTrap default constructor is called \n";
// }

// ScavTrap::ScavTrap() // body happens after so the claptrap is not created befor scavtrap and scravtrap dont have a default construvtor so the other constructor cant be called automatically so u get error cause scarvtrap should be after claptrap
// {
//     ClapTrap("wafae");
//     std::cout << "ScavTrap default constructor is called \n";
// }

//before push try both and see the difference and what happens if u didnt explicitly call the constructor of the base class and try adding  a default constructor in base class vs removing it and having just a constructor that tkes std::string
// ScavTrap::ScavTrap(const std::string& name_):ClapTrap(name_) // cant access private parts of claptrap through this 
// {
//     std::cout << "ScavTrap constructor is called \n";
//     hit_points = 100;
//     energy_points = 50;
//     attack_damage = 20;
// }
// ScavTrap::ScavTrap(const std::string& name_):ClapTrap(name_), hit_points(100),energy_points(50),attack_damage(20) // the derive class initializer can only call class constructors and Initialize members declared in the derived class itself.                                                                                                                  
// {
//                                         //it cannot t cannot initialize base class members directly, even if they are protected.            
//     std::cout << "ScavTrap constructor is called \n";
// //     hit_points = 100;
// //     energy_points = 50;
// //     attack_damage = 20;
// }
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
        energy_points -= 1;
    }
    else
        std::cout << "ScavTrap" << name << " cannot attack " << target <<  "\n";
}
void ScavTrap::guardGate()
{
   std::cout << " ScavTrap is now in Gate keeper mode." << "\n"; 
}