/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:24:09 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/16 14:43:14 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

/* You can also write the function like this:
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) 
{
    std::cout << "ClapTrap " << name << " is created!" << std::endl;
} */

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
    std::cout << "ClapTrap " << name << " is created!" << std::endl;
}

ClapTrap::~ClapTrap() 
{
    std::cout << "ClapTrap " << name << " is destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) 
{
    if (energyPoints > 0 && hitPoints > 0) 
    {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    } else 
    {
        std::cout << "ClapTrap " << name << " can't attack. Not enough energy or hit points." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) 
{
    if (hitPoints <= amount) 
    {
        hitPoints = 0;
        std::cout << "ClapTrap " << name << " takes " << amount << " damage and is destroyed!" << std::endl;
    } else 
    {
        hitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount << " damage. Remaining hit points: " << hitPoints << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) 
{
    if (energyPoints > 0 && hitPoints > 0) 
    {
        hitPoints += amount;
        energyPoints--;
        std::cout << "ClapTrap " << name << " repairs itself for " << amount << " hit points. Current hit points: " << hitPoints << std::endl;
    } else 
    {
        std::cout << "ClapTrap " << name << " can't repair. Not enough energy or hit points." << std::endl;
    }
}

// Getters
std::string ClapTrap::getName() const { return name; }
unsigned int ClapTrap::getHitPoints() const { return hitPoints; }
unsigned int ClapTrap::getEnergyPoints() const { return energyPoints; }
unsigned int ClapTrap::getAttackDamage() const { return attackDamage; }

// Setters
void ClapTrap::setName(const std::string& name) { this->name = name; }
void ClapTrap::setHitPoints(unsigned int hitPoints) { this->hitPoints = hitPoints; }
void ClapTrap::setEnergyPoints(unsigned int energyPoints) { this->energyPoints = energyPoints; }
void ClapTrap::setAttackDamage(unsigned int attackDamage) { this->attackDamage = attackDamage; }