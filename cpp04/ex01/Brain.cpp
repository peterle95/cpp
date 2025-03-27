/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:43:09 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/27 13:08:28 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

/*Purpose:

Initialize the ideas array with default values
Ensure each Brain starts with consistent, known state
Prevent undefined behavior by explicitly setting array contents

Relation to code:

Called when Dog or Cat objects are created
Prepares the Brain's memory space for potential idea storage
Part of object initialization process

Each Cat and Dog object contains a Brain pointer that points to a dynamically allocated Brain object. 
This Brain object has a fixed-size array of 100 ideas (std::string), initialized to "Empty idea" by default.
So when you create a Dog or Cat, it gets its own Brain with 100 potential idea slots, 
which can be individually set and retrieved using setIdea() and getIdea() methods.
This design allows each animal to have its own independent "thought storage" of up to 100 ideas
*/
Brain::Brain() 
{
    std::cout << "Brain constructor called" << std::endl;
    for (int i = 0; i < 100; ++i) 
    {
        ideas[i] = "Empty idea";
    }
}

Brain::Brain(const Brain& other) 
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; ++i) 
    {
        ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other) 
{
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &other) 
    {
        for (int i = 0; i < 100; ++i) 
        {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() 
{
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea) 
{
    if (index >= 0 && index < 100) 
    {
        ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index) const 
{
    if (index >= 0 && index < 100) 
    {
        return ideas[index];
    }
    return "";
}