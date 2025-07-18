#ifndef WHATEVER_HPP
#define WHATEVER_HPP

// FUNCTION TEMPLATE #1: swap
// This is a function template declaration - it's a blueprint for creating functions
// "template" keyword declares this as a template
// "typename T" means T is a placeholder for any type
// T could be int, string, double, or any custom type
template<typename T>
void swap(T& a, T& b) {  // Takes two references to objects of type T
                         // & means reference - we modify the original variables
                         // not copies of them (essential for swapping!)
    // Create a temporary variable of type T
    // Copy the value of 'a' into temp
    // When called from main with ints: int temp = a;
    // When called with strings: std::string temp = a;
    T temp = a;  
    // Assign the value of 'b' to 'a'
    // This overwrites 'a' with 'b's value
    a = b;
    // Assign the saved value (originally from 'a') to 'b'
    // Now the swap is complete!
    b = temp;
}

// FUNCTION TEMPLATE #2: min
template<typename T>            // Again, T is a type placeholder
const T& min(const T& a, const T& b) {  // Returns a const reference to type T
                                         // const T& = "constant reference"
                                         // We return a reference to avoid copying
                                         // const prevents modification of return value
                                         // Parameters are const references too -
                                         // we don't modify them, just compare
    
    return (a < b) ? a : b;  
    // Ternary operator: condition ? value_if_true : value_if_false
    // If a < b is true, return reference to a
    // If a < b is false, return reference to b
    // This requires type T to have operator< defined
    // Works with int, string, double, etc.
    // From main: when a=3, b=2 after swap, returns b (2)
}

// FUNCTION TEMPLATE #3: max
template<typename T>            // Same template syntax as above
const T& max(const T& a, const T& b) {  // Same return type and parameters as min
    
    return (a > b) ? a : b;  
    // Opposite logic from min
    // If a > b is true, return reference to a
    // If a > b is false, return reference to b
    // This requires type T to have operator> defined
    // From main: when a=3, b=2 after swap, returns a (3)
}

#endif

/*
HOW THIS CONNECTS TO MAIN.CPP:

1. When main.cpp calls ::swap(a, b) with integers:
   - Compiler sees two int arguments
   - Creates swap<int> function where T = int
   - Actual function becomes: void swap(int& a, int& b)

2. When main.cpp calls ::swap(c, d) with strings:
   - Compiler sees two std::string arguments  
   - Creates swap<std::string> function where T = std::string
   - Actual function becomes: void swap(std::string& a, std::string& b)

3. Template instantiation is automatic - you don't explicitly say swap<int>
   The compiler deduces the type from the arguments you pass

4. Why const T& for min/max?
   - const: We promise not to modify the parameters
   - &: We pass by reference to avoid copying (efficient)
   - Return const T&: We return a reference to one of the original objects
     (no copying), but caller can't modify it through our return value

5. Requirements for type T:
   - Must be copyable (for temp variable in swap)
   - Must have operator< defined (for min function)
   - Must have operator> defined (for max function)
   - Must have assignment operator= (for swap)
*/