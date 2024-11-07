# C++ Concepts Manual: Zombie Program

## 1. Classes and Objects

### What is a Class?
A class is a blueprint for creating objects. In this program, we have a `Zombie` class that defines what a zombie is and what it can do. Classes typically have:
- Private attributes (data members): These are variables that hold the state or properties of an object and cannot be accessed directly from outside the class. They ensure encapsulation and protect the integrity of the object's data.
- Public methods (member functions): These are functions that define the behavior of the class and can be called from outside the class. They provide an interface for interacting with the object's data and functionality.
- Constructors and destructors: Constructors are special member functions that are called when an object is created, allowing for initialization of the object's attributes. Destructors are called when an object is destroyed, allowing for cleanup of resources and memory management.

Example from our Zombie class:
```cpp
class Zombie {
private:
    std::string name;  // Private attribute
public:
    Zombie(std::string name);  // Constructor
    ~Zombie();  // Destructor
    void announce(void);  // Public method
};


## 2. Memory Management

### Stack vs Heap Memory
This program demonstrates two ways to create objects:

1. **Stack Memory**:
   - Automatically managed memory
   - Memory is freed when object goes out of scope
   - Used in `randomChump` function
   - Faster allocation/deallocation
   - Limited by stack size

2. **Heap Memory**:
   - Manually managed using `new` and `delete`
   - Memory persists until explicitly freed
   - Used in `newZombie` function
   - More flexible but requires careful management
   - Larger memory limit

### When to Use Each:
- Use **Stack** when:
  - Object lifetime is limited to current scope
  - Object size is small
  - Performance is critical
  
- Use **Heap** when:
  - Object needs to outlive current scope
  - Object size is large
  - Dynamic allocation is needed

## 3. Important C++ Syntax

### Header Files
- Use header guards (`#ifndef`, `#define`, `#endif`)
- Declare class definitions and function prototypes
- Include necessary libraries

### Memory Management Operators
- `new`: Allocates memory on heap
- `delete`: Frees heap memory
- `->`: Arrow operator for accessing members through pointers
- `.`: Dot operator for accessing members directly

### Constructors and Destructors
- Constructors initialize objects
- Destructors clean up resources
- Both are special member functions
- Destructors are called automatically when object is destroyed

## 4. Best Practices

### Resource Management
- Always match `new` with `delete`
- Use stack allocation when possible
- Be aware of scope and object lifetime
- Implement proper destructors for cleanup

### Code Organization
- Separate declaration (headers) from implementation
- Use meaningful names
- Follow consistent coding style
- Comment complex logic

## 5. Common Pitfalls to Avoid

- Memory leaks (forgetting to delete heap objects)
- Dangling pointers (using deleted objects)
- Stack overflow (too many stack allocations)
- Not initializing members in constructors
- Forgetting to implement destructors when needed

## 6. Compilation and Building

The program uses a Makefile for compilation with:
- Compiler flags for warnings and errors
- C++98 standard compliance
- Separate compilation of source files
- Clean build management

## 7. Example Usage

```cpp
// Stack allocation (automatic cleanup)
void someFunction() {
Zombie stackZombie("Stack"); // Created on stack
stackZombie.announce();
} // Automatically destroyed here
// Heap allocation (manual cleanup)
void anotherFunction() {
Zombie heapZombie = new Zombie("Heap"); // Created on heap
heapZombie->announce();
delete heapZombie; // Manual cleanup required
}
```
