#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>

RPN::RPN() {}

RPN::~RPN() {}

void RPN::execute(const std::string& expression) {
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (token.length() == 1 && std::isdigit(token[0])) {
            _stack.push(std::atoi(token.c_str()));
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (_stack.size() < 2) {
                std::cerr << "Error" << std::endl;
                return;
            }
            int val2 = _stack.top();
            _stack.pop();
            int val1 = _stack.top();
            _stack.pop();

            if (token == "+") _stack.push(val1 + val2);
            else if (token == "-") _stack.push(val1 - val2);
            else if (token == "*") _stack.push(val1 * val2);
            else if (token == "/") {
                if (val2 == 0) {
                    std::cerr << "Error: Division by zero." << std::endl;
                    return;
                }
                _stack.push(val1 / val2);
            }
        } else {
            std::cerr << "Error" << std::endl;
            return;
        }
    }

    if (_stack.size() == 1) {
        std::cout << _stack.top() << std::endl;
    } else {
        std::cerr << "Error" << std::endl;
    }
}