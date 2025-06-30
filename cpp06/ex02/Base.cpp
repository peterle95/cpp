/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:02:39 by pmolzer           #+#    #+#             */
/*   Updated: 2025/06/30 21:29:49 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

/*
 * BASE CLASS IMPLEMENTATION - MINIMAL POLYMORPHIC FOUNDATION
 * 
 * This file contains the implementation of the Base class, which serves as the
 * foundation for Runtime Type Identification (RTTI) demonstration.
 * 
 * KEY QUESTION: Why only implement the destructor?
 * ANSWER: Because it's the ONLY function that needs implementation!
 */

/**
 * Virtual destructor implementation
 * 
 * WHY ONLY THE DESTRUCTOR IS IMPLEMENTED:
 * 
 * 1. PURE INTERFACE CLASS
 *    - Base is designed as a pure interface/abstract base
 *    - No data members = no initialization needed
 *    - No behavior = no methods to implement
 *    - Only purpose: enable polymorphism and RTTI
 * 
 * 2. VIRTUAL FUNCTION REQUIREMENT
 *    - Virtual functions MUST be implemented (even if empty)
 *    - Compiler error if you declare virtual function without implementation
 *    - Exception: pure virtual functions (= 0), but we don't want abstract class
 * 
 * 3. RTTI ENABLEMENT
 *    - Having ANY virtual function makes class polymorphic
 *    - Polymorphic classes get vtable (virtual function table)
 *    - vtable contains type information needed for RTTI
 *    - Destructor is minimal virtual function to achieve this
 */
Base::~Base() 
{
    /*
     * EMPTY DESTRUCTOR BODY - WHY?
     * 
     * 1. NO RESOURCES TO CLEAN UP
     *    - Base class has no data members
     *    - No dynamic memory allocation
     *    - No file handles, network connections, etc.
     *    - Nothing to destroy = empty body
     * 
     * 2. POLYMORPHIC DESTRUCTION CHAIN
     *    - When derived object is deleted through Base*:
     *      a) Derived destructor called first
     *      b) Base destructor called second  
     *      c) This ensures proper cleanup order
     *    - Base destructor runs after derived cleanup is done
     * 
     * 3. VTABLE ENTRY REQUIREMENT
     *    - Virtual destructor needs vtable entry
     *    - Even empty implementation creates necessary vtable structure
     *    - Enables dynamic_cast and other RTTI operations
     * 
     * WHAT HAPPENS BEHIND THE SCENES:
     * - Compiler generates vtable for Base class
     * - vtable contains pointer to this destructor
     * - vtable also contains RTTI information
     * - This enables dynamic_cast to work at runtime
     */
}

/*
 * WHAT'S NOT IMPLEMENTED AND WHY:
 * 
 * 1. DEFAULT CONSTRUCTOR
 *    - Compiler provides implicit default constructor
 *    - No data members to initialize
 *    - Implicit version does exactly what we need (nothing)
 *    - No need to explicitly implement
 * 
 * 2. COPY CONSTRUCTOR
 *    - Exercise states "Orthodox Canonical Form not required"
 *    - No data members to copy
 *    - Compiler-generated version would be sufficient
 *    - Not needed for RTTI demonstration
 * 
 * 3. ASSIGNMENT OPERATOR
 *    - Same reasoning as copy constructor
 *    - No data to assign
 *    - Not required for this exercise
 *    - RTTI doesn't depend on assignment
 * 
 * 4. OTHER VIRTUAL FUNCTIONS
 *    - This is a "marker class" or "tag type"
 *    - Only purpose: create distinct types for RTTI testing
 *    - No behavior needed, only type identity
 *    - Additional virtual functions would be unnecessary complexity
 */

/*
 * COMPILER-GENERATED CODE (What happens automatically):
 * 
 * The compiler implicitly generates:
 * 
 * // Default constructor (implicit)
 * Base::Base() {}
 * 
 * // Copy constructor (implicit, but may be deleted due to virtual destructor)
 * Base::Base(const Base& other) {}
 * 
 * // Assignment operator (implicit, but may be deleted)
 * Base& Base::operator=(const Base& other) { return *this; }
 * 
 * Note: Modern C++ compilers may delete copy/assignment for classes
 * with user-declared destructors (Rule of Five), but it doesn't matter
 * for this exercise since we don't copy Base objects.
 */

/*
 * VTABLE STRUCTURE (Conceptual representation):
 * 
 * When this destructor is compiled, the compiler creates:
 * 
 * Base_vtable:
 * - [0] pointer to Base::~Base()
 * - [RTTI] type information for Base class
 * - [RTTI] type hierarchy information
 * 
 * Each derived class (A, B, C) gets its own vtable:
 * 
 * A_vtable:
 * - [0] pointer to A::~A() (compiler-generated)
 * - [RTTI] type information for A class  
 * - [RTTI] inheritance chain: A -> Base
 * 
 * This vtable structure is what enables dynamic_cast to work!
 */

/*
 * MEMORY LAYOUT IMPLICATIONS:
 * 
 * Objects of polymorphic classes have extra overhead:
 * 
 * Base object memory layout:
 * [vptr] -> points to Base_vtable
 * 
 * A object memory layout:  
 * [vptr] -> points to A_vtable
 * 
 * The vptr (virtual pointer) is automatically added by compiler
 * and points to the appropriate vtable for runtime type identification.
 */

/*
 * WHY THIS DESIGN IS EFFECTIVE:
 * 
 * 1. MINIMAL OVERHEAD
 *    - Only one virtual function (destructor)
 *    - Smallest possible vtable
 *    - Minimal memory overhead per object
 * 
 * 2. MAXIMUM FUNCTIONALITY
 *    - Enables all RTTI features
 *    - Supports safe polymorphic destruction
 *    - Allows dynamic_cast operations
 * 
 * 3. CLEAR INTENT
 *    - Base class is obviously meant for inheritance
 *    - Virtual destructor signals polymorphic usage
 *    - Empty body shows it's a pure interface
 * 
 * 4. MAINTAINABLE
 *    - Simple implementation
 *    - No hidden complexity
 *    - Easy to understand and extend
 */

/*
 * REAL-WORLD PARALLELS:
 * 
 * This pattern is common in:
 * 
 * 1. PLUGIN INTERFACES
 *    - Base interface with virtual destructor
 *    - Plugins implement derived classes
 *    - Host application uses RTTI to identify plugin types
 * 
 * 2. SERIALIZATION FRAMEWORKS
 *    - Base serializable class
 *    - Derived classes for different data types
 *    - RTTI used to determine serialization method
 * 
 * 3. COMPONENT SYSTEMS
 *    - Base component class
 *    - Specialized components inherit from base
 *    - Systems use RTTI to process specific component types
 * 
 * 4. EVENT HANDLING
 *    - Base event class
 *    - Specific event types inherit from base
 *    - Handlers use RTTI to process appropriate events
 */

/*
 * CRITICAL UNDERSTANDING:
 * 
 * This single line of code (the destructor implementation) enables:
 * - Polymorphism
 * - Runtime Type Identification
 * - Safe downcasting with dynamic_cast
 * - Proper memory management in inheritance hierarchies
 * - Foundation for complex design patterns
 * 
 * It's a perfect example of how C++ allows you to achieve maximum
 * functionality with minimal code when you understand the underlying
 * mechanisms.
 */