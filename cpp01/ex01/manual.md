# C++ Programming Manual

## Introduction to C++

C++ is a powerful, high-level programming language that is widely used for system/software development, game development, and performance-critical applications. It is an extension of the C programming language and includes object-oriented features.

## Basic Concepts

### 1. Syntax

C++ syntax is the set of rules that defines the combinations of symbols that are considered to be correctly structured programs. Here are some basic elements:

- **Comments**: Use `//` for single-line comments and `/* ... */` for multi-line comments.
- **Variables**: Used to store data. You must declare a variable before using it.
  
  ```cpp
  int age = 25;
  ```

### 2. Data Types

C++ supports several built-in data types:

- **int**: Integer type.
- **float**: Floating-point type.
- **double**: Double-precision floating-point type.
- **char**: Character type.
- **std::string**: String type (from the C++ Standard Library).

### 3. Control Structures

Control structures allow you to dictate the flow of your program:

- **If Statements**: Used for conditional execution.

  ```cpp
  if (age > 18) {
      std::cout << "Adult";
  }
  ```

- **Loops**: Used for repeated execution.

  ```cpp
  for (int i = 0; i < 5; ++i) {
      std::cout << i;
  }
  ```

### 4. Functions

Functions are blocks of code that perform a specific task. They can take parameters and return values.

```cpp
int add(int a, int b) {
    return a + b;
}
```

### 5. Object-Oriented Programming (OOP)

C++ supports OOP, which allows you to create classes and objects.

- **Class**: A blueprint for creating objects.

  ```cpp
  class Dog {
  public:
      void bark() {
          std::cout << "Woof!";
      }
  };
  ```

- **Object**: An instance of a class.

  ```cpp
  Dog myDog;
  myDog.bark();
  ```

### 6. Memory Management

C++ allows manual memory management using `new` and `delete`.

```cpp
int* ptr = new int; // Allocate memory
delete ptr; // Free memory
```

### 7. Standard Library

C++ has a rich standard library that provides many useful functions and classes, such as:

- **Input/Output**: `iostream` for console input and output.
- **Strings**: `string` for string manipulation.
- **Containers**: `vector`, `map`, etc., for data storage.

### 8. Error Handling

C++ uses exceptions for error handling. You can throw and catch exceptions to manage errors gracefully.

```cpp
try {
    throw std::runtime_error("An error occurred");
} catch (const std::runtime_error& e) {
    std::cout << e.what();
}
```

## Conclusion

C++ is a versatile language that combines the efficiency of low-level programming with the features of high-level languages. Understanding the basic concepts outlined in this manual will provide a solid foundation for further learning and development in C++.