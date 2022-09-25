//
// Created by v1ew on 9/23/2022.
//
#include <iostream>
#include <sstream>

void calculator() {
    std::string buffer;
    double op1, op2;
    char operation;
    std::stringstream buffer_stream;
    std::cout << "Enter an expression without whitespaces: ";
    std::cin >> buffer;

    if (buffer.length() == 0) {
        std::cerr << "Expression not found." << std::endl;
        return;
    }

    buffer_stream << buffer;
    buffer_stream >> op1;
    while (!buffer_stream.eof()) {
        buffer_stream >> operation >> op2;
        switch (operation) {
            case '+':
                op1 += op2;
                break;
            case '-':
                op1 -= op2;
                break;
            case '*':
                op1 *= op2;
                break;
            case '/':
                op1 /= op2;
                break;
            default:
                std::cerr << "Unknown operation [" << operation << "]" << std::endl;
        }
    }
    std::cout << "Result: " << op1 << std::endl;
}
