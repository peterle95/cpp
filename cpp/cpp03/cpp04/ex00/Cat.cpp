/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:37:55 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/07 15:57:46 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() 
{
    type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) 
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) 
{
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) 
    {
        Animal::operator=(other);
    }
    return *this;
}

Cat::~Cat() 
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const 
{
    std::cout << "Meow! Meow!" << std::endl;
}