/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:07:39 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/13 14:47:39 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

/*TASK OF THE PROGRAM:
First, you have to implement a class! How original!
It will be called ClapTrap and will have the following private attributes initialized
to the values specified in brackets:
•Name, which is passed as parameter to a constructor
•Hit points (10), represent the health of the ClapTrap
•Energy points (10)
•Attack damage (0)
Add the following public member functions so the ClapTrap looks more realistic:
•void attack(const std::string& target);
•void takeDamage(unsigned int amount);
•void beRepaired(unsigned int amount);
When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
When ClapTrap repairs itself, it gets <amount> hit points back. Attacking and repairing
cost 1 energy point each. Of course, ClapTrap can’t do anything if it has no hit points
or energy points left.

In all of these member functions, you have to print a message to describe what hap-
pens. For example, the attack() function may display something like (of course, without
the angle brackets):
ClapTrap <name> attacks <target>, causing <damage> points of damage!
The constructors and destructor must also display a message, so your peer-evaluators
can easily see they have been called.
Implement and turn in your own tests to ensure your code works as expected.
*/

int main() 
{
    ClapTrap clap("Clappy");
    ClapTrap clap2("Clappy2");  // Uncommented second instance
    
    // Initial functioning tests
    clap.attack("Enemy");
    clap.attack("Some Enemy");
    clap.takeDamage(5);
    clap.beRepaired(3);

    // Energy depletion tests
    for (int i = 0; i < 8; i++) {  // Already used 2 energy, 8 remaining
        clap.attack("Energy Drain Target");
    }
    clap.attack("Should Fail Attack");  // Should fail (no energy)
    
    // Hit points exhaustion tests
    clap.takeDamage(8);  // Should reduce to 0 HP (3 remaining after repair - 8 damage)
    clap.beRepaired(3);  // Should fail (no HP left)
    clap.attack("Dead Trap");  // Should fail (no HP)

    // Second instance tests
    clap2.attack("Another Enemy");  // Should work independently
    clap2.takeDamage(15);  // Should set HP to 0
    clap2.beRepaired(5);  // Should fail (no HP)

    return 0;
}