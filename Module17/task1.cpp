#include <iostream>

void swap(int *a, int *b) {
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}


void task1()
{
    int a = 10;
    int b = 20;

	std::cout << "Before swap: a = " << a << ", " << "b = " << b << "\n";
    swap(&a, &b);
	std::cout << "After swap:  a = " << a << ", " << "b = " << b << "\n";
}

