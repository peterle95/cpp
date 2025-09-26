#include "MutantStack.hpp"
#include <iostream>

/*Now, it’s time to move on to more serious things. Let’s develop something weird.
The std::stack container is very nice. Unfortunately, it is one of the 
only STL Con￾tainers that is NOT iterable. That’s too bad.
But why would we accept this? Especially if we can take the liberty 
of butchering the
original stack to create missing features.
To repair this injustice, you have to make the std::stack container iterable.
Write a MutantStack class. It will be implemented in terms of a std::stack.
It will offer all its member functions, plus an additional feature: iterators.
Of course, you will write and turn in your own tests to ensure everything works as
expected.
C++ - Module 08 Templated containers, iterators, algorithms
If you run it a first time with your MutantStack, and a second time replacing the
MutantStack with, for example, a std::list, the two outputs should be the same. Of
course, when testing another container, update the code below with the 
corresponding
member functions (push() can become push_back()).*/

int main() {
    std::cout << "\033[91mBasic Test with int:\033[0m" << std::endl;

    MutantStack<int> mstack;

    // Normal stack operations, included in std::stack
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl;  // should be 17

    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;  // should be 1

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "\nForward iteration:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Reverse iteration:" << std::endl;
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // Test const iterator
    const MutantStack<int> constStack = mstack;
    std::cout << "Const iteration:" << std::endl;
    for (MutantStack<int>::const_iterator cit = constStack.begin(); cit != constStack.end(); ++cit) {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;

    // Test copy into std::stack
    std::stack<int> s(mstack);
    std::cout << "Copied into std::stack, top element: " << s.top() << std::endl;

    std::cout << "\n\033[91mBasic Test with strings:\033[0m" << std::endl;

    MutantStack<std::string> sstack;
    sstack.push("Hello");
    sstack.push("World");
    sstack.push("MutantStack");

    for (MutantStack<std::string>::iterator it = sstack.begin(); it != sstack.end(); ++it) {
        std::cout << *it << std::endl;
    }

    std::cout << "\n\033[91mBasic Test with doubles:\033[0m" << std::endl;

    MutantStack<double> dstack;
    dstack.push(3.14);
    dstack.push(2.718);
    dstack.push(1.618);

    for (MutantStack<double>::iterator it = dstack.begin(); it != dstack.end(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}
