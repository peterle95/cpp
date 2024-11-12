/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:55:09 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/12 09:25:49 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* TASK OF THE EXERCISE:
Create a program that takes three parameters in the following order: a filename and
two strings, s1 and s2.
It will open the file <filename> and copies its content into a new file
<filename>.replace, replacing every occurrence of s1 with s2.
Using C file manipulation functions is forbidden and will be considered cheating. All
the member functions of the class std::string are allowed, except replace. Use them
wisely!
Of course, handle unexpected inputs and errors. You have to create and turn in your
own tests to ensure your program works as expected.*/

#include <iostream>
#include <fstream>
#include <string>
#include <stddef.h>
/*The size_t type is actually available through several standard headers, 
including <string>, <iostream>, and <fstream>, which we've already included. 
It's indirectly included through these headers. However, for better code clarity 
and explicit dependencies, we could add <stddef.h> or its C++ equivalent <cstddef> to the includes.*/

/* 
 * The replaceInFile function takes a filename and two strings as parameters.
 * It reads the content of the specified file, replaces all occurrences of the first string (s1) 
 * with the second string (s2), and writes the modified content to a new file named 
 * <filename>.replace. This function is a key part of the project, which implements a command-line 
 * tool for string replacement in files, inspired by the Unix 'sed' command.
 * 
 * The function signature uses the following syntax:
 * - `void`: This indicates that the function does not return a value.
 * - `replaceInFile`: This is the name of the function.
 * - `const std::string& filename`: This parameter is a constant reference to a string representing the filename.
 *   Using a reference avoids copying the string, which is more efficient, and the `const` keyword ensures that 
 *   the function does not modify the original string.
 * - `const std::string& s1`: This parameter is a constant reference to the first string to be replaced.
 * - `const std::string& s2`: This parameter is a constant reference to the second string that will replace occurrences of s1.
 * 
 * The term "function signature" refers to the part of the function declaration that specifies the function's name, 
 * its return type, and its parameters. It defines how the function can be called and what arguments it expects.
 */

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2) 
{
    // The std::ifstream class is used to create an input file stream, which allows us to read data from files. 
    // We pass the filename as a C-style string using c_str(), which is a member function of the std::string class. 
    // This function converts the std::string object to a const char* type, which is required by the std::ifstream constructor 
    // for opening files. This is a common requirement in C++ when dealing with file streams. 
    // Note that we cannot use C++11 features in this program, so we must rely on c_str() for compatibility with older standards.
    // If the file is successfully opened, we can read its contents line by line or character by character.
    // This is essential for our program, as we need to access the file's data to perform the string replacement operation.
    std::ifstream inFile(filename.c_str()); /* Open the input file for reading */
    if (!inFile)  /* Check if the file was successfully opened */
    {
        std::cerr << "Error: Unable to open input file: " << filename << std::endl; /* Print error message if file cannot be opened */
        return; /* Exit the function if the file cannot be opened */
    }

    std::string outFilename = filename + ".replacedString"; /* Create the output filename by appending '.replace' to the original filename */
    std::ofstream outFile(outFilename.c_str()); /* Open the output file for writing */
    if (!outFile)  /* Check if the output file was successfully created */
    {
        std::cerr << "Error: Unable to create output file: " << outFilename << std::endl;
        return;
    }

    std::string line; /* Declare a string variable to hold each line of the input file */
    while (std::getline(inFile, line))  /* Read the input file line by line */
    {
        size_t pos = 0; /* Initialize position variable of type size_t (unsigned integer type used for sizes and array indices)
         * size_t is guaranteed to be large enough to contain the size of the largest possible object */
        while ((pos = line.find(s1, pos)) != std::string::npos) 
        { /* Outer while loop: Continue as long as we can find occurrences of s1 in the line
         * line.find(s1, pos): Searches for s1 in the line, starting from position 'pos'
         * std::string::npos: A constant static member of the std::string class that 
         * represents a value indicating "not found" or "no position".
         * It is returned by the find() method when the specified substring (s1) is not found in the string (line).
         * This value is of type size_t and is defined in the standard library, making it conformant with C++98. 
         * If find() returns npos, it means no more occurrences were found */
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length()); /* Create a new string by:
             * 1. Taking the substring from start to current position (line.substr(0, pos))
             * 2. Adding the replacement string (s2)
             * 3. Taking the rest of the line after the found string (line.substr(pos + s1.length()))
             * Example: If line = "Hello World", s1 = "World", s2 = "Earth"
             * pos would be 6, and the new line would be "Hello Earth" */
            pos += s2.length(); /* Update position to skip over the replacement string
             * This prevents infinite loops by ensuring we start searching 
             * after the string we just inserted */
        }
        outFile << line << std::endl; /* Write the modified line to the output file */
    }

    inFile.close(); /* Close the input file to free up resources. 
    This ensures that any resources associated with the file are released, 
    preventing memory leaks and allowing other processes to access the file if needed. */
    outFile.close(); /* Close the output file to ensure all data is written. 
    This flushes any buffered output to the file, guaranteeing that all 
    changes are saved before the program terminates. */

    std::cout << "Replacement complete. Output written to: " << outFilename << std::endl; 
}

/* 
 * The main function serves as the entry point of the program. 
 * It is responsible for handling command-line arguments, validating input, 
 * and invoking the replaceInFile function to perform the string replacement.
 * The function ensures that the user provides the correct number of arguments 
 * and that the first string to be replaced is not empty. 
 * If the input is valid, it calls the replaceInFile function with the provided arguments.
 */

int main(int argc, char* argv[]) 
{
    if (argc != 4) 
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1]; /* Retrieve the filename from the command-line arguments */
    std::string s1 = argv[2]; /* Retrieve the first string (substring to be replaced) from the command-line arguments */
    std::string s2 = argv[3]; /* Retrieve the second string (substring to replace with) from the command-line arguments */

    /* if (s1.empty())
    {
        std::cerr << "Error: string1 cannot be empty" << std::endl;
        return 1;
    } */
    replaceInFile(filename, s1, s2);

    return 0;
}