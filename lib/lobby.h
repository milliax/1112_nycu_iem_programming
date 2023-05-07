#include <conio.h>

#include <iostream>

#include "color.hpp"

int _min(int a, int b) {
    if (a > b) return b;
    return a;
}

int _max(int a, int b) {
    if (a > b) return a;
    return b;
}

namespace lobby {
void print_menu(int index) {
    using namespace std;
    if (index == 1)
        cout << dye::aqua("1. Black Jack") << endl;
    else
        cout << "1. Black Jack" << endl;

    if (index == 2)
        cout << dye::aqua("2. Bulls and Cows") << endl;
    else
        cout << "2. Bulls and Cows" << endl;

    if (index == 3)
        cout << dye::aqua("3. Decrypt Message") << endl;
    else
        cout << "3. Decrypt Message" << endl;

    if (index == 4)
        cout << dye::aqua("4. Automated Bulls and Cows") << endl;
    else
        cout << "4. Automated Bulls and Cows" << endl;

    return;
}

int lobby() {
    int keys;
    int now_selecting = 1;
    int max = 4;
    int min = 1;
    // bool prefix = false;
    std::cout << "Welcome to This program" << std::endl;
    std::cout << "Using the cursor to select gamemode you want." << std::endl;
    std::cout << "There are Four different games you can try." << std::endl;

    print_menu(now_selecting);

    while (true) {
        fflush(stdin);
        keys = getch();

        switch (keys) {
            case 72:
                // code for arrow up
                now_selecting = _max(min, now_selecting - 1);
                break;
            case 80:
                // code for arrow down
                now_selecting = _min(max, now_selecting + 1);
                break;
            case 13:
                return now_selecting;
            case 3:
                std::cout << "Terminate Key detected" << std::endl;
                return 0;
            default:
                break;
        }
        print_menu(now_selecting);
    }

    return 0;
}
}  // namespace lobby