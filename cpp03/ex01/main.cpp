/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:19:15 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/14 15:43:35 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() 
{
    std::cout << "BASIC FUNCTIONALITY TEST\n";
    
    // Basic object lifecycle
    ScavTrap scav("\033[31mscavvy\033[0m");
    ClapTrap* base = &scav;

    std::cout << "\nCreated ScavTrap with 100 HP, 50 EP, 20 AD\n";
    
    // Single attack with or without virtual implementation
    scav.attack("\033[34mEnemy\033[0m"); 
    base->attack("\033[34mAnother Enemy\033[0m"); 
    
    scav.takeDamage(30);
    scav.beRepaired(15);
    
    scav.guardGate();

    return 0;
}
