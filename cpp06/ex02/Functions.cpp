/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:01:21 by pmolzer           #+#    #+#             */
/*   Updated: 2025/04/23 15:11:20 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo> // Add this for std::bad_cast

// Randomly instantiates A, B, or C and returns as Base pointer
Base* generate(void) 
{
    // Seed the random number generator (should be done once per program)
    static bool firstCall = true;
    if (firstCall) 
    {
        std::srand(std::time(NULL));
        firstCall = false;
    }
    
    // Generate a random number between 0 and 2
    int randomNum = std::rand() % 3;
    
    // Create an instance based on the random number
    switch (randomNum) 
    {
        case 0:
            std::cout << "Generated an instance of class A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated an instance of class B" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated an instance of class C" << std::endl;
            return new C();
        default:
            return NULL; // Should never reach here
    }
}

// Identifies the type using a pointer
void identify(Base* p) 
{
    // Try to cast to each type and check if it works
    if (dynamic_cast<A*>(p) != NULL) 
        std::cout << "Identified type via pointer: A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL) 
        std::cout << "Identified type via pointer: B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL) 
        std::cout << "Identified type via pointer: C" << std::endl;
    else 
        std::cout << "Unknown type" << std::endl;
}

// Identifies the type using a reference
void identify(Base& p) 
{
    // Using try-catch blocks because dynamic_cast with references throws on failure
    try 
    {
        A& a = dynamic_cast<A&>(p);
        (void)a; // To avoid unused variable warning
        std::cout << "Identified type via reference: A" << std::endl;
        return;
    } 
    catch (const std::bad_cast&) 
    {
        // Not type A, continue to next try
    }
    
    try 
    {
        B& b = dynamic_cast<B&>(p);
        (void)b; // To avoid unused variable warning
        std::cout << "Identified type via reference: B" << std::endl;
        return;
    } 
    catch (const std::bad_cast&) 
    {
        // Not type B, continue to next try
    }
    
    try 
    {
        C& c = dynamic_cast<C&>(p);
        (void)c; // To avoid unused variable warning
        std::cout << "Identified type via reference: C" << std::endl;
        return;
    } 
    catch (const std::bad_cast&) 
    {
        // Not type C
        std::cout << "Unknown type" << std::endl;
    }
}