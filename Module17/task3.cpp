#include <iostream>
#include <cstring>

bool substr(const char* s1, const char* s2) {
    size_t len_s1 = strlen(s1);
    size_t len_s2 = strlen(s2);
    size_t j;
    
    if (len_s1 >= len_s2) {
        for (size_t i = 0; i <= len_s1 - len_s2; ++i) {
            j = 0;
            while (*(s1 + i + j) == *(s2 + j) && j < len_s2) {
                ++j;
            }
            if (j == len_s2) return true;
        }
    }
    return false;
}

void task3()
{
    const char* a = "Hello world";
    const char* b = "wor";
    const char* c = "banana";
    
    std::cout << substr(a, b) << ", " << substr(a, c) << std::endl;
}

