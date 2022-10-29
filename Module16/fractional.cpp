//
// Created by v1ew on 9/23/2022.
//
#include <iostream>

void fractional() {
    int integer_part, fractional_part;

    std::cout << "Enter an integer part: ";
    std::cin >> integer_part;
    std::cout << "Enter an fractional part: ";
    std::cin >> fractional_part;

    double result;
    char buf[100];
    std::sprintf(buf, "%d.%d", integer_part, fractional_part);
    result = std::stod(buf);
    std::cout << "Result is: " << result << std::endl;
}
