/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:17:00 by pmolzer           #+#    #+#             */
/*   Updated: 2025/07/03 20:17:47 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

/*TASK:
Write a class ScalarConverter that will contain only one static method "convert"
that will take as a parameter a string representation of a C++ literal in its most common
form and output its value in the following series of scalar types:
• char
• int
• float
• double
As this class doesn’t need to store anything at all, it must not be instantiable by users.
Except for char parameters, only the decimal notation will be used.
Examples of char literals: ’c’, ’a’, ...
To make things simple, please note that non-displayable characters shouldn’t be used as
inputs. If a conversion to char is not displayable, print an informative message.
Examples of int literals: 0, -42, 42...
Examples of float literals: 0.0f, -4.2f, 4.2f...
You have to handle these pseudo-literals as well (you know, for science): -inff, +inff,
and nanf.
Examples of double literals: 0.0, -4.2, 4.2...
You have to handle these pseudo-literals as well (you know, for fun): -inf, +inf, and
nan

Write a program to test that your class works as expected.
You have to first detect the type of the literal passed as a parameter, convert it from
string to its actual type, then convert it explicitly to the three other data types. Lastly,
display the results as shown below.
If a conversion does not make any sense or overflows, display a message to inform
the user that the type conversion is impossible. Include any header you need in order to
handle numeric limits and special values.
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
./convert nan
char: impossible
int: impossible
float: nanf
double: nan
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
*/

int main(int argc, char* argv[]) 
{
    // ScalarConverter testobj;
    
    if (argc != 2) 
    {
        std::cout << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }
    
    ScalarConverter::convert(argv[1]);
    ScalarConverter::convert("nan");
    ScalarConverter::convert("+inf");
    return 0;
}

/*Why Private Constructors/Destructors?
The ScalarConverter class is designed as a utility class or static class - it's meant to provide 
functionality without ever creating instances of it. Here's why:
1. Preventing Instantiation

// These are private - users cannot do this:
ScalarConverter converter;           // ❌ Compilation error
ScalarConverter* ptr = new ScalarConverter(); // ❌ Compilation error

The class is designed to work like this instead:

//Only this is allowed:
ScalarConverter::convert("42");      // ✅ Static method call

2. The Class Has No State
The ScalarConverter class doesn't need to store any data (no member variables). 
It's purely a collection of related functions. Creating objects would be wasteful and unnecessary.

What About = 0 (Pure Virtual)?

If you wrote:

ScalarConverter() = 0;  // This would be invalid!

This syntax doesn't work for constructors. You might be thinking of:
Pure Virtual Functions:

virtual void someFunction() = 0;  // Pure virtual function

This makes the class abstract - you can't instantiate it, but you can inherit from it.
Deleted Functions (C++11+):

ScalarConverter() = delete;  // Explicitly deleted constructor

This explicitly prevents the function from being used, but it's more modern syntax.
The static Access Specifier
What static does:

1. No Object Required: Static members belong to the class itself, not to any instance
2. Single Copy: Only one copy exists regardless of how many objects you create
3. Accessible via Class Name: You call them using ClassName::functionName()

Why Use Static Here?

class ScalarConverter {
public:
    static void convert(const std::string& literal);  // Static method
};

// Usage:
ScalarConverter::convert("42");  // No object needed!

Compare this to a non-static approach:

class ScalarConverter {
public:
    void convert(const std::string& literal);  // Non-static method
};

// Usage would require:
ScalarConverter converter;    // Create object first
converter.convert("42");      // Then call method on object

Design Pattern: Static Utility Class
This is a common pattern in C++ (and other languages) for utility classes:
Benefits:

1. No Memory Overhead: No objects to create/destroy
2. Clear Intent: It's obvious this is just a collection of utility functions
3. Performance: No object creation overhead
4. Simplicity: Users can't accidentally create objects or pass them around

Real-World Examples:

// Standard library examples:
std::sort(vec.begin(), vec.end());        // Algorithm utilities
std::numeric_limits<int>::max();          // Type utilities
std::string::npos;                        // String constants

// Your class:
ScalarConverter::convert("42.0f");        // Conversion utilities

Alternative Approaches
1. Free Functions (C-style):

// Instead of a class, just have functions:
void convert(const std::string& literal);
bool isInt(const std::string& literal);
// etc.
Problem: Functions aren't grouped together, potential naming conflicts.
2. Namespace:
namespace ScalarConverter {
    void convert(const std::string& literal);
    bool isInt(const std::string& literal);
    // etc.
}

// Usage:
ScalarConverter::convert("42");

This is actually a valid alternative! Many C++ developers prefer this approach.
3. Singleton Pattern:

class ScalarConverter {
public:
    static ScalarConverter& getInstance() {
        static ScalarConverter instance;
        return instance;
    }
    void convert(const std::string& literal);
};

// Usage:
ScalarConverter::getInstance().convert("42");

Problem: More complex, still requires object creation, overkill for stateless utilities.

Why Not Abstract Base Class?
If you made it abstract:
class ScalarConverter {
public:
    virtual void convert(const std::string& literal) = 0;  // Pure virtual
    virtual ~ScalarConverter() = default;
};

class ConcreteConverter : public ScalarConverter {
public:
    void convert(const std::string& literal) override {
        // Implementation
    }
};

Problems with this approach:

More complex inheritance hierarchy
Still need to create objects: ConcreteConverter converter;
Virtual function overhead
Unnecessary complexity for simple utility functions

Summary
The current design is a Static Utility Class pattern:

Private constructors prevent instantiation
Static methods provide functionality without objects
Clean, simple interface: ScalarConverter::convert("42")
No memory overhead or object management
Clear intent that this is just a collection of related utility functions

This pattern is particularly common in C++ for utility classes that don't need to maintain state and just provide algorithmic functionality.*/