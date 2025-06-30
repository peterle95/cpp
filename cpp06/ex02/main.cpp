/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:01:09 by pmolzer           #+#    #+#             */
/*   Updated: 2025/06/30 21:15:17 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

/*TASK:
Implement a Base class that has a public virtual destructor only. Create three empty
classes A, B, and C, that publicly inherit from Base.
These four classes don’t have to be designed in the Orthodox
Canonical Form.
Implement the following functions:
Base * generate(void);
It randomly instantiates A, B, or C and returns the instance as a Base pointer. Feel free
to use anything you like for the random choice implementation.
void identify(Base* p);
It prints the actual type of the object pointed to by p: "A", "B", or "C".
void identify(Base& p);
It prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
inside this function is forbidden.
Including the typeinfo header is forbidden.
Write a program to test that everything works as expected.
*/

/*Purpose and Core Concepts
This exercise demonstrates runtime type identification (RTTI) and polymorphism in C++. The core concepts are:
Polymorphism: You have a base class Base with derived classes A, B, C. 
You can store any derived object as a Base* pointer, but the actual type is hidden.
Dynamic Casting: dynamic_cast allows you to safely check and convert between related types at runtime:

With pointers: Returns nullptr if the cast fails
With references: Throws std::bad_cast exception if the cast fails

The Challenge: Given only a Base* or Base&, determine the actual derived type without using typeid or including <typeinfo>.
Solution Strategy:

For pointers: Try dynamic_cast to each type, check for nullptr
For references: Try dynamic_cast in try-catch blocks, catch std::bad_cast*/

int main() 
{
    // This exercise demonstrates Runtime Type Identification (RTTI) using dynamic_cast
    // We have a polymorphic hierarchy: Base -> A, B, C
    // The challenge: identify the actual type when we only have a Base pointer/reference
    
    // Generate and identify multiple instances to show randomness and type identification
    for (int i = 0; i < 5; i++) 
    {
        std::cout << "\n--- Test " << i + 1 << " ---" << std::endl;
        
        // generate() randomly creates A, B, or C but returns as Base*
        // This simulates real scenarios where you receive a base pointer
        // but need to know the actual derived type
        Base* instance = generate();
        
        // identify(Base* p) uses dynamic_cast<DerivedType*> 
        // If successful, returns valid pointer; if failed, returns nullptr
        // This is the "safe" way to check types with pointers
        identify(instance);
        
        // identify(Base& p) uses dynamic_cast<DerivedType&>
        // If successful, returns reference; if failed, throws std::bad_cast
        // Must use try-catch blocks since we can't check references for "null"
        // Demonstrates type identification without using pointers internally
        identify(*instance);
        
        // Clean up dynamically allocated memory
        delete instance;
    }
    
    return 0;
}