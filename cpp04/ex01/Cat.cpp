/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:42:50 by pmolzer           #+#    #+#             */
/*   Updated: 2025/04/30 15:08:33 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

/*In the Dog and Cat classes, they:

1. Call the base Animal class copy constructor
2. Override:
   - Constructor (to set specific type)
   - Copy constructor (to do deep copy of brain)
   - Assignment operator (to handle deep copy)
   - Destructor (to properly delete brain)
   - makeSound() method

They use some Animal methods directly (like getType()) and inherit the base class behavior for others.*/

Cat::Cat() // : brain(new Brain()) this is theoretically better
{
    this->brain = new Brain();
    // Brain* brain = new Brain(); // This creates a *local* variable named 'brain' and is wrong
    type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

/*Takes a constant reference to another Cat object as parameter
Calls the base Animal class copy constructor using : Animal(other)
Performs a deep copy of the brain by creating a new Brain object using the source object's 
brain: brain(new Brain(*other.brain))
This ensures the copied Cat has its own independent Brain instance, not just a pointer to the original Brain

Key points:

Deep copy mechanism prevents shared brain pointer between original and copied objects
Creates a completely new Brain object with the same content as the source
Prevents memory sharing and potential double-free issues

By creating a new Brain instance in the copy constructor, each Cat 
object maintains its own unique memory allocation for brain data.*/
Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) 
{
    std::cout << "Cat copy constructor called" << std::endl;
}

/*This is the assignment operator for the `Cat` class. Let's break down the syntax:

```cpp
Cat& Cat::operator=(const Cat& other)
```

- `Cat&`: Return type is a reference to a `Cat` object
- `Cat::operator=`: Defines the assignment operator for the `Cat` class
- `(const Cat& other)`: Takes a constant reference to another `Cat` object as a parameter

Key points:
- Allows copying of `Cat` objects using the `=` operator
- Uses `Animal::operator=(other)` to copy base class attributes
- Prevents self-assignment with `if (this != &other)`
- Returns a reference to the modified object to allow chaining assignments

Example usage:
```cpp
Cat cat1;
Cat cat2;
cat2 = cat1; // This calls the assignment operator
```*/
Cat& Cat::operator=(const Cat& other) 
{
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) 
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() 
{
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const 
{
    std::cout << "Meow! Meow!" << std::endl;
}