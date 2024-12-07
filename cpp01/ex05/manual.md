# Harl Program Step-by-Step Guide

## Overview
The Harl program is designed to simulate a character named Harl who makes complaints at different levels: DEBUG, INFO, WARNING, and ERROR. Each level corresponds to a specific type of message that Harl can express. The program uses pointers to member functions to dynamically call the appropriate complaint function based on user input.

## Step-by-Step Explanation

### 1. Class Definition
The program defines a class named `Harl` in `Harl.hpp`. This class contains:
- **Private Member Functions**: 
  - `void debug()`: Outputs a debug message.
  - `void info()`: Outputs an informational message.
  - `void warning()`: Outputs a warning message.
  - `void error()`: Outputs an error message.
  
- **Public Member Function**:
  - `void complain(std::string level)`: This function takes a string parameter representing the complaint level and calls the corresponding private member function.

### 2. Member Function Implementations
In `Harl.cpp`, the member functions are implemented:
- Each function outputs a predefined message to the console. For example, the `debug()` function outputs a message about enjoying extra bacon in a burger.

### 3. Using Pointers to Member Functions
The `complain` function uses an array of pointers to member functions:
```cpp
void (Harl::*complaints[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
```
This array holds pointers to the four complaint functions. The program also defines an array of strings that correspond to the complaint levels:
```cpp
std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
```
#### 3.1 Calling Member Functions
When a valid complaint level is provided, the corresponding member function is called using the pointer syntax:
```cpp
   (harl.*complaints[i])();
```
Here, `harl` is an instance of the `Harl` class, `complaints[i]` is a pointer to a member function of the `Harl` class, and `()` is used to call the member function.

### 4. Handling Complaints
The `complain` function iterates through the `levels` array to find a match with the input `level`. If a match is found, it calls the corresponding member function using the pointer:
```cpp
(this->*complaints[i])();
```
If no match is found, it outputs "Invalid complaint level".

### 5. Main Function
The `main` function in `main.cpp` serves as the entry point of the program:
- An instance of the `Harl` class is created:
```cpp
Harl harl;
```
- The program then demonstrates Harl's complaints at each level by calling the `complain` function with different strings ("DEBUG", "INFO", "WARNING", "ERROR").
- It also tests an invalid level ("INVALID") to show how the program handles incorrect input.

### 6. Compilation and Execution
The program uses a `Makefile` to manage the build process:
- The `Makefile` specifies the compiler (`c++`), compiler flags, source files, and rules for building the executable.
- The `all` target compiles the program, while `clean` and `fclean` targets are used to remove object files and the executable.

### Conclusion
The Harl program effectively demonstrates the use of classes, member functions, and pointers to member functions in C++. It provides a clear structure for handling different complaint levels without resorting to complex conditional statements, making the code more maintainable and readable.
