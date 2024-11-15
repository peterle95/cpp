/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:05:37 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/14 19:49:52 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*TASK OF THE PROGRAM:
The previous exercise was a good start but our class is pretty useless. It can only
represent the value 0.0.
Add the following public constructors and public member functions to your class:
•A constructor that takes a constant integer as a parameter.
It converts it to the corresponding fixed-point value. The fractional bits value is
initialized to 8 like in exercise 00.
•A constructor that takes a constant floating-point number as a parameter.
It converts it to the corresponding fixed-point value. The fractional bits value is
initialized to 8 like in exercise 00.
•A member function float toFloat( void ) const;
that converts the fixed-point value to a floating-point value.
•A member function int toInt( void ) const;
that converts the fixed-point value to an integer value.
And add the following function to the Fixed class files:
•An overload of the insertion («) operator that inserts a floating-point representation
of the fixed-point number into the output stream object passed as parameter

Running this code:
#include <iostream>
int main( void ) {
Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );
a = Fixed( 1234.4321f );
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
return 0;
}
Should output something similar to:
$> ./a.out
Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Copy assignment operator called
Float constructor called
Copy assignment operator called
Destructor called
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
Destructor called
$>
*/

#include <iostream> // Include the iostream library for input and output operations
#include "Fixed.hpp" // Include the Fixed class header file

/* 
This program demonstrates the usage of the Fixed class, which represents a 
fixed-point number. It creates instances of the Fixed class, showcasing 
the default constructor, copy constructor, and copy assignment operator. 
The program outputs the raw values of the fixed-point numbers to the console.
*/
int main(void) // Main function where the program execution starts
{
    Fixed a; // Create an instance of Fixed using the default constructor
    /* This calls the default constructor of the Fixed class, which initializes 
    _fixedPointValue to 0 and prints "Default constructor called". */

    Fixed const b(10); // Create an instance of Fixed using the integer constructor
    /* This calls the integer constructor of the Fixed class, which converts 
    the integer 10 to its fixed-point representation and prints "Int constructor called". */

    Fixed const c(42.42f); // Create an instance of Fixed using the float constructor
    /* This calls the float constructor of the Fixed class, which converts 
    the float 42.42 to its fixed-point representation and prints "Float constructor called". */

    Fixed const d(b); // Create an instance of Fixed using the copy constructor
    /* This calls the copy constructor of the Fixed class, which copies the 
    value of 'b' into 'd' and prints "Copy constructor called". */

    a = Fixed(1234.4321f); // Assign a new Fixed object to 'a' using the float constructor
    /* This creates a temporary Fixed object from the float 1234.4321, 
    assigns it to 'a', and prints "Float constructor called" followed by 
    "Copy assignment operator called". */

    std::cout << "a is " << a << std::endl; // Output the value of 'a'
    /* This uses the overloaded insertion operator to print the floating-point 
    representation of 'a'. The output will show the value of 'a' in a readable format. */

    std::cout << "b is " << b << std::endl; // Output the value of 'b'
    /* Similar to the previous line, this prints the floating-point representation 
    of 'b', which was initialized with the integer 10. */

    std::cout << "c is " << c << std::endl; // Output the value of 'c'
    /* This prints the floating-point representation of 'c', which was initialized 
    with the float 42.42. */

    std::cout << "d is " << d << std::endl; // Output the value of 'd'
    /* This prints the floating-point representation of 'd', which is a copy of 'b'. */

    std::cout << "a is " << a.toInt() << " as integer" << std::endl; // Output the integer value of 'a'
    /* This calls the toInt() member function, which converts the fixed-point 
    value of 'a' to an integer and prints it. */

    std::cout << "b is " << b.toInt() << " as integer" << std::endl; // Output the integer value of 'b'
    /* Similar to the previous line, this calls toInt() for 'b' and prints 
    its integer representation. */

    std::cout << "c is " << c.toInt() << " as integer" << std::endl; // Output the integer value of 'c'
    /* This calls toInt() for 'c' and prints its integer representation. */

    std::cout << "d is " << d.toInt() << " as integer" << std::endl; // Output the integer value of 'd'
    /* This calls toInt() for 'd' and prints its integer representation. */

    return 0; // End of the main function
    /* The program returns 0, indicating successful execution. */
}

/* 
Relation to Other Code in the Project:
This file, main.cpp, serves as the entry point for the program and demonstrates 
the functionality of the Fixed class defined in Fixed.hpp and implemented in 
Fixed.cpp. It showcases the various constructors and member functions of the 
Fixed class, including the conversion from integers and floats to fixed-point 
representation, as well as the conversion back to integers and floats. The 
output messages help trace the flow of object creation and manipulation, 
providing insight into how the class operates during execution.
*/