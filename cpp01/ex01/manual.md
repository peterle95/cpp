# C++ Programming Manual

## Basic Concepts

### 1. Syntax

C++ syntax is the set of rules that defines the combinations of symbols that are considered to be correctly structured programs. Here are some basic elements:

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

### 8. Zombie Horde Exercise

This exercise demonstrates how to create a horde of Zombie objects in C++. Below is a step-by-step explanation of how the program works:

1. **User Input**: The program starts by prompting the user to enter the number of zombies they want in the horde. This is done using `std::cin`.

2. **Zombie Horde Creation**: The `zombieHorde` function is called with the user-defined number of zombies and a name (in this case, "ZombieClone"). This function is responsible for allocating memory for the zombies.

   ```cpp
   Zombie* horde = zombieHorde(hordeSize, "ZombieClone");
   ```

3. **Memory Allocation**: Inside the `zombieHorde` function, an array of `Zombie` objects is dynamically allocated using `new`. The size of the array is determined by the user input.

   ```cpp
   Zombie* horde = new Zombie[N];
   ```

4. **Initialization**: A loop iterates through each zombie in the allocated array, setting their name using the `setName` method.

   ```cpp
   for (int i = 0; i < N; ++i) {
       horde[i].setName(name);
   }
   ```

5. **Announcing Zombies**: Back in the `main` function, another loop goes through each zombie in the horde and calls the `announce` method, which outputs the zombie's name and its characteristic sound.

   ```cpp
   for (int i = 0; i < hordeSize; ++i) {
       horde[i].announce();
   }
   ```

6. **Memory Cleanup**: After all zombies have announced themselves, the allocated memory for the horde is deallocated using `delete[]` to prevent memory leaks.

   ```cpp
   delete[] horde;
   ```

7. **Program Completion**: The program returns 0, indicating successful execution.

This exercise illustrates key concepts in C++ such as dynamic memory management, object-oriented programming, and user interaction.

