/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:16:03 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/09 13:53:41 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// This function creates a Zombie object with the given name and announces its presence.
void randomChump(std::string name) 
{
    Zombie zombie(name); // Create a Zombie object named 'zombie' and initialize it with the provided name.
    zombie.announce(); // Call the announce method on the 'zombie' object to print its name and sound.
}