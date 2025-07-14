/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:01:21 by pmolzer           #+#    #+#             */
/*   Updated: 2025/07/07 14:52:30 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
// #include <typeinfo> // for std::bad_cast, not allowed in the subject

Base* generate(void) 
{
    static bool firstCall = true;
    if (firstCall) 
    {
        std::srand(std::time(NULL));
        firstCall = false;
    }
    
    int randomNum = std::rand() % 3;
    
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
            return NULL;
    }
}

void identify(Base* p) 
{
    if (dynamic_cast<A*>(p) != NULL) 
        std::cout << "Identified type via pointer: A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL) 
        std::cout << "Identified type via pointer: B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL) 
        std::cout << "Identified type via pointer: C" << std::endl;
    else 
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p) 
{
    try 
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Identified type via reference: A" << std::endl;
        return;
    } 
    catch (const std::exception& e) 
    {}
    
    try 
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Identified type via reference: B" << std::endl;
        return;
    } 
    catch (const std::exception& e) 
    {}
    
    try 
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Identified type via reference: C" << std::endl;
        return;
    } 
    catch (const std::exception& e) 
    {
        std::cout << "Unknown type" << std::endl;
    }
}