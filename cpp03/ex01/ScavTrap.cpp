/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:23:39 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/05 13:59:09 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) 
{
    std::cout << "ScavTrap: " << name << " is created!" << std::endl;
    hitPoints = 100;    // Direct access
    energyPoints = 50;  // Direct access 
    attackDamage = 20;  // Direct access
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap: " << this->name << " is destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target) 
{
    if (energyPoints > 0 && hitPoints > 0) 
    {
        std::cout << "ScavTrap " << this->name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!\n";
        energyPoints--;
    } 
    else 
    {
        std::cout << "ScavTrap " << this->name << " can't attack. Not enough energy or hit points." << std::endl;
    }
}

void ScavTrap::guardGate() 
{
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}