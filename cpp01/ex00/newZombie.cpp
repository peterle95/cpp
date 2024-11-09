/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:15:56 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/09 11:36:04 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* 
 * Creates a new Zombie object on the heap with the given name.
 * Returns a pointer to the newly created Zombie.
 */
Zombie* newZombie(std::string name) 
{
    // Allocate a new Zombie object on the heap and initialize it with the provided name
    return new Zombie(name);
}

/*The function newZombie takes a std::string parameter called name.
It creates a new instance of the Zombie class on the heap using the 
new operator, passing the name to the Zombie constructor.
The function returns a pointer to the newly created Zombie object, 
allowing the caller to interact with it.*/