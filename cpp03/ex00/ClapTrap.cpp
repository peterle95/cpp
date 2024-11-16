/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:24:09 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/16 16:26:53 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
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

/* 
 * Getter for the ClapTrap's name.
 * Returns the name of the ClapTrap instance.
 */
std::string ClapTrap::getName() const 
{ 
    return name;
}

/* 
 * Getter for the ClapTrap's hit points.
 * Returns the current hit points of the ClapTrap instance.
 */
unsigned int ClapTrap::getHitPoints() const 
{ 
    return hitPoints;
}

/* 
 * Getter for the ClapTrap's energy points.
 * Returns the current energy points of the ClapTrap instance.
 */
unsigned int ClapTrap::getEnergyPoints() const 
{ 
    return energyPoints;
}

/* 
 * Getter for the ClapTrap's attack damage.
 * Returns the current attack damage of the ClapTrap instance.
 */
unsigned int ClapTrap::getAttackDamage() const 
{ 
    return attackDamage;
}

/* 
 * Setter for the ClapTrap's name.
 * Sets the name of the ClapTrap instance.
 */
void ClapTrap::setName(const std::string& name) 
{ 
    this->name = name;
}

/* 
 * Setter for the ClapTrap's hit points.
 * Sets the hit points of the ClapTrap instance.
 */
void ClapTrap::setHitPoints(unsigned int hitPoints) 
{ 
    this->hitPoints = hitPoints;
}

/* 
 * Setter for the ClapTrap's energy points.
 * Sets the energy points of the ClapTrap instance.
 */
void ClapTrap::setEnergyPoints(unsigned int energyPoints) 
{ 
    this->energyPoints = energyPoints;
}

/* 
 * Setter for the ClapTrap's attack damage.
 * Sets the attack damage of the ClapTrap instance.
 */
void ClapTrap::setAttackDamage(unsigned int attackDamage) 
{ 
    this->attackDamage = attackDamage;
}