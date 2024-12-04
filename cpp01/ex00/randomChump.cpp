/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:16:03 by pmolzer           #+#    #+#             */
/*   Updated: 2024/12/04 15:22:29 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// This function creates a Zombie object with the given name and announces its presence.
void randomChump(std::string name) 
{
    Zombie zombie(name); // Create a Zombie object named 'zombie' and initialize it with the provided name.
    zombie.announce(); // Call the announce method on the 'zombie' object to print its name and sound.
    // The Zombie object is created on the stack, which means it will be automatically destroyed when it goes out of scope. 
    // This is different from creating an object on the heap, which requires manual memory management and must be deleted explicitly.
    // We decided to use a stack allocation for the Zombie object here because it simplifies memory management. 
    // Stack-allocated objects are automatically destroyed when they go out of scope, reducing the risk of memory leaks 
    // that can occur with heap-allocated objects, which require explicit deletion. This makes the code safer and easier to maintain.
}