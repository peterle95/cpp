/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:23:32 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/12 09:22:46 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

// Default constructor for the Zombie class, initializes the name to an empty string.
Zombie::Zombie() : name("") {} // Initializes the name member variable to an empty string.

// Constructor that takes a string parameter to set the name of the Zombie.
Zombie::Zombie(std::string name) : name(name) {} // Initializes the name member variable with the provided name.

// Destructor for the Zombie class, outputs a message when a Zombie is destroyed.
Zombie::~Zombie() 
{
    std::cout << name << " has been destroyed." << std::endl; // Prints a message indicating the Zombie's name before destruction.
}

// Method to announce the Zombie's presence with its name.
void Zombie::announce() const 
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl; // Outputs the Zombie's name followed by its characteristic sound.
}

// Method to set the name of the Zombie.
void Zombie::setName(const std::string& newName) 
{
    name = newName; // Assigns the provided newName to the name member variable.
}