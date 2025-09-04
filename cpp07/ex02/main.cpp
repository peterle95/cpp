#include "Array.hpp"

template<typename T>
void printArray(const Array<T>& arr, const std::string& name) 
{
    std::cout << name << " (size " << arr.size() << "): ";
    for (std::size_t i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() 
{
    
    std::cout << "\n\033[91mTest 1:\033[0m Default constructor" << std::endl;
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;
    
    std::cout << "\n\033[91mTest 2:\033[0m Parametric constructor" << std::endl;
    Array<int> intArray(5);
    std::cout << "Int array size: " << intArray.size() << std::endl;
    
    for (std::size_t i = 0; i < intArray.size(); ++i) 
    {
        intArray[i] = static_cast<int>(i);
    }
    printArray(intArray, "Int array");
    
    std::cout << "\n\033[91mTest 3:\033[0m Copy constructor" << std::endl;
    Array<int> copiedArray(intArray);
    printArray(copiedArray, "Copied array");
    
    intArray[0] = 999;
    std::cout << "After modifying original[0] to 999:" << std::endl;
    printArray(intArray, "Original array");
    printArray(copiedArray, "Copied array");
    
    std::cout << "\n\033[91mTest 4:\033[0m Assignment operator" << std::endl;
    Array<int> assignedArray;
    assignedArray = intArray;
    printArray(assignedArray, "Assigned array");
    
    assignedArray[1] = 888;
    std::cout << "After modifying assigned[1] to 888:" << std::endl;
    printArray(intArray, "Original array");
    printArray(assignedArray, "Assigned array");
    
    std::cout << "\n\033[91mTest 5:\033[0m String array" << std::endl;
    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "World";
    stringArray[2] = "Template";
    printArray(stringArray, "String array");

    std::cout << "\n\033[91mTest 6:\033[0m Memory allocation verification" << std::endl;
    {
        Array<int> tempArray(1000);
        std::cout << "Created large array of size: " << tempArray.size() << std::endl;
        tempArray[0] = 42;
        tempArray[999] = 84;
        std::cout << "First element: " << tempArray[0] << std::endl;
        std::cout << "Last element: " << tempArray[999] << std::endl;
    }
    std::cout << "\033[91mLarge array destroyed successfully\033[0m" << std::endl;
    
    std::cout << "\n\033[91mTest 7:\033[0m Exception handling" << std::endl;
    try 
    {
        std::cout << "Accessing valid index [2]: " << intArray[2] << std::endl;
    } catch (const std::exception& e) 
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    try 
    {
        std::cout << "Accessing invalid index [10]: ";
        std::cout << intArray[10] << std::endl;
    } catch (const std::exception& e) 
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    try 
    {
        std::cout << "Accessing empty array [0]: ";
        std::cout << emptyArray[0] << std::endl;
    } catch (const std::exception& e) 
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\n\033[91mTest 8:\033[0m Self-assignment" << std::endl;
    intArray = intArray;
    printArray(intArray, "Self-assigned array");
    
    std::cout << "\n\033[91mTest 9:\033[0m Assignment with different sizes" << std::endl;
    Array<int> smallArray(2);
    smallArray[0] = 100;
    smallArray[1] = 200;
    printArray(smallArray, "Small array before");
    
    smallArray = intArray;
    printArray(smallArray, "Small array after assignment");
    
    std::cout << "\n\033[91mTest 10:\033[0m Const array access" << std::endl;
    const Array<int> constArray(intArray);
    std::cout << "Const array[0]: " << constArray[0] << std::endl;
    std::cout << "Const array size: " << constArray.size() << std::endl;
    
    
    return 0;
}