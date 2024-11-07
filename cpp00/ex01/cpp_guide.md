1. Classes and Object-Oriented Programming
**What are Classes?**  
Classes are user-defined data types that encapsulate data and functions that operate on that data. They're the foundation of object-oriented programming (OOP).

**Looking at your PhoneBook class (reference PhoneBook.hpp, lines 11-30), we can see the basic structure:**

```cpp
class PhoneBook {
private:
    // Data members (attributes)
    Contact contacts[8];
    int count;

public:
    // Member functions (methods)
    PhoneBook();
    void addContact();
    void searchContact();
};
```

**Key OOP Concepts:**

**Encapsulation**  
Bundling data and methods that operate on that data within a single unit (class)
Hiding internal details using access specifiers (private, public, protected)
Access Specifiers
private: Only accessible within the class
public: Accessible from anywhere
protected: Accessible in the class and its derived classes
Constructors
Example from your code (PhoneBook.cpp, line 31):

```cpp
PhoneBook::PhoneBook() : count(0), oldest(0) {}
```

**String Handling**  
C++ has a string class instead of char arrays
Example from your code (Contact.hpp, lines 12-16):

```cpp
std::string firstName;
std::string lastName;
```

**References**  
C++ introduces references as an alternative to pointers:

void function(int& x)  // Reference parameter
void function(int* x)  // Pointer parameter (C-style)

**Function Overloading**  
C++ allows multiple functions with the same name but different parameters:

```cpp
void print(int x);
void print(std::string x);
void print(double x);
```

3. Memory Management
**New vs Malloc**  
C:

```c
int* ptr = (int*)malloc(sizeof(int));
free(ptr);
```

C++:

```cpp
int* ptr = new int;
delete ptr;
```

**4. Header Files**  
Header Guards
Your code demonstrates proper use of header guards (Contact.hpp, lines 1-3):

```cpp
#ifndef CONTACT_HPP
#define CONTACT_HPP
// ... code ...
#endif
```

**Namespaces**  
C++ introduces namespaces to avoid naming conflicts:

```cpp
std::cout   // 'cout' in the 'std' namespace
std::string // 'string' in the 'std' namespace
```

**Best Practices**  
**Resource Management**  
Use constructors for initialization
Use destructors for cleanup
Consider RAII (Resource Acquisition Is Initialization)
Const Correctness
Mark methods that don't modify object state as const
Use const references for parameters when possible
Member Initialization
Use initialization lists in constructors
Initialize members in the order they're declared
Your phonebook project is a good example of these concepts in action, showing:
Class organization (PhoneBook and Contact classes)
Encapsulation (private data members, public interface)
Standard library usage (std::string, std::cout)
Header organization
Basic OOP principles