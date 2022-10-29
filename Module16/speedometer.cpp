//
// Created by v1ew on 9/23/2022.
//
#include <iostream>

#define MAX_SPEED 150

int compare (float value, float reference, float epsilon) {
    if (value < reference - epsilon)
        return -1;
    if (value > reference + epsilon)
        return 1;
    return 0;
}

void speedometer() {
    float speed = 0;
    float increment;
    char result[100];

    std::cout << "Current speed: " << speed << std::endl;
    do {
        std::cout << "Enter a speed increment: ";
        std::cin >> increment;
        speed += increment;

        if (compare(speed, MAX_SPEED, 0.01) > 0)
            speed = MAX_SPEED;
        else if (compare(speed, 0, 0.01) < 0)
            speed = 0;

        std::sprintf(result, "%.1f", speed);
        std::cout << "Current speed: " << result << std::endl;
    } while (compare(speed, 0, 0.01));
}
