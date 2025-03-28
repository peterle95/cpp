/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:11:03 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/28 15:20:17 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
    this->type = "Animal";
    std::cout << "Animal constructor called" << std::endl;
}

/*Syntax breakdown:

Takes a constant reference to another Animal object as parameter
Uses member initializer list : type(other.type) to directly initialize the type member
Copies the type from the source object
Prints a constructor call message

Key points:

Performs a shallow copy of the type member
Creates a new Animal object with the same type as the source object
Simple implementation that directly transfers the type attribute

The copy constructor ensures that when an Animal object is copied, its type is preserved in the new instance.*/
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

