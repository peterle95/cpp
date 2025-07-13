#include <iostream>
#include <string>
#include "Array.hpp"

#include <iostream>
#include <string>
#include "Array.hpp"

/*TASK:
Develop a class template Array that contains elements of type T and that implements
the following behavior and functions:
- Construction with no parameter: Creates an empty array.
- Construction with an unsigned int n as a parameter: Creates an array of n elements
initialized by default.
Tip: Try to compile int * a = new int(); then display *a.
- Construction by copy and assignment operator. In both cases, modifying either the
original array or its copy after copying musn't affect the other array.
- You MUST use the operator new[] to allocate memory. Preventive allocation (al￾locating memory in advance) is forbidden. Your program must never access non￾allocated memory.
- Elements can be accessed through the subscript operator: [ ].
- When accessing an element with the [ ] operator, if its index is out of bounds, an
std::exception is thrown.
- A member function size() that returns the number of elements in the array. This
member function takes no parameters and must not modify the current instance.
As usual, ensure everything works as expected and turn in a main.cpp file that con￾tains your tests.
*/

// Template function to demonstrate template instantiation and test array printing
// This function works with any type T that can be output to std::cout
template<typename T>
void printArray(const Array<T>& arr, const std::string& name) {
    // Display array name and size information
    std::cout << name << " (size " << arr.size() << "): ";
    
    // Iterate through all elements using size_t (unsigned integer type)
    // This prevents signed/unsigned comparison warnings
    for (std::size_t i = 0; i < arr.size(); ++i) {
        // Use const version of operator[] since arr is const reference
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "=== Testing Array class template ===" << std::endl;
    
    // Test 1: Default constructor
    // Tests: Array<T>::Array() - creates empty array with _size = 0, _elements = NULL
    std::cout << "\nTest 1: Default constructor" << std::endl;
    Array<int> emptyArray;  // Calls default constructor
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;  // Should print 0
    
    // Test 2: Parametric constructor
    // Tests: Array<T>::Array(unsigned int n) - creates array of n elements using new[]
    std::cout << "\nTest 2: Parametric constructor" << std::endl;
    Array<int> intArray(5);  // Creates array with 5 int elements, default-initialized to 0
    std::cout << "Int array size: " << intArray.size() << std::endl;  // Should print 5
    
    // Initialize elements using non-const operator[]
    // This tests: T& Array<T>::operator[](int index)
    for (std::size_t i = 0; i < intArray.size(); ++i) {
        // static_cast ensures proper type conversion from size_t to int
        intArray[i] = static_cast<int>(i * 10);  // Assigns: 0, 10, 20, 30, 40
    }
    printArray(intArray, "Int array");  // Uses const operator[] in printArray function
    
    // Test 3: Copy constructor
    // Tests: Array<T>::Array(const Array& other) - deep copy with separate memory allocation
    std::cout << "\nTest 3: Copy constructor" << std::endl;
    Array<int> copiedArray(intArray);  // Creates independent copy with same values
    printArray(copiedArray, "Copied array");  // Should show same values as intArray
    
    // Test deep copy by modifying original
    // This verifies that copied array has its own memory (not sharing pointers)
    intArray[0] = 999;  // Change first element of original
    std::cout << "After modifying original[0] to 999:" << std::endl;
    printArray(intArray, "Original array");    // Should show [999, 10, 20, 30, 40]
    printArray(copiedArray, "Copied array");   // Should still show [0, 10, 20, 30, 40]
    
    // Test 4: Assignment operator
    // Tests: Array<T>& Array<T>::operator=(const Array& other)
    std::cout << "\nTest 4: Assignment operator" << std::endl;
    Array<int> assignedArray;  // Start with empty array
    assignedArray = intArray;  // Assignment: deletes old memory, allocates new, copies values
    printArray(assignedArray, "Assigned array");  // Should match current intArray
    
    // Test independence after assignment (verifies deep copy in operator=)
    assignedArray[1] = 888;  // Modify assigned array
    std::cout << "After modifying assigned[1] to 888:" << std::endl;
    printArray(intArray, "Original array");     // Should be unchanged
    printArray(assignedArray, "Assigned array"); // Should show the modification
    
    // Test 5: String array
    // Tests template instantiation with different type (std::string)
    std::cout << "\nTest 5: String array" << std::endl;
    Array<std::string> stringArray(3);  // Creates Array<std::string> with 3 elements
    // std::string default constructor creates empty strings
    stringArray[0] = "Hello";    // Assignment to string elements
    stringArray[1] = "World";
    stringArray[2] = "Template";
    printArray(stringArray, "String array");  // Tests template function with std::string
    
    // Test 6: Exception handling
    // Tests: OutOfBoundsException throwing in operator[]
    std::cout << "\nTest 6: Exception handling" << std::endl;
    
    // Test valid access (should not throw)
    try {
        std::cout << "Accessing valid index [2]: " << intArray[2] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test invalid access - index too large (should throw OutOfBoundsException)
    try {
        std::cout << "Accessing invalid index [10]: ";
        std::cout << intArray[10] << std::endl;  // intArray size is 5, so index 10 is invalid
    } catch (const std::exception& e) {
        // OutOfBoundsException inherits from std::exception
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test access on empty array (should throw OutOfBoundsException)
    try {
        std::cout << "Accessing empty array [0]: ";
        std::cout << emptyArray[0] << std::endl;  // emptyArray has size 0
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test 7: Self-assignment
    // Tests assignment operator's self-assignment protection (if (this != &other))
    std::cout << "\nTest 7: Self-assignment" << std::endl;
    intArray = intArray;  // Should not cause memory issues due to self-assignment check
    printArray(intArray, "Self-assigned array");  // Should remain unchanged
    
    // Test 8: Assignment with different sizes
    // Tests memory reallocation in assignment operator
    std::cout << "\nTest 8: Assignment with different sizes" << std::endl;
    Array<int> smallArray(2);  // Create smaller array
    smallArray[0] = 100;
    smallArray[1] = 200;
    printArray(smallArray, "Small array before");
    
    // Assignment from larger to smaller array
    // operator= should: delete old memory, allocate new memory of correct size, copy values
    smallArray = intArray;  // smallArray now becomes size 5 with intArray's values
    printArray(smallArray, "Small array after assignment");
    
    // Test 9: Const array access
    // Tests: const T& Array<T>::operator[](int index) const
    std::cout << "\nTest 9: Const array access" << std::endl;
    const Array<int> constArray(intArray);  // Copy constructor creates const array
    // Const array can only use const version of operator[]
    std::cout << "Const array[0]: " << constArray[0] << std::endl;  // Uses const operator[]
    std::cout << "Const array size: " << constArray.size() << std::endl;  // size() is const
    
    // Test 10: Memory allocation verification
    // Tests proper memory management with larger arrays
    std::cout << "\nTest 10: Memory allocation verification" << std::endl;
    {
        // Create large array in local scope to test memory allocation/deallocation
        Array<int> tempArray(1000);  // Allocates memory for 1000 integers
        std::cout << "Created large array of size: " << tempArray.size() << std::endl;
        
        // Test that memory is properly accessible
        tempArray[0] = 42;      // First element
        tempArray[999] = 84;    // Last valid element (size-1)
        std::cout << "First element: " << tempArray[0] << std::endl;
        std::cout << "Last element: " << tempArray[999] << std::endl;
        
    } // tempArray goes out of scope here - destructor should properly delete[] memory
    
    std::cout << "Large array destroyed successfully" << std::endl;
    
    return 0;
    // All arrays (emptyArray, intArray, copiedArray, assignedArray, stringArray, 
    // smallArray, constArray) are destroyed here by their destructors
    // Each destructor calls delete[] on their _elements pointer
}