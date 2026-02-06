#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    protected: 
        std::string name; // no reference because if we pass a string literal c++ will make a temporary std::string to the constructor that will end when the constructor finishes so here i will have  areference to invalid memory so lets better let the objet own the string nsd have its own 
        unsigned int hit_points;
        unsigned int energy_points;
        unsigned int attack_damage;
    public:
        ClapTrap(const std::string& name_);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        // ClapTrap();
        ~ClapTrap();
};





#endif