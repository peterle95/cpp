/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:23:39 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/05 17:22:37 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) 
// This explicitly calls the base class constructor first before executing ScavTrap's constructor body
{
    std::cout << "ScavTrap " << name << " is created!" << std::endl;
    hitPoints = 100;    // Direct access
    energyPoints = 50;  // Direct access 
    attackDamage = 20;  // Direct access
}

ScavTrap::~ScavTrap()
// Destructors are called in reverse order of construction (derived class first, then base class)
{
    std::cout << "ScavTrap " << name << " is destroyed!" << std::endl;
}

/* 
* Attack method demonstrates three name access approaches:
* 1. 'name' - Implicit member access (works when no parameter shadowing)
*    Explanation: Name shadowing occurs when a local variable or parameter has the same name as a class member.
*    In such a case, the local variable shadows the member variable, 
*    meaning that unqualified access (using just 'name')
*    will refer to the local variable instead of the intended class member.
* 2. 'this->name' - Explicit member access (safe with shadowed names)
* 3. 'ClapTrap::name' - Qualified base class access (explicit inheritance)
* All resolve to same member when no shadowing exists, but explicit forms
* are preferred for code clarity and maintenance
*/
void ScavTrap::attack(const std::string& target) 
{
    if (energyPoints > 0 && hitPoints > 0) {
        std::cout << "ScavTrap " << name << this->name << ClapTrap::name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!\n";
        energyPoints--;
    } else 
    {
        std::cout << "ScavTrap " << name << " can't attack. Not enough energy or hit points." << std::endl;
    }
}

/* void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
} */

void ScavTrap::guardGate() {
    std::string name = "Temporary";  // Now name refers to local variable
    std::cout << name << std::endl;               // Prints "Temporary"
    std::cout << this->name << std::endl;         // Still accesses ClapTrap::name
}