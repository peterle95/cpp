/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:41:58 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/07 16:02:30 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    const int arraySize = 10;
    Animal* animals[arraySize];

    // Fill the array with Dogs and Cats
    for (int i = 0; i < arraySize; ++i) 
    {
        if (i % 2 == 0) 
        {
            animals[i] = new Dog();
        } else 
        {
            animals[i] = new Cat();
        }
    }

    // Test deep copy
    Dog* originalDog = new Dog();
    Dog* copiedDog = new Dog(*originalDog);

    // Delete the original dog
    delete originalDog;

    // The copied dog should still be valid and have its own Brain
    copiedDog->makeSound();

    // Clean up
    delete copiedDog;

    // Delete all animals in the array
    for (int i = 0; i < arraySize; ++i) 
    {
        delete animals[i];
    }

    return 0;
}