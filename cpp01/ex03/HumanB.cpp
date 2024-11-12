/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:47:47 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/12 09:23:49 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 * HumanB.cpp
 * 
 * This source file implements the HumanB class, which represents a human character 
 * that can wield a weapon. The class allows for the dynamic assignment of weapons 
 * and includes methods for setting a weapon and performing an attack. 
 * This file works in conjunction with the Weapon class and the HumanA class 
 * to demonstrate the interaction between humans and weapons in the program.
 */

#include "HumanB.hpp" /* Include the header file for the HumanB class definition */
#include <iostream> /* Include the iostream library for input and output operations */

/* 
 * Constructor for the HumanB class.
 * Initializes a HumanB object with a given name and sets the weapon pointer to nullptr.
 */
HumanB::HumanB(const std::string& name) : name(name), weapon(nullptr) {}

// The constructor uses an initializer list to set the member variables. 
// The syntax `name(name)` initializes the member variable `name` with the value of the parameter `name`.
// The syntax `weapon(nullptr)` initializes the pointer `weapon` to a null pointer, indicating that the HumanB object starts without a weapon.
// The empty curly braces `{}` at the end of the constructor indicate the body of the constructor. 
// In this case, the body is empty because all initialization is done in the initializer list, 
// and there are no additional statements to execute when the constructor is called.

/* 
 * Method to set the weapon for this HumanB object.
 * Takes a reference to a Weapon object and assigns it to the weapon pointer.
 */
void HumanB::setWeapon(Weapon& newWeapon) 
{
    weapon = &newWeapon; /* Assign the address of the newWeapon to the weapon pointer */
}

/* 
 * Method to perform an attack.
 * Displays a message indicating the attack and the type of weapon used, 
 * or a message indicating that the human has no weapon if none is assigned.
 */
void HumanB::attack() const 
{
    if (weapon) 
    { /* Check if the weapon pointer is not NULL */
        std::cout << name << " attacks with their " << weapon->getType() << std::endl; /* Output the attack message with weapon type */
    } else 
    {
        std::cout << name << " has no weapon to attack with" << std::endl; /* Output a message indicating no weapon */
    }
}