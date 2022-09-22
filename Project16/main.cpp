#include <iostream>

int show_menu() {
    int choice = -1;

    std::string lines[] = {
            "Speedometer",
            "A stapler of fractional numbers",
            "Calculator",
            "A mechanical piano",
            "Smart home",
            "Exit"
    };

    std::cout << std::endl;
    int lines_count = sizeof lines / sizeof lines[0];
    for (int i = 0; i < lines_count; ++i) {
        std::cout << i + 1 << ". " << lines[i] << std::endl;
    }
    std::cout << "Enter task number: ";
    std::cin >> choice;

    if (choice > 0 && choice < lines_count)
        return choice;
    else if (choice == lines_count)
        return 0;
    else
        return -1;
}

int main() {
    int choice = -1;
    while (choice) {
        choice = show_menu();
    }
    std::cout << "\nBye.\n";

    return 0;
}
