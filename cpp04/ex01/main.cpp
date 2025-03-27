/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:41:58 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/27 13:24:49 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

/*TASK OF THE PROGRAM*/

int main()
{
    /*In this code, `Animal* animals[arraySize]` creates an array of pointers to `Animal` objects because:

    1. Polymorphic behavior: It allows storing different derived types (Dog and Cat) in the same 
    array through base class pointers.
    
    2. Dynamic allocation: Each array element can point to dynamically created objects using `new`.
    
    This enables runtime polymorphism, where you can create and manipulate different animal 
    types through a common base class pointer, calling the correct derived class methods 
    (like `makeSound()`) polymorphically.
    
    The code demonstrates this by alternating between creating Dogs and Cats: 
    if (i % 2 == 0) 
        animals[i] = new Dog();
    else
        animals[i] = new Cat();
    */
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
    /*
    For stack-allocated objects like myBrain and copiedBrain, you do not need to use delete. 
    The destructor will be automatically called when these objects go out of scope.
    delete is only necessary for dynamically allocated objects created with new, like in 
    the main code where Dog and Cat create a Brain* using new Brain(). Those require explicit 
    deletion to prevent memory leaks.*/
    Brain myBrain;
    std::cout << myBrain.getIdea(0) << std::endl;  // Will print "Empty idea"

    myBrain.setIdea(5, "Play fetch");
    std::cout << myBrain.getIdea(5) << std::endl;  // Will print "Play fetch"
    std::cout << myBrain.getIdea(0) << std::endl;


    Brain copiedBrain(myBrain);
    
    copiedBrain.setIdea(5, "I'm a good boy!");
    std::cout << copiedBrain.getIdea(5) << std::endl;
    /*This code snippet demonstrates deep copying and proper memory management 
    for a Dog object. Let's break it down:

    1. `Dog* originalDog = new Dog();`
       - Creates a new Dog object dynamically
       - Allocates memory for the Dog and its Brain
    
    2. `Dog* copiedDog = new Dog(*originalDog);`
       - Creates a new Dog object by calling the copy constructor
       - Makes a deep copy of the original Dog's Brain
       - This ensures `copiedDog` has its own independent Brain, not just a pointer to the same Brain
    
    3. `delete originalDog;`
       - Deallocates memory for the original Dog
       - Calls the Dog destructor, which deletes the Dog's Brain
    
    4. `copiedDog->makeSound();`
       - Demonstrates that the copied Dog is still valid after the original is deleted
       - Shows that the deep copy worked correctly
    
    5. `delete copiedDog;`
       - Deallocates memory for the copied Dog
       - Calls the Dog destructor, which deletes the copied Dog's Brain
    
    The key point is that the deep copy ensures each Dog object has its own independent Brain, 
    preventing issues like double deletion or dangling pointers.*/
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