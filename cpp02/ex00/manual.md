# Important Concepts


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

### 5. Compilation and Execution

The `Makefile` is used to compile the program:

```makefile
NAME = fixed

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Fixed.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
```

- **Targets**:
  - `all`: Compiles the program.
  - `clean`: Removes object files.
  - `fclean`: Removes the executable.
  - `re`: Rebuilds the program.

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
