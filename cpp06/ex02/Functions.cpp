/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:01:21 by pmolzer           #+#    #+#             */
/*   Updated: 2025/06/30 21:24:19 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>  // For std::rand() and std::srand()
#include <ctime>    // For std::time() - used to seed random number generator
#include <typeinfo> // For std::bad_cast exception type (NOT for typeid - that's forbidden)

/*
 * RUNTIME TYPE IDENTIFICATION (RTTI) FUNCTIONS
 * 
 * This file implements three key functions that demonstrate RTTI concepts:
 * 1. generate() - Creates random derived objects
 * 2. identify(Base* p) - Identifies type using pointer and dynamic_cast
 * 3. identify(Base& p) - Identifies type using reference and dynamic_cast with exceptions
 */

// ========== RANDOM OBJECT GENERATION ==========

/**
 * generate() - Randomly instantiates A, B, or C and returns as Base pointer
 * 
 * KEY CONCEPTS:
 * - Polymorphism: Returns derived objects as Base* (upcasting)
 * - Dynamic allocation: Uses 'new' to create objects on heap
 * - Random number generation: Uses C standard library functions
 * 
 * DESIGN PATTERN: Factory pattern - creates objects without specifying exact class
 */
Base* generate(void) 
{
    // STATIC INITIALIZATION PATTERN
    // We only want to seed the random number generator ONCE per program execution
    // Using static variable ensures this initialization happens only on first call
    static bool firstCall = true;
    if (firstCall) 
    {
        // std::srand() seeds the pseudo-random number generator (PRNG) used by std::rand().
        // Think of the PRNG as a long, predetermined sequence of numbers that appears random.
        // The "seed" is the starting point in that sequence.
        //
        // - If you provide the SAME seed to srand(), you will get the EXACT SAME sequence of
        //   "random" numbers from subsequent calls to rand(). This is useful for testing
        //   and reproducibility.
        // - To get a different sequence of numbers each time the program runs, we need a
        //   different seed. A common practice is to use the current time (std::time(NULL)),
        //   which is nearly always different on each execution.
        //
        // In summary: srand() sets the starting point. rand() gets the next number in the sequence.
        // You only need to seed ONCE per program execution.
        std::srand(std::time(NULL));
        firstCall = false;
    }
    
    // Generate random number 0, 1, or 2
    // std::rand() returns random int, % 3 gives remainder (0, 1, or 2)
    int randomNum = std::rand() % 3;
    
    // POLYMORPHIC OBJECT CREATION
    // Each case creates a different derived type but returns as Base*
    // This is UPCASTING - implicit conversion from derived to base pointer
    switch (randomNum) 
    {
        case 0:
            std::cout << "Generated an instance of class A" << std::endl;
            return new A();  // A* implicitly converted to Base*
        case 1:
            std::cout << "Generated an instance of class B" << std::endl;
            return new B();  // B* implicitly converted to Base*
        case 2:
            std::cout << "Generated an instance of class C" << std::endl;
            return new C();  // C* implicitly converted to Base*
        default:
            return NULL; // Should never reach here with % 3, but good practice
    }
}

// ========== TYPE IDENTIFICATION WITH POINTERS ==========

/**
 * identify(Base* p) - Identifies the actual type using pointer and dynamic_cast
 * 
 * KEY CONCEPTS:
 * - dynamic_cast with pointers: Returns nullptr on failure, valid pointer on success
 * - Safe downcasting: Converting from base pointer to derived pointer safely
 * - RTTI requirement: Only works with polymorphic classes (classes with virtual functions)
 * 
 * WHY dynamic_cast?
 * - static_cast: Fast but unsafe, no runtime checking
 * - C-style cast: Unsafe, can cast unrelated types
 * - dynamic_cast: Safe, checks actual object type at runtime
 */
