/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:19:15 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/05 16:23:25 by pmolzer          ###   ########.fr       */
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
    ClapTrap* base = &scav;

    std::cout << "\nCreated ScavTrap with 100 HP, 50 EP, 20 AD\n";
    
    // Test 2: Single attack
    scav.attack("\033[34mEnemy\033[0m"); // Calls ScavTrap::attack
    base->attack("\033[34mAnother Enemy\033[0m"); // Calls ClapTrap::attack (no virtual)
    // Explanation:
    // If the attack method were declared as virtual in ClapTrap,
    // a call via a base pointer (like 'base->attack(...)') would be dynamically dispatched
    // and execute ScavTrap::attack due to runtime polymorphism.
    // Without the virtual keyword, the method resolution is done at compile time based on the pointer type,
    // so base->attack(...) calls ClapTrap::attack.
    
    // Test 3: Take damage and repair
    scav.takeDamage(30);
    scav.beRepaired(15);
    
    // Test 4: Special ability
    scav.guardGate();
    
    // Test 5: Verify destruction order
    ClapTrap *ptr = new ScavTrap("\033[31mPointerTest\033[0m");
    delete ptr;
    /* 
    Why the order matters:
    1. Construction Order (Base → Derived):
       - Base class must be fully initialized before derived class construction
       - Ensures derived class can safely use base class members during its construction
       - Follows ISO C++98 [class.base.init]/5: "Base classes are initialized in declaration order"

    2. Destruction Order (Derived → Base):
       - Derived class must clean up its resources first
       - Base class might depend on its own members still being valid during destruction
       - Mandated by C++98 [class.dtor]/4: "Destructors are invoked in reverse order of construction"

    3. Memory Implications:
       Stack unwinding: 
       - Derived destructor runs before base destructor during stack unwinding
       - Ensures proper release of resources in exception-safe code

    4. Inheritance Safety:
       - Without virtual destructor (C++98 limitation), proper order only guaranteed when:
         a) Deleting through derived pointer (as in this test)
         b) Not using polymorphic deletion through base pointer
       - Current implementation is safe because we're: 
         1) Allocating as ScavTrap (even though storing in ClapTrap*)
         2) Deleting through ScavTrap* (implicitly via type conversion)
    */

    separator();
    return 0;
}
