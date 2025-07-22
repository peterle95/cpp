## Project Manual: Generic Array Iterator Template

### Project Overview

This project implements a generic `iter` function template in C++ that can apply any function to each element of an array. The implementation demonstrates advanced C++ template programming, supporting both const and non-const array operations while working with any data type.

**Core Files:**
- `iter.hpp` - Header file containing the template function definition
- `main.cpp` - Test program demonstrating various use cases
- `Makefile` - Build configuration for compilation

---

## Program Execution Flow

### 1. Program Entry Point (main.cpp)

When the program starts, `main()` function executes a comprehensive test suite that demonstrates the `iter` template function with different data types and operation types.

### 2. Test Sequence Breakdown

#### Test 1: Integer Array Printing
```cpp
int numbers[] = {1, 2, 3, 4, 5};
::iter(numbers, numbersSize, print<int>);
```

**Step-by-step execution:**
1. Creates an integer array with 5 elements
2. Calculates array size using `sizeof(numbers) / sizeof(numbers[0])`
3. Calls `iter` template function with:
   - `numbers` array (automatically converts to pointer)
   - `numbersSize` (5 elements)
   - `print<int>` template function instantiated for integers
4. `iter` function iterates through each element and calls `print<int>` on each
5. Output: `1 2 3 4 5 `

#### Test 2: Integer Array Modification (Increment)
```cpp
::iter(numbers, numbersSize, increment<int>);
```

**Step-by-step execution:**
1. Uses the same `numbers` array from Test 1
2. Calls `iter` with `increment<int>` template function
3. `iter` passes each array element by reference to `increment`
4. `increment` function adds 1 to each element using `++value`
5. Array is modified in-place: `[2, 3, 4, 5, 6]`
6. Prints modified array to verify changes

#### Test 3: Integer Array Modification (Doubling)
```cpp
::iter(numbers, numbersSize, doubleValue);
```

**Step-by-step execution:**
1. Uses the modified array from Test 2: `[2, 3, 4, 5, 6]`
2. Calls `iter` with `doubleValue` non-template function
3. `doubleValue` multiplies each element by 2 using `value *= 2`
4. Array becomes: `[4, 6, 8, 10, 12]`
5. Prints final array state

#### Test 4: String Array Printing
```cpp
std::string words[] = {"hello", "world", "template", "functions"};
::iter(words, wordsSize, printString);
```

**Step-by-step execution:**
1. Creates array of `std::string` objects
2. Calls `iter` with `printString` function (non-template)
3. `printString` takes const reference, reads each string safely
4. Output: `"hello" "world" "template" "functions" `

#### Test 5: String Array Modification
```cpp
::iter(words, wordsSize, addExclamation);
```

**Step-by-step execution:**
1. Uses same string array from Test 4
2. Calls `iter` with `addExclamation` function
3. `addExclamation` takes non-const reference, appends "!" to each string
4. Array becomes: `["hello!", "world!", "template!", "functions!"]`
5. Prints modified strings to verify changes

#### Test 6: Float Array Processing
```cpp
float floats[] = {1.1f, 2.2f, 3.3f, 4.4f};
::iter(floats, floatsSize, print<float>);
::iter(floats, floatsSize, increment<float>);
```

**Step-by-step execution:**
1. Creates float array with decimal values
2. First prints original values using `print<float>`
3. Then increments each value using `increment<float>`
4. Prints incremented results to show template works with floating-point types

#### Test 7: Const Array Handling
```cpp
const int constNumbers[] = {10, 20, 30, 40, 50};
::iter(constNumbers, constNumbersSize, print<int>);
```

**Step-by-step execution:**
1. Creates `const` integer array (read-only)
2. Calls `iter` with `print<int>` function
3. `print` takes const reference parameter, compatible with const arrays
4. Demonstrates that `iter` correctly handles const/non-const compatibility
5. **Note:** Calling with `increment<int>` would cause compilation error since increment requires non-const reference

#### Test 8: Edge Case - Empty Array
```cpp
int* emptyArray = NULL;
::iter(emptyArray, 0, print<int>);
```

**Step-by-step execution:**
1. Creates null pointer simulating empty array
2. Calls `iter` with null pointer and length 0
3. `iter` function checks for null pointer and returns early
4. No segmentation fault occurs due to null pointer protection

---

## Core Template Function Analysis

### The `iter` Template Function (iter.hpp)

```cpp
template<typename T, typename F>
void iter(T* array, std::size_t length, F func) {
    if (!array) return;  // Null pointer protection
    
    for (std::size_t i = 0; i < length; ++i) {
        func(array[i]);  // Apply function to each element
    }
}
```

**Function Parameters:**
- `T* array` - Pointer to array of type T (any type)
- `std::size_t length` - Number of elements in array
- `F func` - Function/functor to apply to each element

**Template Parameters:**
- `T` - Data type of array elements (auto-deduced)
- `F` - Function type (auto-deduced from function argument)

**Key Features:**
1. **Type Safety:** Templates ensure type consistency at compile-time
2. **Flexibility:** Works with any data type and any compatible function
3. **Reference Handling:** Automatically handles const/non-const references
4. **Safety:** Null pointer check prevents segmentation faults

---

## Function Types Demonstrated

### Template Functions
- `print<T>()` - Takes const reference, reads and displays values
- `increment<T>()` - Takes non-const reference, modifies by incrementing

### Regular Functions
- `printString()` - Specific to `std::string`, displays with quotes
- `addExclamation()` - Modifies strings by appending "!"
- `doubleValue()` - Specific to integers, multiplies by 2

---

## Compilation and Execution

**Build Process:**
1. `make` command invokes C++ compiler with flags: `-Wall -Wextra -Werror -std=c++98`
2. Compiles `main.cpp` which includes `iter.hpp`
3. Creates executable named `iter`

**Runtime Process:**
1. Program executes all 8 test cases sequentially
2. Each test demonstrates different aspects of the template function
3. Output shows before/after states for modification operations
4. Program completes successfully, returning 0

This implementation showcases advanced C++ template programming, demonstrating how a single template function can work with multiple data types and function signatures while maintaining type safety and performance.