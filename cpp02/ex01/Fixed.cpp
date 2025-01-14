/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:05:56 by pmolzer           #+#    #+#             */
/*   Updated: 2025/01/14 18:21:33 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// Fixed::Fixed():_fixedPointValue(0) is a member initializer list that 
// initializes _fixedPointValue to 0 before the constructor body executes.
// This is a more efficient way to initialize member variables, as it 
// avoids an extra assignment operation.
// Fixed::Fixed() on the other hand, initializes _fixedPointValue in the constructor 
// body, which is less efficient.
// The first method is possible in C++11 and later, allowing for more concise and efficient initialization.
// Fixed::Fixed():_fixedPointValue(0) is preferred for initializing member variables.
/* Fixed::Fixed():_fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
} */

/* 
Default constructor for the Fixed class. 
This constructor initializes the fixed-point value to 0 and outputs a message.
*/
Fixed::Fixed()
{
    _fixedPointValue = 0; // Initialize _fixedPointValue to 0 in the constructor body
    std::cout << "Default constructor called" << std::endl; // Print message indicating the constructor was called
}

/* 
Constructor that initializes the Fixed object with an integer value.
The integer is converted to a fixed-point representation by shifting left 
by the number of fractional bits.

This line converts an integer value 'n' into its fixed-point representation.
The fixed-point representation is achieved by shifting the integer 'n' to the left 
by the number of fractional bits (_fractionalBits). 

Shifting left by _fractionalBits effectively multiplies 'n' by 2 raised to the power 
of _fractionalBits (which is 8 in this case). This is done to allocate space for 
the fractional part of the fixed-point number. 

For example, if n is 5 and _fractionalBits is 8, the operation would be:
5 << 8, which is equivalent to 5 * 256 = 1280. 

This means that the integer value is now represented in a way that allows for 
fixed-point arithmetic, where the lower bits represent the fractional part.
*/
Fixed::Fixed(const int n)
{
    _fixedPointValue = n << _fractionalBits; // Convert integer to fixed-point representation
    std::cout << "Int constructor called" << std::endl; // Print message indicating the integer constructor was called
   /* std::cout << "\n=== Integer Constructor Debug ===" << std::endl;
    std::cout << "Input n: " << n << std::endl;
    _fixedPointValue = n << _fractionalBits;
    std::cout << "After shift (_fixedPointValue): " << _fixedPointValue << std::endl;
    std::cout << "Binary representation: ";
    for (int i = 31; i >= 0; i--)
        std::cout << ((_fixedPointValue >> i) & 1);
    std::cout << std::endl;
    std::cout << "=== End Integer Constructor ===\n" << std::endl;*/
}

/* 
Constructor that initializes the Fixed object with a float value.
The float is rounded and converted to a fixed-point representation.

This line converts a float value 'n' into its fixed-point representation.
The conversion is done by first multiplying 'n' by 2 raised to the power of 
_fractionalBits (which is 8 in this case). This effectively shifts the decimal 
point to the right, allowing for the representation of fractional values in 
the fixed-point format.

The expression (1 << _fractionalBits) computes 2 raised to the power of 
_fractionalBits. For example, if _fractionalBits is 8, this results in 
256 (or 2^8). 

Multiplying 'n' by this value scales the float to the fixed-point format. 
The `roundf` function is then used to round the result to the nearest integer, 
ensuring that the fixed-point representation is accurate and does not lose 
precision due to floating-point arithmetic.

For example, if n is 5.75, the operation would be:
5.75 * (1 << 8) = 5.75 * 256 = 1472. 

This means that the float value is now represented in a way that allows for 
fixed-point arithmetic, where the integer value represents the scaled 
fixed-point number.
*/
Fixed::Fixed(const float n)
{
    _fixedPointValue = roundf(n * (1 << _fractionalBits)); // Convert float to fixed-point representation
    std::cout << "Float constructor called" << std::endl; // Print message indicating the float constructor was called
    std::cout << "n: " << n << std::endl;
    std::cout << "_fixedPointValue: " << _fixedPointValue << std::endl; 
    /*std::cout << "\n=== Integer Constructor Debug ===" << std::endl;
    std::cout << "Input n: " << n << std::endl;
    _fixedPointValue = n << _fractionalBits;
    std::cout << "After shift (_fixedPointValue): " << _fixedPointValue << std::endl;
    std::cout << "Binary representation: ";
    for (int i = 31; i >= 0; i--)
        std::cout << ((_fixedPointValue >> i) & 1);
    std::cout << std::endl;
    std::cout << "=== End Integer Constructor ===\n" << std::endl;*/
}

