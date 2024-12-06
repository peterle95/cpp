/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:47:39 by pmolzer           #+#    #+#             */
/*   Updated: 2024/12/06 16:11:16 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 * HumanA.cpp
 * 
 * This source file implements the HumanA class, which represents a human character 
 * that is always armed with a weapon. The class includes a constructor for initializing 
 * the human's name and weapon, as well as a method for performing an attack. 
 * This file works in conjunction with the Weapon class to demonstrate the interaction 
 * between humans and weapons in the program.
 */

#include "HumanA.hpp" /* Include the header file for the HumanA class definition */
#include <iostream> /* Include the iostream library for input and output operations */

/* 
 * Constructor for the HumanA class.
 * Initializes a HumanA object with a given name and a reference to a Weapon object.
 * 
 * Syntax Explanation:
 * The constructor uses an initializer list to initialize the member variables:
 * - `name(name)`: This initializes the member variable `name` with the value of the parameter `name`.
 * - `weapon(weapon)`: This initializes the member variable `weapon` with the reference to the passed Weapon object.
 */
HumanA::HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon) {}

/* 
 * Method to perform an attack.
 * Displays a message indicating the attack and the type of weapon used.
 */
void HumanA::attack() const 
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl; /* Output the attack message with weapon type */
}