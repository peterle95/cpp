#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : name("") {}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie() 
{
    std::cout << name << " has been destroyed." << std::endl;
}

void Zombie::announce() const 
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string& newName) 
{
    name = newName;
}