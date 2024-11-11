/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:55:09 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/11 10:05:41 by pmolzer          ###   ########.fr       */
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

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2) 
{
    std::ifstream inFile(filename.c_str());
    if (!inFile) 
    {
        std::cerr << "Error: Unable to open input file: " << filename << std::endl;
        return;
    }

    std::string outFilename = filename + ".replace";
    std::ofstream outFile(outFilename.c_str());
    if (!outFile) 
    {
        std::cerr << "Error: Unable to create output file: " << outFilename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) 
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos += s2.length();
        }
        outFile << line << std::endl;
    }

    inFile.close();
    outFile.close();

    std::cout << "Replacement complete. Output written to: " << outFilename << std::endl;
}

int main(int argc, char* argv[]) 
{
    if (argc != 4) 
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty()) 
    {
        std::cerr << "Error: string1 cannot be empty" << std::endl;
        return 1;
    }

    replaceInFile(filename, s1, s2);

    return 0;
}