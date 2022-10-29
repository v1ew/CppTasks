#include <iostream>
#include "module16.h"

int show_menu() {
    int choice = -1;

    std::string items[] = {
            "Speedometer",
            "A stapler of fractional numbers",
            "Calculator",
            "A mechanical piano",
            "Smart home",
            "Exit"
    };

    int items_count = sizeof items / sizeof items[0];
    for (int i = 0; i < items_count; ++i) {
        std::cout << i + 1 << ". " << items[i] << std::endl;
    }
    bool replay = false;
    do {
        if (replay)
            std::cerr << "Invalid input!" << std::endl;
        std::cout << "Enter task number: ";
        std::cin >> choice;
        std::cout << std::endl;
        replay = true;
    } while (choice < 1 || choice > items_count);

    if (choice > 0 && choice < items_count)
        return choice;
    else
        return 0;
}

void run(int choice) {
    switch (choice) {
        case 1:
            speedometer();
            break;
        case 2:
            fractional();
            break;
        case 3:
            calculator();
            break;
        case 4:
            piano();
            break;
        case 5:
            smart_home();
            break;
        default:
            return;
    }
}

int main() {
    int choice = -1;
    while (choice) {
        choice = show_menu();
        run(choice);
    }
    std::cout << "Bye.\n";

    return 0;
}
