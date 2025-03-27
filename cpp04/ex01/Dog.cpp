/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:42:30 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/27 12:23:47 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

/*Subject: Upon construction, Dog and Cat will create their Brain using new Brain();
Upon destruction, Dog and Cat will delete their Brain.*/
Dog::Dog() : brain(new Brain()) 
{
    type = "Dog";
    std::cout << "\033[92mDog\033[0m constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) 
{
    std::cout << "\033[92mDog\033[0m copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) 
{
    std::cout << "\033[92mDog\033[0m assignment operator called" << std::endl;
    if (this != &other) 
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() 
{
    delete brain;
    std::cout << "\033[92mDog\033[0m destructor called" << std::endl;
}

void Dog::makeSound() const 
{
    std::cout << "Woof! Woof!" << std::endl;
}