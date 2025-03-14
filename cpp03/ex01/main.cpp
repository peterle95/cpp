/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:19:15 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/14 15:53:52 by pmolzer          ###   ########.fr       */
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
    // Here we declare a pointer of type ClapTrap*, which is a base class pointer, 
    // and assign it the address of the derived object 'scav' (an instance of ScavTrap).
    // This approach is used when you want to leverage polymorphism: by handling a 
    // derived object through its base class interface,
    // you can write code that operates on a variety of derived types uniformly.
    // For example, if the methods in ClapTrap were declared as virtual (e.g., attack()), 
    // calling these methods through the base
    // pointer would result in dynamic dispatch, invoking the overridden functions in ScavTrap at runtime.
    // This technique is particularly beneficial for managing collections of 
    // objects and if dynamic binding is required,
    // as it facilitates flexible code reuse and consistent memory 
    // management (especially when paired with virtual destructors).
    ClapTrap* base = &scav;

    std::cout << "\nCreated ScavTrap with 100 HP, 50 EP, 20 AD\n";
    
    // Test 2: Single attack
    scav.attack("\033[34mEnemy\033[0m"); // Calls ScavTrap::attack
    base->attack("\033[34mAnother Enemy\033[0m");
    // We use the 'base' pointer (of type ClapTrap*) to call the attack() method.
    // Although 'base' actually points to a ScavTrap object, the attack() method in ClapTrap is not virtual.
    // Because of this, the compiler binds the method call at compile time to ClapTrap::attack, not ScavTrap::attack.
    // In contrast, if attack() were declared as virtual in ClapTrap, the call would be dynamically dispatched,
    // and the overridden ScavTrap::attack() would be executed based on the actual object's type at runtime.
    // Dynamically dispatched means that if attack() were declared as virtual in ClapTrap, the decision about which function
    // to execute would be made at runtime based on the actual type of the object (in this case, ScavTrap).
    // This runtime decision process—determining the correct overridden method to call—is what is known as dynamic dispatch,
    // a fundamental mechanism in achieving polymorphism.
    // "At runtime" means that the decision of which method to call is made while the program is executing, not during compilation.
    // This is crucial for dynamic dispatch: if attack() were declared as virtual in ClapTrap, 
    // the program would, at runtime, determine the actual type of the object (in this case, ScavTrap)
    // and select the correct overridden method to execute. This runtime decision process is key to achieving polymorphism.

    
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
