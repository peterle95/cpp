# MutantStack Manual

## Overview

The `MutantStack` class is a custom STL container that extends the functionality of the standard `std::stack` container. While `std::stack` is not iterable, `MutantStack` adds iterator support, making it a more versatile container that can be used in algorithms requiring iteration.

## Key Features

### 1. Template Support
`MutantStack` is a template class that can work with any data type:

```cpp
MutantStack<int> intStack;
MutantStack<std::string> stringStack;
MutantStack<double> doubleStack;
```

### 2. Inheritance from std::stack
`MutantStack` inherits all functionality from `std::stack<T>`, including:
- `push()` - Add element to top
- `pop()` - Remove element from top
- `top()` - Access top element
- `size()` - Get number of elements
- `empty()` - Check if stack is empty

### 3. Orthodox Canonical Form
The class implements the four essential member functions:

#### Default Constructor
```cpp
MutantStack() : std::stack<T>() {}
```
- Creates an empty MutantStack
- Uses the default underlying container (deque)

#### Copy Constructor
```cpp
MutantStack(const MutantStack &other) : std::stack<T>(other) {}
```
- Creates a copy of another MutantStack
- Performs deep copy of all elements

#### Assignment Operator
```cpp
MutantStack &operator=(const MutantStack &other) {
    std::stack<T>::operator=(other);
    return *this;
}
```
- Assigns one MutantStack to another
- Returns reference to allow chaining

#### Destructor
```cpp
~MutantStack() {}
```
- Automatically called when object goes out of scope
- Cleans up resources

### 4. Iterator Support

#### Iterator Typedefs
The class defines four types of iterators:

```cpp
typedef typename std::stack<T>::container_type::iterator iterator;
typedef typename std::stack<T>::container_type::const_iterator const_iterator;
typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
```

#### Forward Iteration
```cpp
iterator begin() { return this->c.begin(); }
iterator end() { return this->c.end(); }
const_iterator begin() const { return this->c.begin(); }
const_iterator end() const { return this->c.end(); }
```

**Usage:**
```cpp
MutantStack<int> mstack;
mstack.push(1);
mstack.push(2);
mstack.push(3);

for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
    std::cout << *it << " ";  // Prints: 1 2 3
}
```

#### Reverse Iteration
```cpp
reverse_iterator rbegin() { return this->c.rbegin(); }
reverse_iterator rend() { return this->c.rend(); }
const_reverse_iterator rbegin() const { return this->c.rbegin(); }
const_reverse_iterator rend() const { return this->c.rend(); }
```

**Usage:**
```cpp
for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
    std::cout << *rit << " ";  // Prints: 3 2 1
}
```

#### Const Iteration
```cpp
const_iterator begin() const { return this->c.begin(); }
const_iterator end() const { return this->c.end(); }
```

**Usage:**
```cpp
const MutantStack<int> constStack = mstack;
for (MutantStack<int>::const_iterator cit = constStack.begin(); cit != constStack.end(); ++cit) {
    std::cout << *cit << " ";  // Read-only access
}
```

## Technical Implementation Details

### Iterator Typedefs Explained
The typedef declarations are crucial for providing iterator support:

```cpp
typedef typename std::stack<T>::container_type::iterator iterator;
typedef typename std::stack<T>::container_type::const_iterator const_iterator;
typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
```

- **`container_type`**: This refers to the underlying container used by `std::stack` (typically `std::deque<T>`)
- **`typename` keyword**: Required for dependent types in template metaprogramming to tell the compiler these are type names
- **Four iterator types**: Regular, const, reverse, and const reverse iterators for complete STL compatibility

### Function Overloading Strategy
The class uses function overloading to provide both mutable and const versions:

```cpp
iterator begin() { return this->c.begin(); }
const_iterator begin() const { return this->c.begin(); }
```

- **Mutable version**: Returns regular iterator, allows modification of elements
- **Const version**: Returns const iterator, provides read-only access
- **Same implementation**: Both functions do the same thing but with different return types

### Underlying Container Access Pattern
MutantStack accesses the underlying container through the protected member `c`:

```cpp
iterator begin() { return this->c.begin(); }
```

- **`this->c`**: Accesses the protected container member from the base `std::stack` class
- **Direct forwarding**: Iterator functions simply forward to the underlying container's iterator methods
- **No data copying**: Iterators reference the actual elements in the container

### Template Metaprogramming Implementation
The class uses advanced template techniques:

```cpp
template <typename T>
class MutantStack : public std::stack<T> {
```
- **Template parameter T**: Allows the stack to work with any data type
- **Public inheritance**: Inherits all `std::stack` functionality while allowing upcasting
- **Dependent type resolution**: Uses `typename` to resolve nested types from template parameters

### Const Correctness Implementation
Const correctness ensures safe access patterns:

```cpp
iterator begin() { return this->c.begin(); }
const_iterator begin() const { return this->c.begin(); }
```

## Advanced Implementation Strategies

### Inheritance Strategy
MutantStack uses public inheritance from `std::stack<T>`:

```cpp
template <typename T>
class MutantStack : public std::stack<T> {
```

