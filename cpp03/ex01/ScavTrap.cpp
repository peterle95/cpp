/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:23:39 by pmolzer           #+#    #+#             */
/*   Updated: 2025/02/28 16:48:23 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) 
// This explicitly calls the base class constructor first before executing ScavTrap's constructor body
{
    std::cout << "ScavTrap " << name << " is created!" << std::endl;
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
}

ScavTrap::~ScavTrap()
// Destructors are called in reverse order of construction (derived class first, then base class)
{
    std::cout << "ScavTrap " << this->getName() << " is destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target) 
{
    if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0) 
    {
        std::cout << "ScavTrap " << this->getName() << " attacks " << target 
                  << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
        this->setEnergyPoints(this->getEnergyPoints() - 1);
    } else 
    {
        std::cout << "ScavTrap " << this->getName() << " can't attack. Not enough energy or hit points." << std::endl;
    }
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode." << std::endl;
}