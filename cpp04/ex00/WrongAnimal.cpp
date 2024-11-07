/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:38:12 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/07 15:58:18 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("WrongAnimal") 
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) 
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) 
{
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    if (this != &other) 
    {
        type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() 
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const 
{
    std::cout << "WrongAnimal makes a wrong sound" << std::endl;
}

std::string WrongAnimal::getType() const 
{
    return type;
}