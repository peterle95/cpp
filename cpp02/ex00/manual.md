# Orthodox Canonical Form

The orthodox canonical form refers to a specific structure that classes in C++ should follow to ensure proper management of resources and object lifecycles. This form typically includes:

1. A default constructor.
2. A copy constructor.
3. A copy assignment operator.
4. A destructor.

This structure is relevant to this project because the `Fixed` class manages a resource (the fixed-point value) and needs to ensure that objects are correctly initialized, copied, and destroyed to prevent resource leaks and undefined behavior.

### Examples from the Project

- **Default Constructor**: The `Fixed` class has a default constructor that initializes `_fixedPointValue` to `0`, ensuring a known state for each instance.
  
  ```cpp
  Fixed::Fixed() : _fixedPointValue(0) 
  {
      std::cout << "Default constructor called" << std::endl;
  }
  ```

- **Copy Constructor**: The copy constructor creates a new `Fixed` object as a copy of an existing one, ensuring that the `_fixedPointValue` is copied correctly.

  ```cpp
  Fixed::Fixed(const Fixed &src) 
  {
      std::cout << "Copy constructor called" << std::endl;
      *this = src; // Calls the copy assignment operator
  }
  ```

- **Copy Assignment Operator**: This operator checks for self-assignment and copies the `_fixedPointValue` from one object to another.

  ```cpp
  Fixed &Fixed::operator=(const Fixed &rhs) 
  {
      std::cout << "Copy assignment operator called" << std::endl;
      if (this != &rhs) // Prevent self-assignment
          this->_fixedPointValue = rhs.getRawBits();
      return *this;
  }
  ```

- **Destructor**: The destructor prints a message when an object is destroyed, helping to track the lifecycle of `Fixed` objects.

  ```cpp
  Fixed::~Fixed() 
  {
      std::cout << "Destructor called" << std::endl;
  }
  ```

By adhering to the orthodox canonical form, the `Fixed` class ensures that it manages its resources correctly and behaves predictably when objects are copied or assigned.


- **Constructors and Destructors**: 
  - **General Use**: Constructors are special member functions that are automatically called when an object of a class is created. They are primarily used to initialize the object's attributes and allocate resources if necessary. Destructors, on the other hand, are called when an object goes out of scope or is explicitly deleted, and they are used to free resources that the object may have acquired during its lifetime.
  - **Specific to This Project**: In the `Fixed` class, the default constructor initializes the `_fixedPointValue` to `0`, ensuring that every instance starts with a known state. The destructor prints a message when an object is destroyed, which helps in tracking the lifecycle of `Fixed` objects during execution.

- **Copy Constructor**: 
  - **General Use**: A copy constructor is a special constructor that creates a new object as a copy of an existing object. For example, if you have a class `Point` that represents a point in 2D space, the copy constructor allows you to create a new `Point` object from an existing one, like this:
  
    ```cpp
    Point p1(3, 4); // Create a Point object p1
    Point p2 = p1;  // Use the copy constructor to create p2 as a copy of p1
    ```
  
  This is essential for managing resources correctly, especially when objects are passed by value or returned from functions.
  - **Specific to This Project**: The copy constructor in the `Fixed` class ensures that when a new `Fixed` object is created from an existing one, the `_fixedPointValue` is copied correctly. This prevents issues that could arise from shallow copies, particularly if the class were to manage dynamic resources in the future.

- **Copy Assignment Operator**: 
  - **General Use**: The copy assignment operator allows one object to be assigned the value of another after both objects have been created. It is crucial for ensuring that the assignment operation behaves correctly, especially in the presence of self-assignment.
  - **Specific to This Project**: In the `Fixed` class, the copy assignment operator checks for self-assignment and copies the `_fixedPointValue` from one object to another. This operator is vital for maintaining the integrity of the data when objects are assigned to each other.

- **Static Members**: 
  - **General Use**: Static members are shared among all instances of a class. They are useful for constants or data that should be common to all objects of the class, rather than unique to each instance.
  - **Specific to This Project**: The `Fixed` class uses a static constant integer `_fractionalBits` to define the number of fractional bits for fixed-point representation. This value is shared across all instances of `Fixed`, ensuring consistency and reducing memory usage.

- **Encapsulation**: 
  - **General Use**: Encapsulation is a fundamental principle of object-oriented programming that restricts direct access to some of an object's components. It helps in bundling the data (attributes) and methods (functions) that operate on the data into a single unit or class, and it protects the integrity of the data by exposing only necessary parts through public methods.
  - **Specific to This Project**: The `Fixed` class encapsulates the `_fixedPointValue` and provides public methods like `getRawBits()` and `setRawBits(int const raw)` to interact with this private data. This design ensures that the internal representation of the fixed-point number is hidden from the user, allowing for controlled access and modification, which is crucial for maintaining the integrity of the data throughout the program.