/* 
Copy constructor for the Fixed class. 
This constructor creates a new Fixed object as a copy of an existing one.
*/
Fixed::Fixed(const Fixed &src) 
{
    std::cout << "Copy constructor called" << std::endl; // Print message indicating the copy constructor was called
    *this = src; // Use the copy assignment operator to copy the value from src to the current object
    std::cout << "src: " << src._fixedPointValue << std::endl;
    std::cout << "_fixedPointValue: " << _fixedPointValue << std::endl;
    /*std::cout << "\n=== Float Constructor Debug ===" << std::endl;
    std::cout << "Input n: " << n << std::endl;
    
    float scaled = n * (1 << _fractionalBits);
    std::cout << "After scaling (n * 256): " << scaled << std::endl;
    
    _fixedPointValue = roundf(scaled);
    std::cout << "After rounding (_fixedPointValue): " << _fixedPointValue << std::endl;
    
    std::cout << "Binary representation: ";
    for (int i = 31; i >= 0; i--)
        std::cout << ((_fixedPointValue >> i) & 1);
    std::cout << std::endl;
    
    float back = (float)_fixedPointValue / (1 << _fractionalBits);
    std::cout << "Converting back to float: " << back << std::endl;
    std::cout << "=== End Float Constructor ===\n" << std::endl;*/
}

/* 
Copy assignment operator for the Fixed class. 
This operator allows one Fixed object to be assigned the value of another.
*/
Fixed &Fixed::operator=(const Fixed &rhs) 
{
    std::cout << "Copy assignment operator called" << std::endl; // Print message indicating the copy assignment operator was called
    std::cout << "this: " << this->_fixedPointValue << std::endl;
    if (this != &rhs) // Check for self-assignment
    {
        this->_fixedPointValue = rhs.getRawBits(); // Copy the raw value from rhs to the current object's fixed-point value
    }
    std::cout << "rhs: " << rhs._fixedPointValue << std::endl;
    std::cout << "_fixedPointValue: " << _fixedPointValue << std::endl;
    return *this; // Return the current object to allow for chained assignments
    /*std::cout << "\n=== Assignment Operator Debug ===" << std::endl;
    std::cout << "Current _fixedPointValue: " << this->_fixedPointValue << std::endl;
    std::cout << "RHS _fixedPointValue: " << rhs.getRawBits() << std::endl;
    
    if (this != &rhs)
        this->_fixedPointValue = rhs.getRawBits();
    
    std::cout << "New _fixedPointValue: " << this->_fixedPointValue << std::endl;
    std::cout << "=== End Assignment Operator ===\n" << std::endl;
    return *this;*/
}

/* 
Destructor for the Fixed class. 
This destructor is called when a Fixed object goes out of scope.
*/
Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl; // Print message indicating the destructor was called
}

/* 
Member function to get the raw fixed-point value. 
This function returns the value of _fixedPointValue.
*/
int Fixed::getRawBits(void) const 
{
    return this->_fixedPointValue; // Return the raw fixed-point value
}

/* 
Member function to set the raw fixed-point value. 
This function sets _fixedPointValue to the provided raw value.
*/
void Fixed::setRawBits(int const raw) 
{
    this->_fixedPointValue = raw; // Set the fixed-point value to the provided raw value
}

/* 
Member function to convert the fixed-point value to a float. 
This function returns the float representation of the fixed-point value.
*/
float Fixed::toFloat(void) const 
{
    return static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits); // Convert fixed-point value to float
    /*float result = static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits);
    std::cout << "\n=== toFloat Debug ===" << std::endl;
    std::cout << "_fixedPointValue: " << _fixedPointValue << std::endl;
    std::cout << "Divided by " << (1 << _fractionalBits) << std::endl;
    std::cout << "Result: " << result << std::endl;
    std::cout << "=== End toFloat ===\n" << std::endl;
    return result;*/
}

/* 
Member function to convert the fixed-point value to an integer. 
This function returns the integer representation of the fixed-point value.
*/
int Fixed::toInt(void) const 
{
    return this->_fixedPointValue >> _fractionalBits; // Convert fixed-point value to integer
}

/* 
Overloaded output stream operator for the Fixed class. 
This function allows for easy printing of Fixed objects.
The syntax for overloading the output stream operator is as follows:
- std::ostream &operator<<(std::ostream &out, const Fixed &fixed):
  - std::ostream &: The return type is a reference to an output stream object, allowing for chaining of output operations.
  - operator<<: This is the name of the function, which is the operator being overloaded (in this case, the << operator).
  - std::ostream &out: The first parameter is a reference to an output stream object (like std::cout), which will be used to output the data.
  - const Fixed &fixed: The second parameter is a constant reference to a Fixed object, which contains the data to be printed.
*/
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) 
{
    out << fixed.toFloat(); // Output the float representation of the fixed object
    // The toFloat() member function converts the fixed-point value to a float, which is then sent to the output stream.
    return out; // Return the output stream
    // This allows for further chaining of output operations, such as:
    // std::cout << fixed1 << fixed2; // This would print both fixed1 and fixed2 in sequence.
}

/* 
Relation to Other Code in the Project:
This file, Fixed.cpp, contains the implementation of the Fixed class defined in Fixed.hpp. 
It includes the definitions of the constructors, destructor, and member functions that manage 
the fixed-point number representation. The main function in main.cpp utilizes this class 
to create instances and demonstrate its functionality, such as object copying and value assignment. 
The output messages in this file help trace the flow of object creation and manipulation, 
providing insight into how the class operates during execution.
*/