/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:24:09 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/04 14:23:03 by pmolzer          ###   ########.fr       */
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
    std::cout << "ClapTrap: " << name << " is created!" << std::endl;
}

ClapTrap::~ClapTrap() 
{
    std::cout << "ClapTrap: " << name << " is destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) 
{
    if (energyPoints > 0 && hitPoints > 0) 
    {
        std::cout << "ClapTrap: " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    } else 
    {
        std::cout << "ClapTrap: " << name << " can't attack. Not enough energy or hit points." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) 
{
    if (hitPoints <= amount) 
    {
        hitPoints = 0;
        std::cout << "ClapTrap: " << name << " takes " << amount << " damage and is destroyed!" << std::endl;
    } else 
    {
        hitPoints -= amount;
        std::cout << "ClapTrap: " << name << " takes " << amount << " damage. Remaining hit points: " << hitPoints << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) 
{
    if (energyPoints > 0 && hitPoints > 0) 
    {
        hitPoints += amount;
        energyPoints--;
        std::cout << "ClapTrap: " << name << " repairs itself for " << amount << " hit points. Current hit points: " << hitPoints << std::endl;
    } else 
    {
        std::cout << "ClapTrap: " << name << " can't repair. Not enough energy or hit points." << std::endl;
    }
}