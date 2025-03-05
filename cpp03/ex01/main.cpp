/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:19:15 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/05 11:40:06 by pmolzer          ###   ########.fr       */
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

int main() 
{
    separator();
    std::cout << "BASIC FUNCTIONALITY TEST\n";
    
    // Test 1: Basic object lifecycle
    ScavTrap scav("\033[31mscavvy\033[0m");
    std::cout << "\nCreated ScavTrap with 100 HP, 50 EP, 20 AD\n";
    
    // Test 2: Single attack
    scav.attack("\033[31mEnemy\033[0m");
    
    // Test 3: Take damage and repair
    scav.takeDamage(30);
    scav.beRepaired(15);
    
    // Test 4: Special ability
    scav.guardGate();
    
    // Test 5: Verify destruction order
    ClapTrap *ptr = new ScavTrap("\033[31mPointerTest\033[0m");
    delete ptr;

    separator();
    return 0;
}
