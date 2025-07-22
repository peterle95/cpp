# Array Template Class Manual

## Project Overview

This project implements a generic Array template class in C++98 that provides dynamic array functionality with bounds checking and proper memory management. The Array class template can hold elements of any type T and provides safe array operations with exception handling.

## Core Functionality

The Array template class provides:
- Dynamic memory allocation for arrays of any type
- Copy constructor and assignment operator with deep copying
- Bounds-checked element access via subscript operator
- Exception throwing for out-of-bounds access
- Proper memory management with RAII principles

## Main Files

### Which Main File to Use

The project includes two main files:

1. **`main.cpp`** - Your comprehensive test file (recommended for development/testing)
2. **`main_subject.cpp`** - Subject-provided validation test

**Use `main.cpp` for development and understanding** - it contains detailed tests that demonstrate all functionality step by step.

**The subject provided `main_subject.cpp`** as a validation test to ensure your Array implementation meets the specific requirements. This file tests edge cases like negative indices and boundary conditions that are critical for the assignment evaluation.

## Program Execution Flow (main.cpp)

### Step-by-Step Breakdown

#### 1. Template Instantiation and Helper Function
```cpp
template<typename T>
void printArray(const Array<T>& arr, const std::string& name)
```
- A helper function template that prints array contents
- Demonstrates template usage and const-correctness

#### 2. Test 1: Default Constructor
```cpp
Array<int> emptyArray;
```
- Creates an empty array using `Array<T>::Array()`
- Sets `_elements = NULL` and `_size = 0`
- No memory allocation occurs
- Prints size (should be 0)

#### 3. Test 2: Parametric Constructor
```cpp
Array<int> intArray(5);
```
- Creates array with 5 elements using `Array<T>::Array(unsigned int n)`
- Allocates memory: `_elements = new T[5]`
- Elements are default-initialized (0 for int)
- Loop fills array with values (0, 10, 20, 30, 40)
- Each assignment calls `operator[](int index)` with bounds checking

#### 4. Test 3: Copy Constructor
```cpp
Array<int> copiedArray(intArray);
```
- Invokes `Array<T>::Array(const Array& other)`
- Allocates new memory block of same size
- Performs deep copy: `_elements[i] = other._elements[i]`
- Modifies original array to verify independence
- Demonstrates that copies are truly independent

#### 5. Test 4: Assignment Operator
```cpp
assignedArray = intArray;
```
- Calls `Array<T>& operator=(const Array& other)`
- Deletes existing memory: `delete[] _elements`
- Allocates new memory matching source size
- Performs element-by-element copy
- Includes self-assignment protection
- Modifies assigned array to verify independence

#### 6. Test 5: String Template Instantiation
```cpp
Array<std::string> stringArray(3);
```
- Demonstrates template works with complex types
- String objects are properly constructed and assigned
- Shows template's type-agnostic nature

#### 7. Test 6: Exception Handling
```cpp
try { intArray[10]; } catch(const std::exception& e) { ... }
```
- Tests bounds checking in `operator[](int index)`
- Valid access (index 2) succeeds normally
- Invalid access (index 10) throws `OutOfBoundsException`
- Empty array access (index 0) throws exception
- Demonstrates both const and non-const operator[] versions

#### 8. Test 7: Self-Assignment
```cpp
intArray = intArray;
```
- Tests self-assignment protection in assignment operator
- `if (this != &other)` prevents self-destruction
- Array remains unchanged and valid

#### 9. Test 8: Size Change Assignment
```cpp
smallArray = intArray;
```
- Tests assignment between arrays of different sizes
- Old memory is freed, new memory allocated
- Size changes from 2 to 5 elements
- All elements copied correctly

#### 10. Test 9: Const Correctness
```cpp
const Array<int> constArray(intArray);
```
- Tests const version of `operator[]`
- Const array cannot be modified
- Demonstrates proper const-correctness implementation

#### 11. Test 10: Memory Management
```cpp
{ Array<int> tempArray(1000); }
```
- Creates large array (1000 elements) 
- Tests memory allocation for large sizes
- Automatic destruction when leaving scope
- Verifies no memory leaks occur

## Subject Main File Analysis (main_subject.cpp)

### Purpose
The subject provided this file to validate critical requirements:

### Step-by-Step Execution

#### 1. Array Creation and Mirroring
```cpp
Array<int> numbers(MAX_VAL);  // MAX_VAL = 750
int* mirror = new int[MAX_VAL];
```
- Creates Array of 750 elements
- Creates standard C++ array for comparison
- Both filled with same random values

#### 2. Copy Testing Scope
```cpp
{
    Array<int> tmp = numbers;
    Array<int> test(tmp);
}
```
- Tests copy constructor and assignment in isolated scope
- Objects destroyed when leaving scope
- Verifies original array remains unaffected

#### 3. Data Integrity Verification
```cpp
for (int i = 0; i < MAX_VAL; i++) {
    if (mirror[i] != numbers[i]) { ... }
}
```
- Compares Array with standard array
- Ensures copying didn't corrupt data
- Critical for verifying deep copy correctness

#### 4. Negative Index Testing
```cpp
numbers[-2] = 0;
```
- Tests bounds checking for negative indices
- Should throw `OutOfBoundsException`
- Validates `operator[]` properly handles `int` parameter

#### 5. Upper Bound Testing
```cpp
numbers[MAX_VAL] = 0;  // Index 750 in array of size 750
```
- Tests upper boundary (index equals size)
- Should throw exception (valid indices: 0 to 749)
- Verifies proper bounds calculation

#### 6. Memory Cleanup
```cpp
delete [] mirror;
```
- Manual cleanup of standard array
- Array class cleanup is automatic via destructor

## Key Implementation Details

### Memory Management
- Uses `new T[n]` for allocation (as required)
- RAII principle: constructor allocates, destructor deallocates
- Deep copying ensures memory safety

### Exception Handling
- Custom `OutOfBoundsException` inherits from `std::exception`
- Bounds checking: `index < 0 || index >= _size`
- Both const and non-const operators throw exceptions

### Template Design
- Header-only implementation (templates must be in headers)
- Works with any type T that has default constructor and copy assignment
- Type safety enforced at compile time

## Compilation and Execution

```bash
make          # Compiles with main.cpp
./array       # Runs comprehensive tests

# To test with subject main:
# Change SRCS in Makefile to include main_subject.cpp instead of main.cpp
make re
./array       # Runs subject validation tests
```

The comprehensive test output will show each test phase with results, demonstrating that the Array template correctly implements all required functionality with proper memory management and exception handling.
```
