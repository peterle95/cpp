/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:23:41 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/12 09:23:06 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// This function creates a horde of N Zombies and assigns them a given name.
Zombie* zombieHorde(int N, std::string name) 
{
    Zombie *horde = new Zombie[N]; // Dynamically allocate an array of N Zombies.
    
    for (int i = 0; i < N; ++i) 
    { // Loop through each Zombie in the horde.
        horde[i].setName(name); // Set the name of the current Zombie to the provided name.
    }
    
    return horde; // Return the pointer to the array of Zombies.
}