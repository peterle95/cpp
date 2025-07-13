/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:16:36 by pmolzer           #+#    #+#             */
/*   Updated: 2025/07/13 12:54:14 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() 
{}

ScalarConverter::ScalarConverter(const ScalarConverter& other) 
{ 
    (void)other; 
}
    
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) 
{ 
    (void)other; 
    return *this; 
}
    
ScalarConverter::~ScalarConverter() 
{}


bool ScalarConverter::isChar(const std::string& literal) 
{
    return (literal.length() == 1 && !std::isdigit(literal[0])) || 
           (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

bool ScalarConverter::isInt(const std::string& literal) 
{
    char* end;
    long num = std::strtol(literal.c_str(), &end, 10);
    
    return (*end == '\0' && num >= INT_MIN && num <= INT_MAX);
}

bool ScalarConverter::isFloat(const std::string& literal) 
{
    // Check for special float literals
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return true;
    
    size_t len = literal.length();
    if (len < 2 || literal[len - 1] != 'f')
        return false;
    
    char* end;
    std::strtof(literal.c_str(), &end);
    
    return (*end == 'f' && *(end + 1) == '\0');
}

bool ScalarConverter::isDouble(const std::string& literal) 
{
    if (literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "inf")
        return true;
    
    char* end;
    std::strtod(literal.c_str(), &end);
    
    return (*end == '\0');
}

void ScalarConverter::printChar(char c) 
{
    std::cout << "char: ";
    if (std::isprint(c))
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
}

void ScalarConverter::printInt(int i) 
{
    std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f) 
{
    std::cout << "float: " << std::setprecision(1) << std::fixed << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d) 
{
    std::cout << "double: " << std::setprecision(1) << std::fixed << d << std::endl;
}

void ScalarConverter::convertFromChar(char c) 
{
    printChar(c);
    printInt(static_cast<int>(c));
    printFloat(static_cast<float>(c));
    printDouble(static_cast<double>(c));
}

void ScalarConverter::convertFromInt(int i) 
{
    if (i >= 0 && i <= 127)
        printChar(static_cast<char>(i));
    else
        std::cout << "char: impossible" << std::endl;
    
    printInt(i);
    printFloat(static_cast<float>(i));
    printDouble(static_cast<double>(i));
}

void ScalarConverter::convertFromFloat(float f) 
{
    if (std::isnan(f) || std::isinf(f))
        std::cout << "char: impossible" << std::endl;
    else if (f >= 0 && f <= 127)
        printChar(static_cast<char>(f));
    else
        std::cout << "char: impossible" << std::endl;
    
    if (std::isnan(f) || std::isinf(f) || f > INT_MAX || f < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        printInt(static_cast<int>(f));
    
    printFloat(f);
    printDouble(static_cast<double>(f));
}

void ScalarConverter::convertFromDouble(double d) 
{
    if (std::isnan(d) || std::isinf(d))
        std::cout << "char: impossible" << std::endl;
    else if (d >= 0 && d <= 127)
        printChar(static_cast<char>(d));
    else
        std::cout << "char: impossible" << std::endl;
    
    if (std::isnan(d) || std::isinf(d) || d > INT_MAX || d < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        printInt(static_cast<int>(d));
    
    
    if (std::isnan(d) || std::isinf(d))
        printFloat(static_cast<float>(d));
    else if (d > __FLT_MAX__ || d < -__FLT_MAX__)
        std::cout << "float: impossible" << std::endl;
    else
        printFloat(static_cast<float>(d));
    
    printDouble(d);
}

void ScalarConverter::convert(const std::string& literal) 
{
    if (isChar(literal)) 
    {
        char c = (literal.length() == 1) ? literal[0] : literal[1];
        convertFromChar(c);
    }
    else if (isInt(literal)) 
    {
        int i = std::atoi(literal.c_str());
        convertFromInt(i);
    }
    else if (isFloat(literal)) 
    {
        float f;
        if (literal == "nanf")
            f = std::numeric_limits<float>::quiet_NaN();
        else if (literal == "+inff")
            f = std::numeric_limits<float>::infinity();
        else if (literal == "-inff")
            f = -std::numeric_limits<float>::infinity();
        else
            f = std::strtof(literal.c_str(), NULL);
        convertFromFloat(f);
    }
    else if (isDouble(literal)) 
    {
        double d;
        if (literal == "nan")
            d = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inf" || literal == "inf")
            d = std::numeric_limits<double>::infinity();
        else if (literal == "-inf")
            d = -std::numeric_limits<double>::infinity();
        else
            d = std::strtod(literal.c_str(), NULL);
        convertFromDouble(d);
    }
    else 
    {
        std::cout << "Invalid input format" << std::endl;
    }
}