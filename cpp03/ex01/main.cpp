/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:19:15 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/12 13:00:10 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() 
{
    std::cout << "BASIC FUNCTIONALITY TEST\n";
    
    // Test 1: Basic object lifecycle
    ScavTrap scav("\033[31mscavvy\033[0m");
    ClapTrap* base = &scav;

    std::cout << "\nCreated ScavTrap with 100 HP, 50 EP, 20 AD\n";
    
    // Test 2: Single attack
    scav.attack("\033[34mEnemy\033[0m"); 
    base->attack("\033[34mAnother Enemy\033[0m"); 
    
    // Test 3: Take damage and repair
    scav.takeDamage(30);
    scav.beRepaired(15);
    
    // Test 4: Special ability
    scav.guardGate();
    
    // Test 5: Verify destruction order
    ClapTrap *ptr = new ScavTrap("\033[31mPointerTest\033[0m");
    delete ptr;

    return 0;
}