**Benefits of this approach:**
- **Full API compatibility**: All `std::stack` methods available directly
- **Polymorphic behavior**: Can be used wherever `std::stack` is expected
- **Protected member access**: Can access the underlying container `c` for iterator implementation
- **No overhead**: No additional memory or performance cost compared to `std::stack`

**Design considerations:**
- **Composition vs Inheritance**: Inheritance chosen for direct API compatibility and protected member access
- **Interface segregation**: Only adds iterator functionality, doesn't change existing behavior
- **Liskov Substitution Principle**: MutantStack is a true `std::stack` with additional capabilities

### Orthodox Canonical Form Implementation

#### Constructor Strategy
```cpp
MutantStack() : std::stack<T>() {}
```

- **Member initialization**: Explicitly calls base class constructor
- **Default container**: Uses `std::deque<T>` as underlying container (standard for `std::stack`)
- **Resource efficiency**: No dynamic allocation for empty stack

#### Copy Semantics
```cpp
MutantStack(const MutantStack &other) : std::stack<T>(other) {}
MutantStack &operator=(const MutantStack &other) {
    std::stack<T>::operator=(other);
    return *this;
}
```

- **Deep copying**: Automatically handled by base class copy constructor and assignment
- **Exception safety**: Inherits exception guarantees from `std::stack`
- **Return value optimization**: Assignment operator returns reference for chaining

#### Resource Management
```cpp
~MutantStack() {}
```

- **Automatic cleanup**: Base class destructor handles container cleanup
- **RAII compliance**: Follows Resource Acquisition Is Initialization principle
- **No memory leaks**: All resources managed by base class

### Template Specialization Considerations

#### Type Requirements
The template parameter `T` must meet certain requirements:
- **Copy constructible**: Required for stack operations
- **Assignable**: Needed for copy constructor and assignment operator
- **Default constructible**: Used internally by the underlying container

#### Container Compatibility
The underlying container (typically `std::deque`) must support:
- `iterator`, `const_iterator`, `reverse_iterator`, `const_reverse_iterator` types
- `begin()` and `end()` methods for all iterator categories
- Efficient insertion/removal at both ends (for stack operations)

### Memory Layout and Performance

#### Memory Structure
```
MutantStack<int> object:
┌─────────────────────────────────────┐
│ std::stack<int> base class         │
│ ┌─────────────────────────────────┐ │
│ │ std::deque<int> container (c)   │ │
│ │ ┌─────────────────────────────┐ │ │
│ │ │ int, int, int, ...          │ │ │
│ │ └─────────────────────────────┘ │ │
│ └─────────────────────────────────┘ │
└─────────────────────────────────────┘
```

#### Performance Characteristics
- **Zero overhead**: Iterator functions are inline and add no runtime cost
- **Cache friendly**: Sequential memory layout of underlying deque
- **Exception guarantees**: Strong guarantee for all operations (inherited from STL)

### STL Algorithm Compatibility

#### Range-Based For Support
```cpp
for (auto& element : mstack) {
    std::cout << element << " ";
}
```

#### Algorithm Compatibility
```cpp
// Find element
auto it = std::find(mstack.begin(), mstack.end(), target);

// Count occurrences
int count = std::count(mstack.begin(), mstack.end(), value);

// Copy to another container
std::vector<int> vec(mstack.begin(), mstack.end());
```

**Compatibility features:**
- **Input iterator compliance**: Supports `==`, `!=`, `++`, unary `*` operations
- **Forward iterator compliance**: Supports multi-pass algorithms
- **Bidirectional support**: Reverse iterators enable backward traversal

### Basic Stack Operations
```cpp
MutantStack<int> mstack;

// Push elements
mstack.push(5);
mstack.push(17);

// Access top element
std::cout << mstack.top() << std::endl;  // Output: 17

// Remove element
mstack.pop();

// Check size
std::cout << mstack.size() << std::endl;  // Output: 1
```

### Iteration Capabilities
```cpp
// Forward iteration (bottom to top)
for (auto it = mstack.begin(); it != mstack.end(); ++it) {
    std::cout << *it << " ";
}

// Reverse iteration (top to bottom)
for (auto rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
    std::cout << *rit << " ";
}
```

### Compatibility with STL
```cpp
// Can be copied to std::stack
std::stack<int> regularStack(mstack);

// Can be used with STL algorithms
std::vector<int> vec(mstack.begin(), mstack.end());
```

## Advantages Over std::stack

1. **Iterability**: Can be used in range-based for loops and STL algorithms
2. **Reverse iteration**: Can iterate from top to bottom
3. **Const correctness**: Safe iteration over constant objects
4. **Full STL compatibility**: Inherently compatible with existing code

## Limitations

1. **Access pattern**: Still follows LIFO (Last In, First Out) principle
2. **No random access**: Cannot access elements by index
3. **Single-ended**: Can only access top element directly

## Performance Characteristics

- **Time Complexity**:
  - `push()`: O(1) amortized
  - `pop()`: O(1)
  - `top()`: O(1)
  - `begin()`/`end()`: O(1)
  - Iteration: O(n) for n elements

- **Space Complexity**: O(n) for n elements stored

This implementation provides all the functionality of `std::stack` while adding the crucial feature of iteration support, making it suitable for use in algorithms that require sequential access to elements.
