/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:01:09 by pmolzer           #+#    #+#             */
/*   Updated: 2025/04/23 15:08:33 by pmolzer          ###   ########.fr       */
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

int main() {
    // Generate and identify multiple instances
    for (int i = 0; i < 5; i++) 
    {
        std::cout << "\n--- Test " << i + 1 << " ---" << std::endl;
        
        // Generate a random instance
        Base* instance = generate();
        
        // Identify using pointer
        identify(instance);
        
        // Identify using reference
        identify(*instance);
        
        // Clean up
        delete instance;
    }
    
    return 0;
}