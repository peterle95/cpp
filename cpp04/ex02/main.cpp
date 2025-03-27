/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:47:07 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/27 17:13:12 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

/*TASK OF THE PROGRAM
Creating Animal objects doesn’t make sense after all. It’s true, they make no sound!
To avoid any possible mistakes, the default Animal class should not be instantiable.
Fix the Animal class so that nobody can instantiate it. Everything should work as before.
If you want to, you can update the class name by adding an A prefix to Animal.
*/


int main()
{
    std::cout << "=== Constructors ===" << std::endl;
   //AAnimal Animal;// This should not compile now

    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    std::cout << "\n=== Polymorphism ===" << std::endl;
    j->makeSound();
    i->makeSound();

    delete j;
    delete i;

     std::cout << "\n=== Deep copy ===" << std::endl;
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