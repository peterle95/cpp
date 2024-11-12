/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:47:07 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/12 09:17:15 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

/*TASK OF THE PROGRAM*/


int main()
{
    // Animal* meta = new Animal(); // This should not compile now

    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    j->makeSound();
    i->makeSound();

    delete j;
    delete i;

    // Test deep copy
    Dog* originalDog = new Dog();
    Dog* copiedDog = new Dog(*originalDog);

    // Delete the original dog
    delete originalDog;

    // The copied dog should still be valid and have its own Brain
    copiedDog->makeSound();

    // Clean up
    delete copiedDog;

    return 0;
}