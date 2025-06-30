/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:02:55 by pmolzer           #+#    #+#             */
/*   Updated: 2025/06/30 21:26:54 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

/*
 * BASE CLASS FOR RUNTIME TYPE IDENTIFICATION (RTTI) DEMONSTRATION
 * 
 * This header defines the foundation of a polymorphic hierarchy used to
 * demonstrate RTTI concepts and safe type casting in C++.
 * 
 * KEY DESIGN DECISIONS:
 * - Minimal interface (only destructor)
 * - Virtual destructor enables polymorphism
 * - No Orthodox Canonical Form required (as per exercise)
 */

/**
 * Base class - Foundation of polymorphic hierarchy
 * 
 * CRITICAL CONCEPTS:
 * 
 * 1. POLYMORPHIC BASE CLASS
 *    - Must have at least ONE virtual function to enable RTTI
 *    - Virtual destructor serves this purpose AND ensures proper cleanup
 *    - Without virtual functions, dynamic_cast won't work!
 * 
 * 2. VIRTUAL DESTRUCTOR IMPORTANCE
 *    - Enables proper destruction of derived objects through base pointers
 *    - Prevents undefined behavior when deleting derived objects via base pointer
 *    - Makes the class polymorphic (enables RTTI and dynamic_cast)
 * 
 * 3. PUBLIC DESTRUCTOR
 *    - Allows external code to delete objects
 *    - Essential for factory pattern used in generate() function
 */
class Base 
{
    public:
        /**
         * Virtual destructor - THE CORNERSTONE OF POLYMORPHISM
         * 
         * WHY VIRTUAL?
         * - When you do: Base* ptr = new Derived(); delete ptr;
         * - Without virtual: Only Base destructor called (WRONG!)
         * - With virtual: Derived destructor called first, then Base (CORRECT!)
         * 
         * WHY PUBLIC?
         * - Allows external deletion: delete basePtr;
         * - Required for factory pattern and dynamic allocation
         * 
         * RTTI ENABLEMENT:
         * - Having ANY virtual function makes class "polymorphic"
         * - Polymorphic classes have Runtime Type Information
         * - RTTI is required for dynamic_cast to work
         * - Virtual destructor is the minimal virtual function needed
         * 
         * MEMORY SAFETY:
         * - Prevents resource leaks in derived classes
         * - Ensures proper cleanup order (derived -> base)
         * - Critical when base pointer manages derived objects
         */
        virtual ~Base();
        
        /*
         * DESIGN NOTES:
         * 
         * NO OTHER VIRTUAL FUNCTIONS:
         * - This exercise focuses purely on type identification
         * - No behavior polymorphism needed (no virtual methods)
         * - Destructor alone provides necessary RTTI support
         * 
         * NO ORTHODOX CANONICAL FORM:
         * - No copy constructor needed
         * - No assignment operator needed  
         * - No default constructor needed
         * - Exercise explicitly states this is not required
         * 
         * INHERITANCE DESIGN:
         * - Derived classes (A, B, C) will be empty
         * - Only purpose is to create distinct types for RTTI testing
         * - Classic example of "marker classes" or "tag types"
         */
};

// ========== FUNCTION PROTOTYPES ==========

/*
 * These function declarations define the interface for RTTI operations.
 * Implementation is in Functions.cpp
 */

/**
 * generate() - Factory function for random object creation
 * 
 * FACTORY PATTERN:
 * - Creates objects without specifying exact class
 * - Client code doesn't need to know about A, B, C classes
 * - Returns Base* hiding actual derived type
 * 
 * POLYMORPHISM DEMONSTRATION:
 * - Returns derived objects as base pointers (upcasting)
 * - Actual type is hidden from caller
 * - Forces use of RTTI to determine real type
 * 
 * RETURN TYPE: Base*
 * - Pointer allows null return (though we don't use it)
 * - Enables polymorphic behavior
 * - Caller responsible for deletion (ownership transfer)
 */
Base* generate(void);

/**
 * identify(Base* p) - Type identification using pointer
 * 
 * POINTER-BASED RTTI:
 * - Uses dynamic_cast<DerivedType*>
 * - Returns nullptr on failure, valid pointer on success
 * - Null-checking pattern for type determination
 * 
 * SAFE DOWNCASTING:
 * - Converts Base* to derived pointer safely
 * - Runtime type checking prevents invalid casts
 * - Alternative to dangerous C-style casts
 * 
 * PARAMETER: Base* p
 * - Accepts any object in the hierarchy
 * - Can be null (though our usage guarantees non-null)
 * - Const-correct (could be const Base* if we don't modify)
 */
void identify(Base* p);

/**
 * identify(Base& p) - Type identification using reference
 * 
 * REFERENCE-BASED RTTI:
 * - Uses dynamic_cast<DerivedType&> 
 * - Throws std::bad_cast on failure, returns reference on success
 * - Exception-handling pattern for type determination
 * 
 * REFERENCE CONSTRAINTS:
 * - Cannot be null (references must refer to valid objects)
 * - Cannot use pointer internally (exercise constraint)
 * - Must use try-catch for error handling
 * 
 * PARAMETER: Base& p
 * - Reference guarantees valid object
 * - No null checking needed
 * - Demonstrates exception-based error handling
 * 
 * EXERCISE CONSTRAINT:
 * - "Using a pointer inside this function is forbidden"
 * - Forces pure reference-based approach
 * - Shows different exception handling paradigm
 */
void identify(Base& p);

/*
 * HEADER DESIGN PRINCIPLES:
 * 
 * 1. SINGLE RESPONSIBILITY
 *    - Base class: Enable polymorphism and RTTI
 *    - Functions: Demonstrate different RTTI techniques
 * 
 * 2. INTERFACE SEGREGATION  
 *    - Minimal Base interface (only destructor)
 *    - Clear function signatures for different approaches
 * 
 * 3. DEPENDENCY INVERSION
 *    - Functions depend on Base abstraction
 *    - Concrete types (A, B, C) are implementation details
 * 
 * 4. OPEN/CLOSED PRINCIPLE
 *    - Easy to add new derived types without changing Base
 *    - identify() functions would need updates (tradeoff)
 * 
 * RTTI REQUIREMENTS SATISFIED:
 * - Polymorphic base class (virtual destructor)
 * - Runtime type information available
 * - Safe downcasting mechanisms provided
 * - Both pointer and reference approaches supported
 */

#endif

/*
 * CRITICAL UNDERSTANDING POINTS:
 * 
 * 1. VIRTUAL DESTRUCTOR = POLYMORPHISM ENABLER
 *    - Without it, dynamic_cast won't work
 *    - Essential for safe polymorphic destruction
 *    - Minimal requirement for RTTI functionality
 * 
 * 2. RTTI CHAIN OF DEPENDENCIES
 *    - Virtual function → Polymorphic class
 *    - Polymorphic class → RTTI available  
 *    - RTTI available → dynamic_cast works
 *    - dynamic_cast → Safe type identification
 * 
 * 3. DESIGN TRADEOFFS
 *    - Minimal interface vs. rich functionality
 *    - Type safety vs. performance overhead
 *    - Compile-time vs. runtime type checking
 * 
 * 4. REAL-WORLD APPLICATIONS
 *    - Plugin architectures
 *    - Serialization systems
 *    - Event handling frameworks
 *    - Component-based game engines
 * 
 * This header establishes the foundation for understanding how C++
 * provides safe, runtime type identification in polymorphic hierarchies.
 */