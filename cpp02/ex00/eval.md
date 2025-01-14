I'll help you present the ex00 project as a 42 student. Here's a comprehensive overview:

## Project Purpose and Requirements

This is the first exercise of Module 02, focusing on implementing a fixed-point number class in Orthodox Canonical Form. The main requirements were to:

1. Create a `Fixed` class that represents fixed-point numbers
2. Implement it following Orthodox Canonical Form (default constructor, copy constructor, copy assignment operator, destructor)
3. Include specific private members:
   - An integer to store the fixed-point value
   - A static constant integer for fractional bits (set to 8)
4. Provide member functions to get and set the raw bits

## Implementation Approach

I implemented this using three main files:

1. `Fixed.hpp` - Class declaration
2. `Fixed.cpp` - Method implementations
3. `main.cpp` - Test program

### Key Design Choices

1. **Encapsulation**: I made `_fixedPointValue` private to protect the internal representation
2. **Const Correctness**: Used `const` for the copy constructor parameter and `getRawBits()` method
3. **Verbose Output**: Added descriptive messages for each constructor/destructor call to track object lifecycle

## Key Functions and Classes

The `Fixed` class is the core component. Here are its key elements:

### Private Members
```cpp
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;
```

### Constructors and Operators
```cpp
Fixed::Fixed() : _fixedPointValue(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) 
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_fixedPointValue = rhs.getRawBits();
    return *this;
}
```

## Edge Cases and Error Handling

1. **Self-Assignment Protection**: 
```cpp
if (this != &rhs)
```
This check prevents issues during self-assignment (e.g., `a = a`).

2. **Const Correctness**: Using `const` references prevents accidental modifications:
```cpp
int getRawBits(void) const;
```

## What I Learned

1. **Orthodox Canonical Form**: Understanding why these four components (default constructor, copy constructor, assignment operator, and destructor) are essential for proper class design.

2. **Fixed-Point Numbers**: Learning about fixed-point arithmetic as an alternative to floating-point numbers.

3. **Copy Semantics**: Understanding deep vs shallow copying and why proper copy construction is important.

4. **Operator Overloading**: Learning how to properly implement the assignment operator with self-assignment protection.

If you have any specific questions about the implementation or would like me to elaborate on any part, I'd be happy to explain further.
