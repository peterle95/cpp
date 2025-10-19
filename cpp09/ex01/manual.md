How to Compile and Run

Save the files with their respective names (Makefile, RPN.hpp, RPN.cpp, main.cpp).
Open your terminal in the directory where you saved the files.
Run the make command to compile the project.
Execute the program with an RPN expression as an argument, for example:

```
Sh
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
```

Core Concepts of the Solution
To solve this, we'll use the Standard Template Library (STL) as required. The most suitable container for evaluating a Reverse Polish Notation (RPN) expression is a std::stack.[1][2] RPN, also known as postfix notation, is evaluated by processing the expression's components from left to right.[3][4]
The logic is as follows:
If the component is a number, it is pushed onto a stack.
If the component is an operator, the top two numbers are popped from the stack, the operation is performed, and the result is pushed back onto the stack.
To parse the input string into numbers and operators, std::stringstream is an effective tool, allowing a string to be treated like an input stream.