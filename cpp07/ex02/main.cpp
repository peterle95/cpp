#include <iostream>
#include <string>
#include "Array.hpp"

// Test function to demonstrate template instantiation
template<typename T>
void printArray(const Array<T>& arr, const std::string& name) {
    std::cout << name << " (size " << arr.size() << "): ";
    for (std::size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "=== Testing Array class template ===" << std::endl;
    
    // Test 1: Default constructor
    std::cout << "\nTest 1: Default constructor" << std::endl;
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;
    
    // Test 2: Parametric constructor
    std::cout << "\nTest 2: Parametric constructor" << std::endl;
    Array<int> intArray(5);
    std::cout << "Int array size: " << intArray.size() << std::endl;
    
    // Initialize elements
    for (std::size_t i = 0; i < intArray.size(); ++i) {
        intArray[i] = static_cast<int>(i * 10);
    }
    printArray(intArray, "Int array");
    
    // Test 3: Copy constructor
    std::cout << "\nTest 3: Copy constructor" << std::endl;
    Array<int> copiedArray(intArray);
    printArray(copiedArray, "Copied array");
    
    // Modify original to test deep copy
    intArray[0] = 999;
    std::cout << "After modifying original[0] to 999:" << std::endl;
    printArray(intArray, "Original array");
    printArray(copiedArray, "Copied array");
    
    // Test 4: Assignment operator
    std::cout << "\nTest 4: Assignment operator" << std::endl;
    Array<int> assignedArray;
    assignedArray = intArray;
    printArray(assignedArray, "Assigned array");
    
    // Modify assigned array to test independence
    assignedArray[1] = 888;
    std::cout << "After modifying assigned[1] to 888:" << std::endl;
    printArray(intArray, "Original array");
    printArray(assignedArray, "Assigned array");
    
    // Test 5: String array
    std::cout << "\nTest 5: String array" << std::endl;
    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "World";
    stringArray[2] = "Template";
    printArray(stringArray, "String array");
    
    // Test 6: Exception handling
    std::cout << "\nTest 6: Exception handling" << std::endl;
    try {
        std::cout << "Accessing valid index [2]: " << intArray[2] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "Accessing invalid index [10]: ";
        std::cout << intArray[10] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "Accessing empty array [0]: ";
        std::cout << emptyArray[0] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test 7: Self-assignment
    std::cout << "\nTest 7: Self-assignment" << std::endl;
    intArray = intArray;
    printArray(intArray, "Self-assigned array");
    
    // Test 8: Assignment with different sizes
    std::cout << "\nTest 8: Assignment with different sizes" << std::endl;
    Array<int> smallArray(2);
    smallArray[0] = 100;
    smallArray[1] = 200;
    printArray(smallArray, "Small array before");
    
    smallArray = intArray;
    printArray(smallArray, "Small array after assignment");
    
    // Test 9: Const array access
    std::cout << "\nTest 9: Const array access" << std::endl;
    const Array<int> constArray(intArray);
    std::cout << "Const array[0]: " << constArray[0] << std::endl;
    std::cout << "Const array size: " << constArray.size() << std::endl;
    
    // Test 10: Memory allocation verification
    std::cout << "\nTest 10: Memory allocation verification" << std::endl;
    {
        Array<int> tempArray(1000);
        std::cout << "Created large array of size: " << tempArray.size() << std::endl;
        tempArray[0] = 42;
        tempArray[999] = 84;
        std::cout << "First element: " << tempArray[0] << std::endl;
        std::cout << "Last element: " << tempArray[999] << std::endl;
    } // tempArray destroyed here
    std::cout << "Large array destroyed successfully" << std::endl;
    
    return 0;
}