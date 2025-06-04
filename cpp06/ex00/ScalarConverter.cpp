/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:16:36 by pmolzer           #+#    #+#             */
/*   Updated: 2025/06/03 15:00:13 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ScalarConverter.cpp
#include "ScalarConverter.hpp"

/* ========================================================================== */
/* PRIVATE CONSTRUCTORS AND DESTRUCTOR                                       */
/* These are private to prevent instantiation of the ScalarConverter class   */
/* since it's designed to work only with static methods                      */
/* ========================================================================== */

/**
 * Default constructor - Private to prevent instantiation
 * This class is designed to be used only through static methods,
 * so no objects should be created from it
 */

// Private constructors and destructor - never called
ScalarConverter::ScalarConverter() 
{}

/**
 * Copy constructor - Private to prevent copying
 * Takes a reference to another ScalarConverter object
 * Uses (void)other to suppress unused parameter warning
 */
ScalarConverter::ScalarConverter(const ScalarConverter& other) 
{ 
    (void)other; 
}
    

/**
 * Assignment operator - Private to prevent assignment
 * Takes a reference to another ScalarConverter object
 * Returns a reference to this object (standard assignment operator pattern)
 */
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) 
{ 
    (void)other; 
    return *this; 
}
    
/**
 * Destructor - Private to prevent deletion
 * Called when an object goes out of scope (if it could be created)
 */
ScalarConverter::~ScalarConverter() 
{}

/* ========================================================================== */
/* TYPE DETECTION HELPER METHODS                                             */
/* These static methods determine what type a string literal represents      */
/* ========================================================================== */

/**
 * Determines if a string literal represents a character
 * Accepts two formats: single character 'c' or quoted character 'c'
 * Returns true if the string is a valid character literal
 */
