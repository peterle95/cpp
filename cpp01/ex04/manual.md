# Step-by-Step Guide to the Project

## Overview
This project implements a simple command-line tool that replaces all occurrences of a specified substring in a file with another substring. The tool is named `sed`, inspired by the Unix stream editor.

## Step 1: Project Structure
The project consists of the following files:
- `main.cpp`: The main source file containing the implementation of the replacement logic.
- `Makefile`: A file used to automate the build process.

## Step 2: Understanding `main.cpp`
### Includes
The file begins by including necessary headers:

```cpp
#include <iostream>
#include <fstream>
#include <string>
```
- `iostream`: For input and output operations.
- `fstream`: For file handling (reading from and writing to files).
- `string`: To use the `std::string` class for string manipulation.

### Function Definition: `replaceInFile`
The core functionality is encapsulated in the `replaceInFile` function:

```cpp
void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2)
```
- **Parameters**:
  - `filename`: This parameter is of type `std::string` and represents the name of the file that the function will read from. It is expected to be a valid path to a file on the filesystem. The function will attempt to open this file for reading.
  - `s1`: This parameter is also of type `std::string` and represents the substring that the function will search for within the contents of the specified file. This is the text that will be replaced.
  - `s2`: This parameter is of type `std::string` and represents the substring that will replace every occurrence of `s1` found in the file. 

### Functionality
The `replaceInFile` function performs the following tasks:

1. **File Opening**: 
   - The function first attempts to open the input file specified by `filename` using an `std::ifstream` object. If the file cannot be opened (for example, if it does not exist or the program lacks permission to read it), an error message is printed to the standard error stream, and the function returns early to prevent further execution.

2. **Output File Creation**:
   - If the input file is successfully opened, the function constructs the name of the output file by appending `.replace` to the original filename. It then attempts to create an `std::ofstream` object for writing to this new file. If the output file cannot be created, another error message is printed, and the function exits.

3. **Reading and Replacing Content**:
   - The function reads the input file line by line using a loop that utilizes `std::getline()`. For each line read, it searches for occurrences of the substring `s1` using the `find` method of `std::string`. 
   - If `s1` is found, the function constructs a new string by concatenating the parts of the line before and after the found substring, inserting `s2` in its place. This process continues until all occurrences of `s1` in the line have been replaced.

4. **Writing to the Output File**:
   - After processing each line, the modified line is written to the output file using the `<<` operator of the `std::ofstream` object. Each line is followed by a newline character to maintain the original file's structure.

5. **Closing Files**:
   - Once all lines have been processed, the function closes both the input and output files to free up system resources. It also prints a completion message indicating that the replacement process is finished and specifies the name of the output file.

### Syntax Explanation
- The function is defined with a return type of `void`, meaning it does not return any value. 
- The parameters are passed by reference (indicated by the `&` symbol), which allows the function to access the original strings without making copies, improving efficiency.
- The use of `const` before the parameter types indicates that these parameters will not be modified within the function, ensuring that the original values remain unchanged.

This function is a key component of the program, enabling the core functionality of reading a file, replacing specified substrings, and writing the results to a new file.

## Step 3: The `main` Function
The `main` function serves as the entry point of the program:

```cpp
int main(int argc, char* argv[])
```
- It checks if the correct number of arguments is provided (the program name, input filename, and two strings):

```cpp
if (argc != 4)
```
- If not, it displays a usage message and exits.

### Retrieving Command-Line Arguments
The input filename and the strings to be replaced are retrieved from the command-line arguments:

```cpp
std::string filename = argv[1];
std::string s1 = argv[2];
std::string s2 = argv[3];
```

### Validating Input
The program checks if `s1` is empty, as replacing an empty string does not make sense:

```cpp
if (s1.empty())
```
- If it is empty, an error message is displayed.

### Calling the Replacement Function
Finally, the `replaceInFile` function is called with the provided arguments:

```cpp
replaceInFile(filename, s1, s2);
```

## Conclusion
This project provides a simple yet effective way to replace substrings in a file using C++. By following the steps outlined above, you can understand how the program works and how to build and run it.
