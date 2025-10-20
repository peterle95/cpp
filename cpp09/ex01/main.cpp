#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: Please provide an RPN expression as a single argument." << std::endl;
        return 1;
    }

    RPN rpn;
    rpn.execute(argv[1]);

    return 0;
}