---

## Overview of the Program

This C++ program implements a class called `Fixed` that represents fixed-point numbers. The program demonstrates the use of constructors, destructors, and operator overloading, which are key concepts in C++.

---

## Step-by-Step Breakdown

### 1. File Structure

The program consists of several files:

- **main.cpp**: Contains the main function and demonstrates the usage of the `Fixed` class.
- **Fixed.cpp**: Implements the methods of the `Fixed` class.
- **Fixed.hpp**: Contains the declaration of the `Fixed` class.
- **Makefile**: Used to compile the program.

### 2. Class Declaration (Fixed.hpp)

The `Fixed` class is declared in `Fixed.hpp`:

```cpp
class Fixed
{
private:
int fixedPointValue; // Stores the fixed-point number value
static const int fractionalBits = 8; // Number of fractional bits
public:
Fixed(); // Default constructor
Fixed(const Fixed &src); // Copy constructor
Fixed &operator=(const Fixed &rhs); // Copy assignment operator
~Fixed(); // Destructor
int getRawBits(void) const; // Returns the raw value
void setRawBits(int const raw); // Sets the raw value
};
```

### Explanation of Constructors and Copy Constructors

#### Why Do We Need a Constructor?

A constructor is a special member function that is automatically called when an object of a class is created. The primary purpose of a constructor is to initialize the object's attributes and allocate resources if necessary. In the context of the `Fixed` class, the constructor serves the following purposes:

1. **Initialization**: The constructor initializes the `_fixedPointValue` to a default value (in this case, `0`). This ensures that every instance of the `Fixed` class starts with a known state, preventing potential errors that could arise from using uninitialized variables.

2. **Resource Management**: If the class were to manage resources (like dynamic memory, file handles, etc.), the constructor would be responsible for allocating those resources. Although the current implementation does not require resource management, having a constructor prepares the class for future enhancements.

3. **Encapsulation**: By using a constructor, we encapsulate the initialization logic within the class, making it easier to manage and modify in one place.

#### Why Do We Need a Copy Constructor?

A copy constructor is a special constructor that creates a new object as a copy of an existing object. The need for a copy constructor arises from the following reasons:

1. **Object Copying**: When you want to create a new instance of a class that is a copy of an existing instance, the copy constructor is called. This is particularly important when passing objects by value to functions or returning objects from functions. Without a copy constructor, the default behavior would be to perform a shallow copy, which may lead to issues if the class manages resources.

2. **Preventing Shallow Copies**: In the `Fixed` class, the copy constructor ensures that the `_fixedPointValue` of the new object is set to the value of the existing object. This is crucial for maintaining the integrity of the data. If the class were to manage dynamic memory or other resources, a shallow copy could lead to multiple objects pointing to the same resource, resulting in undefined behavior when one object is modified or destroyed.

3. **Consistency**: The copy constructor allows for consistent behavior when copying objects. It ensures that the new object is a true copy of the original, preserving the state and behavior of the original object.

In summary, constructors and copy constructors are fundamental to object-oriented programming in C++. They ensure that objects are properly initialized and managed, allowing for safe and predictable behavior when working with instances of a class.

### 3. Class Implementation (Fixed.cpp)

The methods of the `Fixed` class are defined in `Fixed.cpp`:

- **Default Constructor**:
  Initializes `_fixedPointValue` to 0 and prints a message.

```cpp
Fixed::Fixed() : _fixedPointValue(0) 
{
    std::cout << "Default constructor called" << std::endl;
}
```

- **Copy Constructor**:
  Initializes a new object as a copy of an existing object and prints a message.

```cpp
Fixed::Fixed(const Fixed &src) 
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src; // Calls the copy assignment operator
}
```

- **Copy Assignment Operator**:
  Assigns the value of one object to another and prints a message.

```cpp
Fixed &Fixed::operator=(const Fixed &rhs) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs) // Prevent self-assignment
        this->_fixedPointValue = rhs.getRawBits();
    return *this;
}
```

- **Destructor**:
  Prints a message when an object is destroyed.

```cpp
Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}
```

- **getRawBits Method**:
  Returns the raw value of `_fixedPointValue` and prints a message.

```cpp
int Fixed::getRawBits(void) const 
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}
```

- **setRawBits Method**:
  Sets the value of `_fixedPointValue`.

```cpp
void Fixed::setRawBits(int const raw) 
{
    this->_fixedPointValue = raw;
}
```

### 4. Main Function (main.cpp)

The `main` function demonstrates the usage of the `Fixed` class:

```cpp
int main(void) 
{
    Fixed a; // Calls the default constructor
    Fixed b(a); // Calls the copy constructor
    Fixed c; // Calls the default constructor

    c = b; // Calls the copy assignment operator

    std::cout << a.getRawBits() << std::endl; // Outputs the raw value of a
    std::cout << b.getRawBits() << std::endl; // Outputs the raw value of b
    std::cout << c.getRawBits() << std::endl; // Outputs the raw value of c

    return 0;
}
```

### Explanation of Constructors and Copy Constructors

#### Why Do We Need a Constructor?

A constructor is a special member function that is automatically called when an object of a class is created. The primary purpose of a constructor is to initialize the object's attributes and allocate resources if necessary. In the context of the `Fixed` class, the constructor serves the following purposes:

1. **Initialization**: The constructor initializes the `_fixedPointValue` to a default value (in this case, `0`). This ensures that every instance of the `Fixed` class starts with a known state, preventing potential errors that could arise from using uninitialized variables.

2. **Resource Management**: If the class were to manage resources (like dynamic memory, file handles, etc.), the constructor would be responsible for allocating those resources. Although the current implementation does not require resource management, having a constructor prepares the class for future enhancements.

3. **Encapsulation**: By using a constructor, we encapsulate the initialization logic within the class, making it easier to manage and modify in one place.

#### Why Do We Need a Copy Constructor?

A copy constructor is a special constructor that creates a new object as a copy of an existing object. The need for a copy constructor arises from the following reasons:

1. **Object Copying**: When you want to create a new instance of a class that is a copy of an existing instance, the copy constructor is called. This is particularly important when passing objects by value to functions or returning objects from functions. Without a copy constructor, the default behavior would be to perform a shallow copy, which may lead to issues if the class manages resources.

2. **Preventing Shallow Copies**: In the `Fixed` class, the copy constructor ensures that the `_fixedPointValue` of the new object is set to the value of the existing object. This is crucial for maintaining the integrity of the data. If the class were to manage dynamic memory or other resources, a shallow copy could lead to multiple objects pointing to the same resource, resulting in undefined behavior when one object is modified or destroyed.

3. **Consistency**: The copy constructor allows for consistent behavior when copying objects. It ensures that the new object is a true copy of the original, preserving the state and behavior of the original object.

In summary, constructors and copy constructors are fundamental to object-oriented programming in C++. They ensure that objects are properly initialized and managed, allowing for safe and predictable behavior when working with instances of a class.


## Project Analysis

### 1. File Purpose and Functionality
This project implements a class named `Fixed` that represents a fixed-point number. The main purpose of the project is to demonstrate the use of constructors, destructors, and operator overloading in C++. The `Fixed` class encapsulates the behavior of fixed-point arithmetic, allowing for the creation, copying, and assignment of fixed-point number objects.

### 2. Technical Implementation Details
The project consists of three main files:
- **`main.cpp`**: The entry point of the program that demonstrates the functionality of the `Fixed` class.
- **`Fixed.hpp`**: The header file that declares the `Fixed` class and its member functions.
- **`Fixed.cpp`**: The implementation file that defines the member functions of the `Fixed` class.

#### Key Functions:
- **Constructors**:
  - Default constructor initializes the fixed-point value to 0.
  - Copy constructor creates a new object as a copy of an existing one.
- **Destructor**: Cleans up when a `Fixed` object goes out of scope.
- **Member Functions**:
  - `getRawBits()`: Returns the raw fixed-point value.
  - `setRawBits(int const raw)`: Sets the raw fixed-point value.

### 3. Problems Encountered and Solutions
- **Self-Assignment in Copy Assignment Operator**: The implementation checks for self-assignment to prevent issues when an object is assigned to itself. This is done using the condition `if (this != &rhs)`.
- **Memory Management**: The project does not dynamically allocate memory, so there are no memory leaks. The destructor is implemented to ensure proper cleanup.

### 4. Memory Management Considerations
- **Allocation Points**: No dynamic memory allocation is used in this project, so there are no allocation points to manage.
- **Deallocation Strategy**: The destructor is defined but does not need to free any resources since no dynamic memory is allocated.
- **Leak Prevention**: Since there are no dynamic allocations, there are no memory leaks.
- **Valgrind Results**: Running Valgrind would show no memory leaks or errors, as the project does not use dynamic memory.

### 5. Potential Evaluation Questions

- **How does the copy constructor work, and why is it important?**
  The copy constructor creates a new instance of the `Fixed` class as a copy of an existing instance. It takes a reference to another `Fixed` object as a parameter and initializes the new object with the same value as the source object. This is important because it ensures that when an object is copied, the new object has its own separate copy of the data, preventing unintended modifications to the original object. In the `Fixed` class, the copy constructor also outputs a message indicating that it has been called, which helps in tracing object creation.

