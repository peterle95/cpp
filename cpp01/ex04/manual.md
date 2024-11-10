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
  - `filename`: The name of the file to read from.
  - `s1`: The substring to be replaced.
  - `s2`: The substring to replace `s1` with.

### Opening the Input File
The function attempts to open the specified input file:

```cpp
std::ifstream inFile(filename.c_str());
```
- If the file cannot be opened, an error message is displayed, and the function returns early.

### Creating the Output File
An output file is created with the same name as the input file, but with `.replace` appended:

```cpp
std::ofstream outFile(outFilename.c_str());
```
- Similar to the input file, if the output file cannot be created, an error message is displayed.

### Reading and Replacing Content
The function reads the input file line by line:

```cpp
while (std::getline(inFile, line))
```
- For each line, it searches for occurrences of `s1` and replaces them with `s2`:

```cpp
while ((pos = line.find(s1, pos)) != std::string::npos) {
    line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
    pos += s2.length();
}
```
- This loop continues until all occurrences of `s1` in the line are replaced.

### Writing to the Output File
After processing each line, the modified line is written to the output file:

```cpp
outFile << line << std::endl;
```

### Closing Files
Finally, both the input and output files are closed, and a completion message is printed:

```cpp
std::cout << "Replacement complete. Output written to: " << outFilename << std::endl;
```

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
