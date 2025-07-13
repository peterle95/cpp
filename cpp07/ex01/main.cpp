#include <iostream>  // Include standard input/output stream library for cout
#include <string>    // Include string library for std::string type
#include "iter.hpp"  // Include our custom header file containing the iter template function

/*TASK:
Implement a function template iter that takes 3 parameters and returns nothing.
- The first parameter is the address of an array.
- The second one is the length of the array.
- The third one is a function that will be called on every element of the array.
Submit a main.cpp file that contains your tests. Provide enough code to generate a
test executable.
Your iter function template must work with any type of array. The third parameter
can be an instantiated function template.
The function passed as the third parameter may take its argument by const reference
or non-const reference, depending on the context.
Think carefully about how to support both const and non-const
elements in your iter function.
*/

// Function template that takes a non-const reference parameter
// This allows the function to modify the value it receives
// Template parameter T makes this work with any type (int, float, string, etc.)
template<typename T>
void increment(T& value) {
    ++value;  // Pre-increment operator: increases value by 1
              // Works with any type that has ++ operator overloaded
}

// Function template that takes a const reference parameter
// The const keyword means this function cannot modify the value
// This is safer for read-only operations and works with const arrays
template<typename T>
void print(const T& value) {
    std::cout << value << " ";  // Output the value followed by a space
                                // Uses << operator which must be defined for type T
}

// Specific function (not a template) that works only with std::string
// Takes const reference because it only reads the string, doesn't modify it
void printString(const std::string& str) {
    std::cout << "\"" << str << "\" ";  // Print string with quotes around it
                                        // Uses string concatenation with << operator
}

// Function that modifies strings by adding exclamation mark
// Takes non-const reference because it needs to modify the string
void addExclamation(std::string& str) {
    str += "!";  // Append exclamation mark to the string
                 // Uses += operator for string concatenation
}

// Specific function for integers that doubles their value
// Takes non-const reference to allow modification
void doubleValue(int& value) {
    value *= 2;  // Multiply value by 2 and store result back in value
                 // Uses compound assignment operator *=
}

// Main function - entry point of the program
int main() {
    // Output header for the test program
    std::cout << "=== Testing iter function template ===" << std::endl;
    
    // Test 1: Integer array with print function
    std::cout << "\nTest 1: Integer array - printing" << std::endl;
    
    // Create an integer array with 5 elements
    // C-style array initialization with values in braces
    int numbers[] = {1, 2, 3, 4, 5};
    
    // Calculate array size using sizeof trick
    // sizeof(numbers) gives total bytes, sizeof(numbers[0]) gives bytes per element
    // Division gives number of elements
    std::size_t numbersSize = sizeof(numbers) / sizeof(numbers[0]);
    
    std::cout << "Original array: ";
    // Call iter function with:
    // - numbers: array address (automatically converted to pointer)
    // - numbersSize: number of elements
    // - print<int>: template function instantiated for int type
    // :: prefix ensures we call global iter function, not any member function
    ::iter(numbers, numbersSize, print<int>);
    std::cout << std::endl;  // Print newline after the array output
    
    // Test 2: Integer array with increment function
    std::cout << "\nTest 2: Integer array - incrementing" << std::endl;
    
    // Call iter with increment function - this will modify each element
    // increment<int> instantiates the template for int type
    ::iter(numbers, numbersSize, increment<int>);
    
    std::cout << "After increment: ";
    // Print the modified array to show increment worked
    ::iter(numbers, numbersSize, print<int>);
    std::cout << std::endl;
    
    // Test 3: Integer array with doubleValue function
    std::cout << "\nTest 3: Integer array - doubling" << std::endl;
    
    // Call iter with doubleValue function - multiplies each element by 2
    // doubleValue is not a template, it's a regular function for int only
    ::iter(numbers, numbersSize, doubleValue);
    
    std::cout << "After doubling: ";
    // Print the array after doubling operation
    ::iter(numbers, numbersSize, print<int>);
    std::cout << std::endl;
    
    // Test 4: String array with const function
    std::cout << "\nTest 4: String array - printing" << std::endl;
    
    // Create array of std::string objects
    // Each string is initialized with a literal value
    std::string words[] = {"hello", "world", "template", "functions"};
    
    // Calculate size of string array using same technique as before
    std::size_t wordsSize = sizeof(words) / sizeof(words[0]);
    
    std::cout << "Original strings: ";
    // Call iter with printString function (not a template)
    // printString specifically handles std::string type
    ::iter(words, wordsSize, printString);
    std::cout << std::endl;
    
    // Test 5: String array with non-const function
    std::cout << "\nTest 5: String array - modifying" << std::endl;
    
    // Call iter with addExclamation function - modifies each string
    // This demonstrates that iter can work with functions that modify elements
    ::iter(words, wordsSize, addExclamation);
    
    std::cout << "After adding exclamation: ";
    // Print the modified strings to show the change
    ::iter(words, wordsSize, printString);
    std::cout << std::endl;
    
    // Test 6: Float array
    std::cout << "\nTest 6: Float array" << std::endl;
    
    // Create array of float values
    // 'f' suffix indicates float literals (not double)
    float floats[] = {1.1f, 2.2f, 3.3f, 4.4f};
    
    // Calculate size of float array
    std::size_t floatsSize = sizeof(floats) / sizeof(floats[0]);
    
    std::cout << "Original floats: ";
    // Use template function instantiated for float type
    ::iter(floats, floatsSize, print<float>);
    std::cout << std::endl;
    
    std::cout << "After increment: ";
    // First increment all float values
    ::iter(floats, floatsSize, increment<float>);
    // Then print the incremented values
    ::iter(floats, floatsSize, print<float>);
    std::cout << std::endl;
    
    // Test 7: Const array (should only work with const functions)
    std::cout << "\nTest 7: Const array" << std::endl;
    
    // Create const array - elements cannot be modified after initialization
    // const keyword makes the entire array read-only
    const int constNumbers[] = {10, 20, 30, 40, 50};
    
    // Calculate size of const array
    std::size_t constNumbersSize = sizeof(constNumbers) / sizeof(constNumbers[0]);
    
    std::cout << "Const array: ";
    // Only const functions can be used with const arrays
    // print<int> takes const reference, so it works with const arrays
    ::iter(constNumbers, constNumbersSize, print<int>);
    std::cout << std::endl;
    
    // This would cause compilation error because increment tries to modify const data:
    // ::iter(constNumbers, constNumbersSize, increment<int>);
    // The compiler would reject this because increment takes non-const reference
    
    // Test 8: Empty array
    std::cout << "\nTest 8: Empty array (length 0)" << std::endl;
    
    // Create null pointer to simulate empty array
    // nullptr is C++11 null pointer literal (safer than NULL)
    int* emptyArray = NULL;
    
    // Call iter with null pointer and length 0
    // Our iter function should handle this gracefully (check for null pointer)
    ::iter(emptyArray, 0, print<int>);
    
    std::cout << "Empty array test completed (no output expected)" << std::endl;
    
    // Return 0 to indicate successful program execution
    // This is the standard way to end main() function
    return 0;
}