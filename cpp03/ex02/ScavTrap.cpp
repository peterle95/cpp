/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:23:39 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/04 14:31:54 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) 
{
    std::cout << "ScavTrap: " << name << " is created!" << std::endl;
    ClapTrap::setHitPoints(100);
    ClapTrap::setEnergyPoints(50);
    ClapTrap::setAttackDamage(20);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap: " << ClapTrap::getName() << " is destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target) 
{
    if (ClapTrap::getEnergyPoints() > 0 && ClapTrap::getHitPoints() > 0) 
    {
        std::cout << "ScavTrap: " << ClapTrap::getName() << " attacks " << target 
                  << ", causing " << ClapTrap::getAttackDamage() << " points of damage!" << std::endl;
        ClapTrap::setEnergyPoints(ClapTrap::getEnergyPoints() - 1);
    } else 
    {
        std::cout << "ScavTrap: " << ClapTrap::getName() << " can't attack. Not enough energy or hit points." << std::endl;
    }
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap: " << ClapTrap::getName() << " is now in Gate keeper mode." << std::endl;
}