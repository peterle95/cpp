/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:20:18 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/27 17:09:48 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain() 
{
    std::cout << "\033[94mBrain\033[0m constructor called" << std::endl;
}

Brain::Brain(const Brain& other) 
{
    std::cout << "\033[94mBrain\033[0m copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++) 
    {
        this->ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other) 
{
    std::cout << "\033[94mBrain\033[0m assignment operator called" << std::endl;
    if (this != &other) 
    {
        for (int i = 0; i < 100; i++) 
        {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() 
{
    std::cout << "\033[94mBrain\033[0m destructor called" << std::endl;
}
