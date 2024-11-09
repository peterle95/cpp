/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:15:50 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/09 13:53:06 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

// Constructor for the Zombie class that initializes the zombie's name.
Zombie::Zombie(std::string name) : name(name) {} // Initialize the name member variable with the provided name.

// Destructor for the Zombie class that outputs a message when a zombie is destroyed.
Zombie::~Zombie() 
{
    std::cout << name << " is destroyed." << std::endl; // Print a message indicating the zombie's name and that it is being destroyed.
}

// Method for the Zombie class that announces the zombie's presence.
void Zombie::announce(void) 
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl; // Print the zombie's name followed by its characteristic sound.
}