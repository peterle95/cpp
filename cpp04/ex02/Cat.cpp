/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:42:50 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/27 17:10:19 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : brain(new Brain()) 
{
    type = "Cat";
    std::cout << "\033[31mCat\033[0m constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other), brain(new Brain(*other.brain)) 
{
    std::cout << "\033[31mCat\033[0m copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) 
{
    std::cout << "\033[31mCat\033[0m assignment operator called" << std::endl;
    if (this != &other) 
    {
        AAnimal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() 
{
    delete brain;
    std::cout << "\033[31mCat\033[0m destructor called" << std::endl;
}

void Cat::makeSound() const 
{
    std::cout << "Meow! Meow!" << std::endl;
}