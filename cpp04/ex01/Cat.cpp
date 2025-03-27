/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:42:50 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/26 17:01:55 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() // : brain(new Brain()) this is theoretically better
{
    this->brain = new Brain();
    // Brain* brain = new Brain(); // This creates a *local* variable named 'brain' and is wrong
    type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) 
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) 
{
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) 
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() 
{
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const 
{
    std::cout << "Meow! Meow!" << std::endl;
}