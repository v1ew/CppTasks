//
// Created by v1ew on 9/23/2022.
//
#include <iostream>

#define NUM_SOUNDS 12

enum note {
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

void piano() {
    std::string input;
    int melody[NUM_SOUNDS];

    std::cout << "Enter a melody:\n";
    for (int i = 0; i < NUM_SOUNDS; ++i) {
        std::cin >> input;
        melody[i] = 0;
        for (int j = 0; j < input.length(); ++j) {
            if (std::isdigit(input[j]) && input[j] - '0' < 8 && input[j] - '0' > 0) {
                melody[i] |= 1 << (input[j] - '0' - 1);
            } else {
                std::cerr << "Invalid symbol - " << input[j] << std::endl;
            }
        }
    }

    std::cout << std::endl;
    for (int i = 0; i < NUM_SOUNDS; ++i) {
        if (melody[i] & DO) {
            std::cout << "DO ";
        }
        if (melody[i] & RE) {
            std::cout << "RE ";
        }
        if (melody[i] & MI) {
            std::cout << "MI ";
        }
        if (melody[i] & FA) {
            std::cout << "FA ";
        }
        if (melody[i] & SOL) {
            std::cout << "SOL ";
        }
        if (melody[i] & LA) {
            std::cout << "LA ";
        }
        if (melody[i] & SI) {
            std::cout << "SI ";
        }
        std::cout << std::endl;
    }
}
