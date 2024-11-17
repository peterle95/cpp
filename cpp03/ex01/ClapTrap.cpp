/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:24:09 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/16 17:52:33 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"  /* Include the header file for the ClapTrap class */
#include <iostream>      /* Include the iostream library for input/output operations */

/* You can also write the function like this:
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) 
{
    std::cout << "ClapTrap " << name << " is created!" << std::endl;
} */

/* 
 * Constructor for the ClapTrap class.
 * Initializes the ClapTrap's name, hit points, energy points, and attack damage.
 */
ClapTrap::ClapTrap(std::string name)
{
    /*
     * We need to initialize the name because, although we are passing it to the constructor,
     * we must assign it to the class's member variable to store it for later use. The "this->"
     * keyword is used to refer to the current instance of the class, which helps distinguish
     * between the member variable "name" and the parameter "name" passed to the constructor.
     */
    this->name = name;  /* Set the name of the ClapTrap instance */
    hitPoints = 10;     /* Initialize hit points to 10 */
    energyPoints = 10;  /* Initialize energy points to 10 */
    attackDamage = 0;   /* Initialize attack damage to 0 */
    std::cout << "ClapTrap " << name << " is created!" << std::endl; /* Print creation message */
}

/* 
 * Destructor for the ClapTrap class.
 * Cleans up when a ClapTrap instance is destroyed.
 */
ClapTrap::~ClapTrap() 
{
    std::cout << "ClapTrap " << name << " is destroyed!" << std::endl; /* Print destruction message */
}

/* 
 * Method for the ClapTrap to attack a target.
 * Reduces the target's hit points based on the ClapTrap's attack damage.
 */
void ClapTrap::attack(const std::string& target) 
{
    if (energyPoints > 0 && hitPoints > 0)  /* Check if ClapTrap has enough energy and hit points */
    {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl; /* Print attack message */
        energyPoints--;  /* Decrease energy points by 1 */
    } else 
    {
        std::cout << "ClapTrap " << name << " can't attack. Not enough energy or hit points." << std::endl; /* Print failure message */
    }
}

/* 
 * Method for the ClapTrap to take damage.
 * Reduces the ClapTrap's hit points based on the damage taken.
 */
void ClapTrap::takeDamage(unsigned int amount) 
{
    if (hitPoints <= amount)  /* Check if the damage amount is greater than or equal to current hit points */
    {
        hitPoints = 0;  /* Set hit points to 0 if damage exceeds current hit points */
        std::cout << "ClapTrap " << name << " takes " << amount << " damage and is destroyed!" << std::endl; /* Print destruction message */
    } else 
    {
        hitPoints -= amount;  /* Subtract damage from hit points */
        std::cout << "ClapTrap " << name << " takes " << amount << " damage. Remaining hit points: " << hitPoints << std::endl; /* Print remaining hit points */
    }
}

/* 
 * Method for the ClapTrap to repair itself.
 * Increases the ClapTrap's hit points based on the repair amount.
 */
void ClapTrap::beRepaired(unsigned int amount) 
{
    if (energyPoints > 0 && hitPoints > 0)  /* Check if ClapTrap has enough energy and hit points */
    {
        hitPoints += amount;  /* Increase hit points by the repair amount */
        energyPoints--;  /* Decrease energy points by 1 */
        std::cout << "ClapTrap " << name << " repairs itself for " << amount << " hit points. Current hit points: " << hitPoints << std::endl; /* Print current hit points */
    } else 
    {
        std::cout << "ClapTrap " << name << " can't repair. Not enough energy or hit points." << std::endl; /* Print failure message */
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