- **What happens if you do not check for self-assignment in the copy assignment operator?**
  If you do not check for self-assignment in the copy assignment operator, it can lead to issues where the object's data is modified while it is being assigned to itself. For example, if the assignment operator does not check if `this` is the same as `&rhs`, it may overwrite the object's data with its own data, potentially leading to unexpected behavior or data corruption. In the `Fixed` class, the check `if (this != &rhs)` prevents this issue by ensuring that the assignment only occurs if the two objects are different.

- **Can you explain the purpose of the `getRawBits` and `setRawBits` functions?**
  The `getRawBits` function is a member function that returns the raw fixed-point value stored in the `_fixedPointValue` member variable. It allows external code to access the internal representation of the fixed-point number without modifying it. The `setRawBits` function, on the other hand, is used to set the value of `_fixedPointValue` directly. This function allows for the modification of the fixed-point number's value, enabling flexibility in how the class is used. Together, these functions provide a way to manage the internal state of the `Fixed` class while maintaining encapsulation.

- **How does the program demonstrate the use of constructors and destructors?**
  The program demonstrates the use of constructors and destructors by creating instances of the `Fixed` class and observing the output messages that indicate when each constructor and destructor is called. When an object is created using the default constructor, a message "Default constructor called" is printed. Similarly, when an object is created using the copy constructor, the message "Copy constructor called" is displayed. Finally, when the objects go out of scope at the end of the `main` function, the destructor is called, and the message "Destructor called" is printed. This sequence of messages illustrates the lifecycle of the `Fixed` objects and shows how constructors and destructors manage resource allocation and cleanup.

### Project Related Concepts

- **Fixed-Point Arithmetic**: Fixed-point arithmetic is a method of representing real numbers that allows for a fixed number of digits after the decimal point. This is particularly useful in systems where floating-point representation may lead to precision issues or where performance is critical, such as in embedded systems or digital signal processing. The `Fixed` class in this project encapsulates the behavior of fixed-point numbers, allowing for precise arithmetic operations without the overhead of floating-point calculations.

- **Orthodox Canonical Form**: In C++, the Orthodox Canonical Form refers to a specific pattern for defining classes that manage resources. This includes defining a default constructor, a copy constructor, a copy assignment operator, and a destructor. This pattern ensures that objects are properly initialized, copied, and cleaned up, preventing resource leaks and undefined behavior. The `Fixed` class adheres to this form, ensuring that it can be safely copied and assigned.

- **Encapsulation**: Encapsulation is a fundamental principle of object-oriented programming that restricts direct access to some of an object's components and can prevent the accidental modification of data. In the `Fixed` class, the internal representation of the fixed-point value is kept private, and access to it is controlled through public member functions (`getRawBits` and `setRawBits`). This promotes data integrity and hides the implementation details from the user.

- **Operator Overloading**: Operator overloading allows developers to define custom behavior for operators (like `=`, `+`, etc.) when they are used with user-defined types. In this project, the copy assignment operator is overloaded to allow for the assignment of one `Fixed` object to another. This is crucial for ensuring that the assignment operation behaves correctly, especially in the context of resource management and self-assignment checks.


- **Const-Correctness**: Const-correctness is a practice in C++ that ensures that functions that do not modify the state of an object are marked as `const`. This allows the compiler to enforce const-correctness and helps prevent unintended modifications. In the `Fixed` class, the `getRawBits` function is marked as `const`, indicating that it does not alter the state of the object, which enhances the safety and clarity of the code.

---

## File-by-File Analysis

### 1. `Fixed.hpp`
- **Purpose**: Declares the `Fixed` class and its member functions.
- **Key Functions**:
  - Constructors and destructor.
  - `getRawBits()` and `setRawBits()`.
- **Edge Cases**: None, as it only declares functions.
- **Potential Issues**: None identified.

### 2. `Fixed.cpp`
- **Purpose**: Implements the member functions of the `Fixed` class.
- **Key Functions**:
  - Default constructor, copy constructor, copy assignment operator, and destructor.
- **Edge Cases**: Self-assignment check in the copy assignment operator.
- **Potential Issues**: None identified.

### 3. `main.cpp`
- **Purpose**: Demonstrates the functionality of the `Fixed` class.
- **Key Functions**:
  - Main function that creates instances of `Fixed` and outputs their raw values.
- **Edge Cases**: None, as it primarily tests the constructors and assignment operator.
- **Potential Issues**: None identified.

---

## Implementation Challenges
- Understanding the Orthodox Canonical Form for C++ classes, which includes defining a default constructor, copy constructor, copy assignment operator, and destructor.
- Ensuring proper function calls and outputs to demonstrate the behavior of the `Fixed` class.

---

## Memory Management
- The project does not involve dynamic memory allocation, thus simplifying memory management concerns. The destructor is present but does not perform any operations since there are no resources to free.

---
