/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:26:48 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/12 14:27:48 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name) : ClapTrap(name) 
{
    std::cout << "FragTrap: " << this->name << " is created!" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::~FragTrap() 
{
    std::cout << "FragTrap: " << this->name << " is destroyed!" << std::endl;
}

void FragTrap::attack(const std::string& target) 
{
    if (this->energyPoints > 0 && this->hitPoints> 0) 
    {
        std::cout << "FragTrap: " << this->name << " attacks " << target 
                  << ", causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints = this->energyPoints - 1;
    } else 
    {
        std::cout << "FragTrap: " << this->name << " can't attack. Not enough energy or hit points." << std::endl;
    }
}

void FragTrap::highFivesGuys(void) 
{
    std::cout << "FragTrap: " << this->name << " enthusiastically requests high fives from everyone!" << std::endl;
}

void FragTrap::showStats() const 
{
    std::cout << "FragTrap " << name << " stats: "
              << "HP: " << hitPoints
              << " EP: " << energyPoints
              << " AD: " << attackDamage 
              << std::endl;
}