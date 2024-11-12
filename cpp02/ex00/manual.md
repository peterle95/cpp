# Important Concepts

- **Constructors and Destructors**: Special member functions that manage the lifecycle of objects.
- **Copy Constructor**: Used to create a new object as a copy of an existing object.
- **Copy Assignment Operator**: Used to assign the values from one object to another.
- **Static Members**: Shared among all instances of a class, useful for constants.
- **Encapsulation**: The class encapsulates data and provides public methods to interact with it.

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