/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:15:45 by pmolzer           #+#    #+#             */
/*   Updated: 2024/12/05 16:29:44 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

// The Zombie class represents a zombie with a name and provides functionality to announce itself.
 class Zombie 
{
private:
    std::string name; // The name of the zombie, stored as a string.

public:
    Zombie(std::string name); // Constructor that initializes the zombie with a given name.
    ~Zombie(); // Destructor that cleans up when a zombie object is destroyed.
    void announce(void); // Method that allows the zombie to announce itself.
};

// This function prototype declares a function that creates a new Zombie on the heap with a given name.
Zombie* newZombie(std::string name); // Function to create a Zombie and return its pointer.
// This function prototype declares a function that creates a Zombie on the stack and announces itself.
void randomChump(std::string name); // Function to create a Zombie and make it announce itself.

#endif