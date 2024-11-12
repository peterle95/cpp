# Fixed-Point Number Representation Program

## Overview

This program implements a class that represents a fixed-point number in C++. The class is designed in Orthodox Canonical Form, which includes a default constructor, a copy constructor, a copy assignment operator, and a destructor. The program demonstrates the use of these features through a simple main function.

## Step-by-Step Guide

### 1. Class Definition

The `Fixed` class is defined in `Fixed.hpp`. It contains:

- **Private Members:**
  - `_fixedPointValue`: An integer that stores the fixed-point number value.
  - `_fractionalBits`: A static constant integer set to 8, representing the number of fractional bits.

- **Public Members:**
  - A default constructor that initializes `_fixedPointValue` to 0.
  - A copy constructor that creates a new object as a copy of an existing object.
  - A copy assignment operator that allows one object to be assigned the value of another.
  - A destructor that cleans up when an object goes out of scope.
  - `getRawBits()`: A member function that returns the raw value of the fixed-point number.
  - `setRawBits(int const raw)`: A member function that sets the raw value of the fixed-point number.

### 2. Implementation of the Class

The implementation of the `Fixed` class is found in `Fixed.cpp`. Here’s how the members are defined:

- **Default Constructor:**
  Initializes `_fixedPointValue` to 0 and prints a message indicating that the constructor was called.

- **Copy Constructor:**
  Copies the value from another `Fixed` object and prints a message indicating that the copy constructor was called.

- **Copy Assignment Operator:**
  Checks for self-assignment, copies the value from another `Fixed` object, and prints a message indicating that the copy assignment operator was called.

- **Destructor:**
  Prints a message when the object is destroyed.

- **getRawBits():**
  Returns the value of `_fixedPointValue` and prints a message indicating that the function was called.

- **setRawBits():**
  Sets the value of `_fixedPointValue`.

### 3. Main Function

The `main` function in `main.cpp` demonstrates the usage of the `Fixed` class:

- Three `Fixed` objects are created: `a`, `b`, and `c`.
- `b` is initialized as a copy of `a` using the copy constructor.
- `c` is assigned the value of `b` using the copy assignment operator.
- The raw values of `a`, `b`, and `c` are printed to the console.

### 4. Compilation and Execution

The program is compiled using a Makefile (`Makefile`). The commands in the Makefile specify how to compile the program and manage object files. The `all` target builds the executable, while `clean` and `fclean` remove object files and the executable, respectively.

To compile and run the program, use the following commands in the terminal:

```bash
make
./fixed
```

## Concepts to Understand


## Concepts to Understand

### 1. Object-Oriented Programming (OOP)

This program utilizes OOP principles, including encapsulation (hiding data).

#### Encapsulation

Encapsulation is the principle of bundling the data (attributes) and methods (functions) that operate on the data into a single unit, or class. It restricts direct access to some of the object's components, which is a means of preventing unintended interference and misuse of the methods and data. In the `Fixed` class, the `_fixedPointValue` and `_fractionalBits` are private members, meaning they cannot be accessed directly from outside the class. Instead, public methods like `getRawBits()` and `setRawBits()` are provided to interact with these private members.


## Conclusion

This program provides a basic implementation of a fixed-point number class in C++. By understanding the concepts outlined above, you can gain a deeper insight into how the program works and how to extend it for more complex functionalities.
