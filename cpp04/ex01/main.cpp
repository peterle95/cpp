/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:41:58 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/27 14:19:01 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

/*TASK OF THE PROGRAM
Constructors and destructors of each class must display specific messages.
Implement a Brain class. It contains an array of 100 std::string called ideas.
This way, Dog and Cat will have a private Brain* attribute.
Upon construction, Dog and Cat will create their Brain using new Brain();
Upon destruction, Dog and Cat will delete their Brain.
In your main function, create and fill an array of Animal objects. Half of it will
be Dog objects and the other half will be Cat objects. At the end of your program
execution, loop over this array and delete every Animal. You must delete directly dogs
and cats as Animals. The appropriate destructors must be called in the expected order.
Don’t forget to check for memory leaks.
A copy of a Dog or a Cat mustn’t be shallow. Thus, you have to test that your copies
are deep copies!

int main()
{
const Animal* j = new Dog();
const Animal* i = new Cat();
delete j;//should not create a leak
delete i;
...
return 0;
}
Implement and turn in more tests than the ones given above.*/

int main()
{
    std::cout << "=== Constructors ===" << std::endl;
    const int arraySize = 10;
    Animal* animals[arraySize];

    // Fill the array with Dogs and Cats
    for (int i = 0; i < arraySize; ++i) 
    {
        if (i % 2 == 0) 
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    
    std::cout << "\n=== Getting & Setting Ideas ===" << std::endl;
    Brain myBrain;
    std::cout << myBrain.getIdea(0) << std::endl;  // Will print "Empty idea"

    myBrain.setIdea(0, "Play fetch");
    std::cout << myBrain.getIdea(0) << std::endl;  // Will print "Play fetch"


    Brain copiedBrain(myBrain);
    
    copiedBrain.setIdea(5, "I'm a good boy!");
    std::cout << copiedBrain.getIdea(5) << std::endl;

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

    std::cout << "\n=== Delete dynamically allocated animal objects ===" << std::endl;
    // Delete all animals in the array
    for (int i = 0; i < arraySize; ++i) 
        delete animals[i];

    return 0;
}