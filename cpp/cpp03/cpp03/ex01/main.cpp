/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:19:15 by pmolzer           #+#    #+#             */
/*   Updated: 2025/02/27 10:43:13 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

/*TASK OF THE PROGRAM

Because you can never have enough ClapTraps, you will now create a derived robot.
It will be named ScavTrap and will inherit the constructors and destructor from ClapTrap. 
However, its constructors, destructor and attack() will print different messages.
After all, ClapTraps are aware of their individuality.
Note that proper construction/destruction chaining must be shown in your tests.
When a ScavTrap is created, the program starts by building a ClapTrap. Destruction is
in reverse order. Why?
ScavTrap will use the attributes of ClapTrap (update ClapTrap in consequence) and
must initialize them to:
• Name, which is passed as parameter to a constructor
• Hit points (100), represent the health of the ClapTrap
• Energy points (50)
• Attack damage (20)
ScavTrap will also have its own special capacity:
void guardGate();
This member function will display a message informing that ScavTrap is now in Gate
keeper mode.
Don’t forget to add more tests to your program.*/


int main() 
{
    ClapTrap clap("CL4P-TP");
    ScavTrap scav("SC4V-TP");
    
    clap.attack("Enemy");
    clap.takeDamage(5);
    clap.beRepaired(3);
    
    scav.attack("Another Enemy");
    scav.takeDamage(20);
    scav.beRepaired(15);
    scav.guardGate();
    // Don’t forget to add more tests to your program.
    return 0;
}