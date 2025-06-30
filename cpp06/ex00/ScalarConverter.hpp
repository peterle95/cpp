/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:16:05 by pmolzer           #+#    #+#             */
/*   Updated: 2025/06/29 12:50:27 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ScalarConverter.hpp
#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <limits> 
#include <cctype>
#include <string>
#include <sstream>
#include <iomanip>

class ScalarConverter 
{
private:
    // Private constructor to prevent instantiation
    ScalarConverter();
    // Private copy constructor
    ScalarConverter(const ScalarConverter& other);
    // Private assignment operator
    ScalarConverter& operator=(const ScalarConverter& other);
    // Private destructor
    ~ScalarConverter();

    // Helper methods for type detection
    static bool isChar(const std::string& literal);
    static bool isInt(const std::string& literal);
    static bool isFloat(const std::string& literal);
    static bool isDouble(const std::string& literal);
    
    // Conversion methods
    static void convertFromChar(char c);
    static void convertFromInt(int i);
    static void convertFromFloat(float f);
    static void convertFromDouble(double d);
    
    // Print methods
    static void printChar(char c);
    static void printInt(int i);
    static void printFloat(float f);
    static void printDouble(double d);

public:
    // The only public method - convert
    /*Static utility pattern: 
    Making convert static allows it to be called directly on the class 
    (ScalarConverter::convert(literal)) without needing an object instance.*/
    static void convert(const std::string& literal);
};

#endif