/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:26:30 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/12 14:08:44 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

/*TASK OF THE PROGRAM
Making ClapTraps is probably starting to get on your nerves.
Now, implement a FragTrap class that inherits from ClapTrap. It is very similar to
ScavTrap. However, its construction and destruction messages must be different. Proper
construction/destruction chaining must be shown in your tests. When a FragTrap is
created, the program starts by building a ClapTrap. Destruction is in reverse order.
Same things for the attributes, but with different values this time:
•Name, which is passed as parameter to a constructor
•Hit points (100), represent the health of the ClapTrap
•Energy points (100)
•Attack damage (30)
FragTrap has a special capacity too:
void highFivesGuys(void);
This member function displays a positive high fives request on the standard output.*/


/* int main() 
{
    ClapTrap clap("clappy");
    ScavTrap scav("scavvy");
    FragTrap frag("fraggy");
    
    clap.attack("Enemy");
    clap.takeDamage(5);
    clap.beRepaired(3);
    
    scav.attack("Another Enemy");
    scav.takeDamage(20);
    scav.beRepaired(15);
    scav.guardGate();
    
    frag.attack("Big Enemy");
    frag.takeDamage(30);
    frag.beRepaired(25);
    frag.highFivesGuys();
    return 0;
} */

// ... existing code ...

int main() 
{
    // Test construction order
    std::cout << "\n=== Constructing ClapTraps ===" << std::endl;
    ClapTrap clap("\033[31mclappy\033[0m");
    ScavTrap scav("\033[31mscavvy\033[0m");
    FragTrap frag("\033[31mfraggy\033[0m");

    // Verify initial FragTrap stats
    std::cout << "\n=== Initial FragTrap Stats ===" << std::endl;
    frag.showStats();

    // Test basic functionality
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

    // Test energy depletion
    std::cout << "\n=== Energy Depletion Test ===" << std::endl;
    FragTrap energy_test("\033[31mEnergyTest\033[0m");
    for (int i = 0; i < 100; i++) 
    {
        energy_test.attack("\033[94mTarget Dummy\033[0m");
    }
    energy_test.attack("Should Fail");  // No energy left

    // Test destruction order with nested scope
    std::cout << "\n=== Construction/Destruction Order Test ===" << std::endl;
    {
        FragTrap temp("\033[31mTemporaryFrag\033[0m");
        temp.highFivesGuys();
    } // Destructor called here before main's frag

    // Test death and repair limitations
    std::cout << "\n=== Death and Repair Tests ===" << std::endl;
    FragTrap mortal("\033[31mMortalFrag\033[0m");
    mortal.takeDamage(100);  // Reduce HP to 0
    mortal.attack("\033[94mGhost\033[0m");  // Should fail
    mortal.beRepaired(50);   // Should fail
    mortal.highFivesGuys();  // Should still work (if allowed)

    // Test different attack values
    std::cout << "\n=== Class-Specific Attack Values ===" << std::endl;
    clap.attack("\033[94mEnemy\033[0m");  // 0 damage (ClapTrap default)
    scav.attack("\033[94mEnemy\033[0m");  // 20 damage (ScavTrap)
    frag.attack("\033[94mEnemy\033[0m");  // 30 damage (FragTrap)

    // Destruction order of main objects will be shown here
    std::cout << "\n=== Destroying Main Objects ===" << std::endl;
    return 0;
}