#include "Harl.hpp"
#include <iostream>

int main() {
    Harl harl;

    std::cout << "Harl complains at DEBUG level:" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;

    std::cout << "Harl complains at INFO level:" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;

    std::cout << "Harl complains at WARNING level:" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;

    std::cout << "Harl complains at ERROR level:" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;

    std::cout << "Harl tries to complain at an invalid level:" << std::endl;
    harl.complain("INVALID");

    return 0;
}