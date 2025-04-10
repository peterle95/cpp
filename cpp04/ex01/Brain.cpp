/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:43:09 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/27 12:23:03 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain() 
{
    std::cout << "\033[94mBrain\033[0m constructor called" << std::endl;
    for (int i = 0; i < 100; ++i) 
    {
        ideas[i] = "Empty idea";
    }
}

Brain::Brain(const Brain& other) 
{
    std::cout << "\033[94mBrain\033[0m copy constructor called" << std::endl;
    for (int i = 0; i < 100; ++i) 
    {
        ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other) 
{
    std::cout << "\033[94mBrain\033[0m assignment operator called" << std::endl;
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
    std::cout << "\033[94mBrain\033[0m destructor called" << std::endl;
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