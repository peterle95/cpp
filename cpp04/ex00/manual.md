Here's the key breakdown of virtual requirements in polymorphism:

1. Methods:
```cpp
// BASE CLASS MUST HAVE virtual
class Base {
public:
    virtual void method();  // Required for polymorphism
};

// DERIVED CLASSES DON'T NEED virtual (but should use override in C++11+)
class Derived : public Base {
public:
    void method() override;  // Automatically virtual through inheritance
};
```

2. Destructors:
```cpp
// BASE CLASS MUST HAVE virtual destructor
class Base {
public:
    virtual ~Base();  // Required for proper destruction
};

// DERIVED CLASSES DON'T NEED virtual
class Derived : public Base {
public:
    ~Derived();  // Automatically virtual through inheritance
};
  ```

Key Rules:
1. Virtual declaration is only required in the base class
2. Derived classes inherit the "virtualness" automatically
3. Best practice: Use override keyword in C++11+ for clarity

```cpp
   void method() override;  // Explicitly shows overriding
```

Why This Works:
Virtual mechanism is inherited through the hierarchy
Once virtual in base, remains virtual in all derived classes
Destructor virtuality ensures proper cleanup order:

```cpp
  Base* obj = new Derived();
  delete obj;  // Calls ~Derived() then ~Base() ✅
```

Exception: When using the override specifier (C++11+), you don't need virtual in derived classes but must maintain the same signature.


