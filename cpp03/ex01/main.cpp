/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:19:15 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/04 15:07:00 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

/*TASK OF THE PROGRAM:
Because you can never have enough ClapTraps, you will now create a derived robot.
It will be named ScavTrap and will inherit the constructors and destructor from Clap-
Trap. However, its constructors, destructor and attack() will print different messages.
After all, ClapTraps are aware of their individuality.
Note that proper construction/destruction chaining must be shown in your tests.
When a ScavTrap is created, the program starts by building a ClapTrap. Destruction is
in reverse order. Why?
ScavTrap will use the attributes of ClapTrap (update ClapTrap in consequence) and
must initialize them to:
•Name, which is passed as parameter to a constructor
•Hit points (100), represent the health of the ClapTrap
•Energy points (50)
•Attack damage (20)
ScavTrap will also have its own special capacity:
void guardGate();
This member function will display a message informing that ScavTrap is now in Gate
keeper mode.
Don't forget to add more tests to your program*/

static void separator() {
    std::cout << "\n\033[36m************************************\033[0m\n" << std::endl;
}

/* int main() 
{
    separator();
    std::cout << "1. Testing Construction/Destruction Order:\n";
    {
        ScavTrap *scav = new ScavTrap("ConstructorTest");
        delete scav;
    }

    separator();
    std::cout << "2. Testing Initial Values:\n";
    ScavTrap scav("Scavy");
    std::cout << "Initial Hit Points: " << scav.getHitPoints() << " (should be 100)\n";
    std::cout << "Initial Energy Points: " << scav.getEnergyPoints() << " (should be 50)\n";
    std::cout << "Initial Attack Damage: " << scav.getAttackDamage() << " (should be 20)\n";

    separator();
    std::cout << "3. Testing Energy Point Depletion:\n";
    for (int i = 0; i < 52; i++) {
        std::cout << "Attack #" << (i+1) << ": ";
        scav.attack("Dummy");
    }

    separator();
    std::cout << "4. Testing Hit Point Management:\n";
    scav.takeDamage(99);
    scav.takeDamage(5);
    scav.beRepaired(50);
    scav.takeDamage(150);

    separator();
    std::cout << "5. Testing ClapTrap/ScavTrap Differentiation:\n";
    ClapTrap *poly = new ScavTrap("PolymorphTest");
    poly->attack("Target");
    delete poly;

    separator();
    std::cout << "6. Testing Gate Keeper Mode:\n";
    scav.guardGate();
    
    separator();
    return 0;
} */

int main() 
{
    separator();
    std::cout << "BASIC FUNCTIONALITY TEST\n";
    
    // Test 1: Basic object lifecycle
    ScavTrap basic("SimpleScav");
    std::cout << "\nCreated ScavTrap with 100 HP, 50 EP, 20 AD\n";
    
    // Test 2: Single attack
    basic.attack("Training Dummy");
    
    // Test 3: Take damage and repair
    basic.takeDamage(30);
    basic.beRepaired(15);
    
    // Test 4: Special ability
    basic.guardGate();
    
    // Test 5: Verify destruction order
    ClapTrap *ptr = new ScavTrap("PointerTest");
    delete ptr;

    separator();
    return 0;
}
