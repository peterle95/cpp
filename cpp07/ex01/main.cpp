#include <iostream>
#include <string>
#include "iter.hpp"

template<typename T>
void increment(T& value) {
    ++value;
}

template<typename T>
void print(const T& value) {
    std::cout << value << " ";
}

void printString(const std::string& str) {
    std::cout << "\"" << str << "\" ";
}

void addExclamation(std::string& str) {
    str += "!";
}

void doubleValue(int& value) {
    value *= 2;
}

int main() {    
    std::cout << "\n\033[91mTest 1:\033[0m Integer array - printing" << std::endl;
    
    int numbers[] = {1, 2, 3, 4, 5};
    
    std::size_t numbersSize = sizeof(numbers) / sizeof(numbers[0]);
    
    std::cout << "Original array: ";
    ::iter(numbers, numbersSize, print<int>);
    std::cout << std::endl;
    
    std::cout << "\n\033[91mTest 2:\033[0mInteger array - incrementing" << std::endl;
    
    ::iter(numbers, numbersSize, increment<int>);
    
    std::cout << "After increment: ";
    ::iter(numbers, numbersSize, print<int>);
    std::cout << std::endl;
    
    std::cout << "\n\033[91mTest 3:\033[0m Integer array - doubling" << std::endl;
    
    ::iter(numbers, numbersSize, doubleValue);
    
    std::cout << "After doubling: ";
    ::iter(numbers, numbersSize, print<int>);
    std::cout << std::endl;
    
    std::cout << "\n\033[91mTest 4:\033[0m String array - printing" << std::endl;
    
    std::string words[] = {"hello", "world", "template", "functions"};
    
    std::size_t wordsSize = sizeof(words) / sizeof(words[0]);
    
    std::cout << "Original strings: ";
    ::iter(words, wordsSize, printString);
    std::cout << std::endl;
    
    std::cout << "\n\033[91mTest 5:\033[0m String array - modifying" << std::endl;
    
    ::iter(words, wordsSize, addExclamation);
    
    std::cout << "After adding exclamation: ";
    ::iter(words, wordsSize, printString);
    std::cout << std::endl;
    
    std::cout << "\n\033[91mTest 6:\033[0m Float array" << std::endl;
    
    float floats[] = {1.1f, 2.2f, 3.3f, 4.4f};
    
    std::size_t floatsSize = sizeof(floats) / sizeof(floats[0]);
    
    std::cout << "Original floats: ";
    ::iter(floats, floatsSize, print<float>);
    std::cout << std::endl;
    
    std::cout << "After increment: ";
    ::iter(floats, floatsSize, increment<float>);
    ::iter(floats, floatsSize, print<float>);
    std::cout << std::endl;
    
    std::cout << "\n\033[91mTest 7:\033[0m Const array" << std::endl;
    
    const int constNumbers[] = {10, 20, 30, 40, 50};
    
    std::size_t constNumbersSize = sizeof(constNumbers) / sizeof(constNumbers[0]);
    
    std::cout << "Const array: ";
    ::iter(constNumbers, constNumbersSize, print<int>);
    std::cout << std::endl;
    
    std::cout << "\n\033[91mTest 8:\033[0m Empty array (length 0)" << std::endl;
    
    int* emptyArray = NULL;
    
    
    ::iter(emptyArray, 0, print<int>); 
    
    std::cout << "Empty array test completed (no output expected)" << std::endl;
    
    return 0;
}