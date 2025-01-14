# Overview of the Program
This program defines a `Fixed` class that represents fixed-point numbers. It includes constructors for initializing fixed-point values from integers and floating-point numbers, as well as member functions to convert these values back to floating-point and integer representations. The program also overloads the insertion operator to allow easy output of `Fixed` objects.

## Step-by-Step Breakdown

### 1. File Structure:
The program consists of multiple files:
- **main.cpp**: Contains the main function and demonstrates the usage of the `Fixed` class.
- **Fixed.cpp**: Implements the methods of the `Fixed` class.
- **Fixed.hpp**: Declares the `Fixed` class and its methods.
- **Makefile**: Used to compile the program.

### Header File (Fixed.hpp):
The header file defines the `Fixed` class and its member functions. It includes guards (`#ifndef`, `#define`, `#endif`) to prevent multiple inclusions. The class has:
- A private member variable `_fixedPointValue` to store the fixed-point value. This variable is not accessible from outside the class, ensuring that the internal representation of the fixed-point number is protected from direct modification, which promotes encapsulation and data integrity.
- A static constant `_fractionalBits` set to 8, which determines the number of bits used for the fractional part. Being static means that this constant is shared across all instances of the class, and it cannot be modified at runtime. This ensures that the fixed-point representation remains consistent across all objects of the `Fixed` class.

### Class Constructors:
- **Default Constructor**: Initializes `_fixedPointValue` to 0 and prints a message.
- **Integer Constructor**: Takes an integer, shifts it left by `_fractionalBits` (effectively multiplying it by 256), and prints a message.
- **Float Constructor**: Takes a float, multiplies it by \(2^{\text{_fractionalBits}}\) (or 256), rounds it, and prints a message.
- **Copy Constructor**: Initializes a new object as a copy of an existing one and prints a message.

### Assignment Operator:
The `operator=` function allows one `Fixed` object to be assigned to another. It checks for self-assignment and copies the raw bits from the source object.

### Destructor:
The destructor prints a message when an object is destroyed, helping track object lifetimes.

### 6. Member Functions:
- **getRawBits()**: Returns the raw fixed-point value.
- **setRawBits(int const raw)**: Sets the raw fixed-point value.
- **toFloat()**: Converts the fixed-point value back to a floating-point number by dividing by \(2^{\text{_fractionalBits}}\).
- **toInt()**: Converts the fixed-point value to an integer by shifting right by `_fractionalBits`.

### Operator Overloading:
The `operator<<` function is overloaded to allow `std::cout` to print `Fixed` objects directly. It calls the `toFloat()` method to get the floating-point representation.

### Main Function (main.cpp):
The main function demonstrates the usage of the `Fixed` class:
- It creates several `Fixed` objects using different constructors.
- It assigns a new `Fixed` object to an existing one.
- It prints the values of the `Fixed` objects using `std::cout`.
- It converts the fixed-point values to integers and prints them.


## Important Concepts
- **Fixed-Point Arithmetic**: This program uses fixed-point representation to handle decimal numbers without floating-point precision issues. It achieves this by using integer arithmetic and scaling.
- **Object-Oriented Programming (OOP)**: The program demonstrates OOP principles such as encapsulation (hiding data), constructors/destructors (object lifecycle management), and operator overloading (customizing behavior of operators).
- **Memory Management**: The program manages memory through constructors and destructors, ensuring that resources are allocated and deallocated properly.

## Conclusion
This program effectively demonstrates the principles of fixed-point arithmetic, object-oriented programming, and operator overloading in C++. By following the steps outlined above, you can understand how the program works and the concepts it illustrates.