void identify(Base* p) 
{
    // PATTERN: Try each possible derived type in sequence
    
    // Try to cast Base* to A*
    // If p actually points to an A object, dynamic_cast returns valid A*
    // If p points to B or C object, dynamic_cast returns nullptr
    if (dynamic_cast<A*>(p) != NULL) 
        std::cout << "Identified type via pointer: A" << std::endl;
    
    // Only check B if it's not A (else if pattern)
    else if (dynamic_cast<B*>(p) != NULL) 
        std::cout << "Identified type via pointer: B" << std::endl;
    
    // Only check C if it's neither A nor B
    else if (dynamic_cast<C*>(p) != NULL) 
        std::cout << "Identified type via pointer: C" << std::endl;
    
    // This should never happen in our program, but handles edge cases
    else 
        std::cout << "Unknown type" << std::endl;
}

// ========== TYPE IDENTIFICATION WITH REFERENCES ==========

/**
 * identify(Base& p) - Identifies the actual type using reference and dynamic_cast
 * 
 * KEY CONCEPTS:
 * - dynamic_cast with references: Throws std::bad_cast on failure
 * - Exception handling: Must use try-catch blocks
 * - References cannot be null: Unlike pointers, we can't check for "null reference"
 * - No pointers allowed: Exercise constraint forces us to use references throughout
 * 
 * WHY DIFFERENT FROM POINTER VERSION?
 * - References must always refer to valid objects (no null references)
 * - dynamic_cast<DerivedType&> throws exception instead of returning null
 * - Forces exception-based error handling instead of null-checking
 */
void identify(Base& p) 
{
    // TRY-CATCH PATTERN for safe reference casting
    
    // ATTEMPT 1: Try to cast to A&
    try 
    {
        // If p actually refers to an A object, this succeeds
        // If p refers to B or C, this throws std::bad_cast
        A& a = dynamic_cast<A&>(p);
        
        // UNUSED VARIABLE SUPPRESSION
        // (void)a tells compiler we intentionally don't use 'a'
        // Prevents compiler warnings about unused variables
        (void)a;
        
        std::cout << "Identified type via reference: A" << std::endl;
        return; // Success! Exit function early
    } 
    catch (const std::bad_cast&) 
    {
        // EXCEPTION HANDLING
        // std::bad_cast is thrown when dynamic_cast fails with references
        // Empty catch block - we just continue to try next type
        // This is intentional: we expect failures during type testing
    }
    
    // ATTEMPT 2: Try to cast to B& (only if A failed)
    try 
    {
        B& b = dynamic_cast<B&>(p);
        (void)b; // Suppress unused variable warning
        std::cout << "Identified type via reference: B" << std::endl;
        return; // Success! Exit function
    } 
    catch (const std::bad_cast&) 
    {
        // Not type B either, continue to C
    }
    
    // ATTEMPT 3: Try to cast to C& (only if A and B failed)
    try 
    {
        C& c = dynamic_cast<C&>(p);
        (void)c; // Suppress unused variable warning
        std::cout << "Identified type via reference: C" << std::endl;
        return; // Success! Exit function
    } 
    catch (const std::bad_cast&) 
    {
        // Not type A, B, or C - this shouldn't happen in our program
        std::cout << "Unknown type" << std::endl;
    }
}

/*
 * IMPORTANT CONCEPTS SUMMARY:
 * 
 * 1. POLYMORPHISM: Base pointer can hold derived objects
 * 2. UPCASTING: Derived -> Base (implicit, always safe)
 * 3. DOWNCASTING: Base -> Derived (explicit, needs runtime checking)
 * 4. RTTI: Runtime Type Information enables dynamic_cast
 * 5. DYNAMIC_CAST: Safe casting with runtime type checking
 *    - With pointers: Returns nullptr on failure
 *    - With references: Throws std::bad_cast on failure
 * 6. VIRTUAL DESTRUCTOR: Required for polymorphism and proper cleanup
 * 7. EXCEPTION HANDLING: try-catch blocks for reference casting
 * 
 * WHY THIS MATTERS:
 * - Real applications often receive base pointers/references
 * - Need to determine actual type for specific operations
 * - Safe alternative to dangerous C-style casts
 * - Foundation for more complex design patterns (Visitor, etc.)
 */