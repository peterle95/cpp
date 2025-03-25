/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:36:56 by pmolzer           #+#    #+#             */
/*   Updated: 2025/03/25 17:52:04 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

/*TASK OF THE PROGRAM
For every exercise, you have to provide the most complete tests you can.
Constructors and destructors of each class must display specific messages. Don’t use the
same message for all classes.
Start by implementing a simple base class called Animal. It has one protected
attribute:
• std::string type;
Implement a Dog class that inherits from Animal.
Implement a Cat class that inherits from Animal.
These two derived classes must set their type field depending on their name. Then,
the Dog’s type will be initialized to "Dog", and the Cat’s type will be initialized to "Cat".
The type of the Animal class can be left empty or set to the value of your choice.
Every animal must be able to use the member function:
makeSound()
It will print an appropriate sound (cats don’t bark).

Running this code should print the specific sounds of the Dog and Cat classes, not
the Animal’s.
int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
...
return 0;
}
To ensure you understood how it works, implement a WrongCat class that inherits
from a WrongAnimal class. If you replace the Animal and the Cat by the wrong ones
in the code above, the WrongCat should output the WrongAnimal sound.
Implement and turn in more tests than the ones given above.
*/


int main()
{
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    /*
    - Creates a pointer to a base class (Animal*)
    - Points to a dynamically allocated derived class object (new Dog())
    - const prevents modifying the object through this pointer
    - virtual methods enable polymorphic behavior
    - Allows calling derived class methods through base class pointer
    - Enables runtime polymorphism
    - The destructor must also be virtual to ensure proper deletion of derived class objects
    
    This syntax allows you to:
    
    - Use base class interface
    - Override specific methods in derived classes
    - Achieve polymorphic behavior
    - Provide a common interface for different types of objects*/
    const Animal* cat = new Cat();
    const WrongAnimal* wrong = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    /*Let's break this down:

        1. `const` Usage:
           - `const` here means the pointer cannot modify the object it points to
           - Prevents accidental modifications to the objects
           - Provides type safety and helps enforce design intentions
        
        2. Pointer Usage:
           - Polymorphism requires pointers or references
           - Allows calling the most derived class's method through base class pointer
           - Dynamic memory allocation with `new`
           - Enables runtime polymorphic behavior (virtual function calls)
        
        Example of polymorphic behavior:
        
        dog->makeSound();  // Calls Dog's makeSound(), not Animal's
        cat->makeSound();  // Calls Cat's makeSound(), not Animal's
    
        
        Without pointers, you'd lose this runtime polymorphic behavior. 
        The pointer allows the correct method to be called based on the 
        actual object type, not the pointer's type.
        
        Memory management note: Always `delete` pointers created with `new` to prevent memory leaks.*/

    std::cout << "Type: " << dog->getType() << std::endl;
    std::cout << "Type: " << cat->getType() << std::endl;
    std::cout << "Type: " << animal->getType() << std::endl;
    cat->makeSound(); // will output the cat sound!
    dog->makeSound();
    animal->makeSound();

    std::cout << "\033[31m****Wrong animal tests:****\033[0m" << std::endl;
    std::cout << wrong->getType() << " : ";
    wrong->makeSound();
    
    std::cout << wrongCat->getType() << " : ";
    wrongCat->makeSound(); // Calls WrongAnimal's version ❌
    std::cout << "\033[31m****End Wrong animal tests:****\033[0m" << std::endl;

    /*The key difference is in how `makeSound()` is defined:

        1. In the correct implementation (Animal/Dog/Cat):
        
        virtual void makeSound() const;  // virtual keyword allows polymorphic behavior
        
        2. In WrongAnimal/WrongCat:
        
        void makeSound() const;  // No virtual keyword
        
        Without `virtual`, when you call `makeSound()` through a base class pointer, 
        it always calls the base class method. 
        
        In the main code:
        const WrongAnimal* wrongCat = new WrongCat();
        wrongCat->makeSound();  // Calls WrongAnimal::makeSound(), not WrongCat::makeSound()
        
        This demonstrates the lack of polymorphic behavior - the method called depends on 
        the pointer type, not the actual object type.*/

    delete animal;
    delete dog;
    delete cat;
    delete wrong;
    delete wrongCat;        // Properly calls ~WrongCat then ~WrongAnimal ✅

    return 0;
}