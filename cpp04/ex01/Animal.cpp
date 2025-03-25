/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:11:03 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/25 17:23:09 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
    this->type = "Animal";
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) 
{
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) 
{
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &other) 
    {
        type = other.type;
    }
    return *this;
}

Animal::~Animal() 
{
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const 
{
    std::cout << "Animal makes a generic sound" << std::endl;
}

std::string Animal::getType() const 
{
    return type;
}

