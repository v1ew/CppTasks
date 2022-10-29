#include <iostream>
#include "module17.h"

void reverse(int *arr, size_t len) {
    for (uint i = 0; i < len/2; ++i) {
        swap(arr + i, arr + len - i - 1);
    }
}

void task2()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    
    reverse(arr, 10);
    for (int i = 0; i < 10; ++i) {
        std::cout << *(arr + i) << " ";
    }
    std::cout << std::endl;
}

