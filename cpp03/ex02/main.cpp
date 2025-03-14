/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:26:30 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/14 15:44:38 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() 
{
    ClapTrap clap("\033[31mclappy\033[0m");
    ScavTrap scav("\033[31mscavvy\033[0m");
    FragTrap frag("\033[31mfraggy\033[0m");

    std::cout << "\n=== Initial FragTrap Stats ===" << std::endl;
    frag.showStats();

    std::cout << "\n=== Basic Functionality Tests ===" << std::endl;
    clap.attack("\033[94mEnemy\033[0m");
    clap.takeDamage(5);
    clap.beRepaired(3);
    
    scav.attack("\033[94mAnother Enemy\033[0m");
    scav.takeDamage(20);
    scav.beRepaired(15);
    scav.guardGate();
    
    frag.attack("\033[94mBig Enemy\033[0m");
    frag.takeDamage(30);
    frag.beRepaired(25);
    frag.highFivesGuys();

    std::cout << "\n=== Energy Depletion Test ===" << std::endl;
    FragTrap energy_test("\033[31mEnergyTest\033[0m");
    for (int i = 0; i < 100; i++) 
    {
        energy_test.attack("\033[94mTarget Dummy\033[0m");
    }
    energy_test.attack("\033[94mShould Fail\033[0m");

    std::cout << "\n=== Death and Repair Tests ===" << std::endl;
    FragTrap mortal("\033[31mMortalFrag\033[0m");
    mortal.takeDamage(100);  
    mortal.attack("\033[94mGhost\033[0m");  
    mortal.beRepaired(50);   
    mortal.highFivesGuys();  

    std::cout << "\n=== Class-Specific Attack Values ===" << std::endl;
    clap.attack("\033[94mEnemy\033[0m");  
    scav.attack("\033[94mEnemy\033[0m");  
    frag.attack("\033[94mEnemy\033[0m");  

    std::cout << "\n=== Destroying Main Objects ===" << std::endl;
    return 0;
}