bool ScalarConverter::isChar(const std::string& literal) 
{
     // Check if it's a single character that's not a digit (like 'a', 'Z', etc.)
    // OR if it's in quoted format like 'c' (length 3: quote, char, quote)
    return (literal.length() == 1 && !std::isdigit(literal[0])) || 
           (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

/**
 * Determines if a string literal represents a valid integer
 * Uses strtol to attempt conversion and checks if result is within INT range
 * Returns true if the string is a valid integer literal
 */
bool ScalarConverter::isInt(const std::string& literal) 
{
    // Pointer to track where string parsing stopped
    char* end;
    // Attempt to convert string to long integer (base 10)
    long num = std::strtol(literal.c_str(), &end, 10);
    
    // Check if we parsed the entire string (*end == '\0') 
    // AND the resulting number fits within INT_MIN to INT_MAX range
    return (*end == '\0' && num >= INT_MIN && num <= INT_MAX);
}

/**
 * Determines if a string literal represents a valid float
 * Handles special float literals (nanf, +inff, -inff) and regular floats ending with 'f'
 * Returns true if the string is a valid float literal
 */
bool ScalarConverter::isFloat(const std::string& literal) 
{
    // First check for special float pseudo-literals
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return true;
    
    // Get the length of the string for validation
    size_t len = literal.length();
    // Float literals must be at least 2 characters and end with 'f'
    if (len < 2 || literal[len - 1] != 'f')
        return false;
    
    // Pointer to track where string parsing stopped
    char* end;
    // Try to convert the string to float (strtof handles the 'f' suffix)
    std::strtof(literal.c_str(), &end);
    
    // Check if parsing stopped at 'f' character and that's the end of string
    return (*end == 'f' && *(end + 1) == '\0');
}

/**
 * Determines if a string literal represents a valid double
 * Handles special double literals (nan, +inf, -inf) and regular doubles
 * Returns true if the string is a valid double literal
 */
bool ScalarConverter::isDouble(const std::string& literal) 
{
    // First check for special double pseudo-literals
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return true;
    
    // Pointer to track where string parsing stopped
    char* end;
    // Try to convert the string to double
    std::strtod(literal.c_str(), &end);
    
    // Check if we parsed the entire string (reached end)
    return (*end == '\0');
}

/* ========================================================================== */
/* PRINT HELPER METHODS                                                      */
/* These methods handle the formatted output for each data type              */
/* ========================================================================== */

/**
 * Prints a character value with appropriate formatting
 * Shows the character in quotes if printable, otherwise shows "Non displayable"
 */
void ScalarConverter::printChar(char c) 
{
    // Print the label for character output
    std::cout << "char: ";
    // Check if character is printable (visible ASCII character)
    if (std::isprint(c))
        // Print character enclosed in single quotes
        std::cout << "'" << c << "'" << std::endl;
    else
        // Print message for non-printable characters (like control characters)
        std::cout << "Non displayable" << std::endl;
}

/**
 * Prints an integer value with appropriate formatting
 * Simple integer output with "int: " prefix
 */
void ScalarConverter::printInt(int i) 
{
    // Print the label and integer value
    std::cout << "int: " << i << std::endl;
}

/**
 * Prints a float value with appropriate formatting
 * Uses fixed-point notation with 1 decimal place and 'f' suffix
 */
void ScalarConverter::printFloat(float f) 
{
    // Set precision to 1 decimal place, use fixed-point notation, add 'f' suffix
    std::cout << "float: " << std::setprecision(1) << std::fixed << f << "f" << std::endl;
}

/**
 * Prints a double value with appropriate formatting
 * Uses fixed-point notation with 1 decimal place
 */
void ScalarConverter::printDouble(double d) 
{
    // Set precision to 1 decimal place, use fixed-point notation
    std::cout << "double: " << std::setprecision(1) << std::fixed << d << std::endl;
}

/* ========================================================================== */
/* CONVERSION METHODS                                                         */
/* These methods handle conversion from a specific type to all other types    */
/* ========================================================================== */

/**
 * Converts from a character to all scalar types (char, int, float, double)
 * Character can always be converted to all other types safely
 */
void ScalarConverter::convertFromChar(char c) 
{
    // Print the original character value
    printChar(c);
    // Convert and print as integer (ASCII value)
    printInt(static_cast<int>(c));
    // Convert and print as float
    printFloat(static_cast<float>(c));
    // Convert and print as double
    printDouble(static_cast<double>(c));
}

/**
 * Converts from an integer to all scalar types (char, int, float, double)
 * Character conversion only works if integer is in ASCII range (0-127)
 */
void ScalarConverter::convertFromInt(int i) 
{
    // Check if integer is within printable ASCII character range
    if (i >= 0 && i <= 127)
        // Convert and print as character
        printChar(static_cast<char>(i));
    else
        // Print impossible message for out-of-range values
        std::cout << "char: impossible" << std::endl;
    
    // Print the original integer value
    printInt(i);
    // Convert and print as float
    printFloat(static_cast<float>(i));
    // Convert and print as double
    printDouble(static_cast<double>(i));
}

/**
 * Converts from a float to all scalar types (char, int, float, double)
 * Handles special float values (NaN, infinity) and overflow conditions
 */
void ScalarConverter::convertFromFloat(float f) 
{
    // Check for special float values or out-of-character-range values
    if (std::isnan(f) || std::isinf(f))
        // Special values cannot be converted to characters
        std::cout << "char: impossible" << std::endl;
    else if (f >= 0 && f <= 127)
        // Convert and print as character if within ASCII range
        printChar(static_cast<char>(f));
    else
        // Print impossible for out-of-range values
        std::cout << "char: impossible" << std::endl;
    
    // Check for special values or integer overflow conditions
    if (std::isnan(f) || std::isinf(f) || f > INT_MAX || f < INT_MIN)
        // Cannot convert special values or out-of-range floats to int
        std::cout << "int: impossible" << std::endl;
    else
        // Convert and print as integer (truncates decimal part)
        printInt(static_cast<int>(f));
    
    // Print the original float value
    printFloat(f);
    // Convert and print as double (always safe conversion)
    printDouble(static_cast<double>(f));
}

/**
 * Converts from a double to all scalar types (char, int, float, double)
 * Handles special double values (NaN, infinity) and overflow conditions
 */
void ScalarConverter::convertFromDouble(double d) 
{
    // Check for special double values
    if (std::isnan(d) || std::isinf(d))
        // Special values cannot be converted to characters
        std::cout << "char: impossible" << std::endl;
    else if (d >= 0 && d <= 127)
        // Convert and print as character if within ASCII range
        printChar(static_cast<char>(d));
    else
        // Print impossible for out-of-range values
        std::cout << "char: impossible" << std::endl;
    
    // Check for special values or integer overflow conditions
    if (std::isnan(d) || std::isinf(d) || d > INT_MAX || d < INT_MIN)
        // Cannot convert special values or out-of-range doubles to int
        std::cout << "int: impossible" << std::endl;
    else
        // Convert and print as integer (truncates decimal part)
        printInt(static_cast<int>(d));
    
    // Check if double value exceeds float range
    if (d > __FLT_MAX__ || d < -__FLT_MAX__)
        // Double value too large/small for float representation
        std::cout << "float: impossible" << std::endl;
    else
        // Convert and print as float (may lose precision)
        printFloat(static_cast<float>(d));
    
    // Print the original double value
    printDouble(d);
}

/* ========================================================================== */
/* MAIN CONVERSION METHOD                                                     */
/* This is the public interface that determines input type and converts      */
/* ========================================================================== */

/**
 * Main conversion method - determines the type of input literal and converts it
 * This is the only public method of the class, called from main()
 * Handles all scalar types: char, int, float, double and their special values
 */
void ScalarConverter::convert(const std::string& literal) 
{
    // Test input against each type in order and convert accordingly
    
    // Check if input represents a character literal
    if (isChar(literal)) 
    {
        // Extract character: single char or middle char of 'c' format
        char c = (literal.length() == 1) ? literal[0] : literal[1];
        // Convert from character to all types
        convertFromChar(c);
    }
    // Check if input represents an integer literal
    else if (isInt(literal)) 
    {
        // Convert string to integer using standard library function
        int i = std::atoi(literal.c_str());
        // Convert from integer to all types
        convertFromInt(i);
    }
    // Check if input represents a float literal
    else if (isFloat(literal)) 
    {
        // Variable to store the float value
        float f;
        // Handle special float pseudo-literals
        if (literal == "nanf")
            // Set to Not-a-Number float value
            f = std::numeric_limits<float>::quiet_NaN();
        else if (literal == "+inff")
            // Set to positive infinity float value
            f = std::numeric_limits<float>::infinity();
        else if (literal == "-inff")
            // Set to negative infinity float value
            f = -std::numeric_limits<float>::infinity();
        else
            // Convert regular float literal using standard library function
            f = std::strtof(literal.c_str(), NULL);
        // Convert from float to all types
        convertFromFloat(f);
    }
    // Check if input represents a double literal
    else if (isDouble(literal)) 
    {
        // Variable to store the double value
        double d;
        // Handle special double pseudo-literals
        if (literal == "nan")
            // Set to Not-a-Number double value
            d = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inf")
            // Set to positive infinity double value
            d = std::numeric_limits<double>::infinity();
        else if (literal == "-inf")
            // Set to negative infinity double value
            d = -std::numeric_limits<double>::infinity();
        else
            // Convert regular double literal using standard library function
            d = std::strtod(literal.c_str(), NULL);
        // Convert from double to all types
        convertFromDouble(d);
    }
    // Input doesn't match any recognized scalar type format
    else 
    {
        // Print error message for invalid input
        std::cout << "Invalid input format" << std::endl;
    }
}