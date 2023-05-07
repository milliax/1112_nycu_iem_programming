#include <conio.h>
#include <windows.h>

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
std::pair<int, int> get_cursor() {
    HANDLE handle;
    CONSOLE_SCREEN_BUFFER_INFO cbsi;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(handle, &cbsi);
    return std::make_pair(cbsi.dwCursorPosition.X, cbsi.dwCursorPosition.Y);
}

void set_cursor(int x = 0, int y = 0) {
    HANDLE handle;
    COORD coordinates;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(handle, coordinates);
    return;
}

void print_menu(int index, std::pair<int, int> coord) {
    using namespace std;
    set_cursor(coord.first, coord.second);
    if (index == 1)
        cout << dye::aqua("1. Black Jack") << "\t\r" << endl;
    else
        cout << "1. Black Jack"
             << "\t\r" << endl;

    if (index == 2)
        cout << dye::aqua("2. Bulls and Cows") << "\t\r" << endl;
    else
        cout << "2. Bulls and Cows"
             << "\t\r" << endl;

    if (index == 3)
        cout << dye::aqua("3. Decrypt Message") << "\t\r" << endl;
    else
        cout << "3. Decrypt Message"
             << "\t\r" << endl;

    if (index == 4)
        cout << dye::aqua("4. Automated Bulls and Cows") << "\t\r" << endl;
    else
        cout << "4. Automated Bulls and Cows"
             << "\t\r" << endl;

    return;
}

int lobby(bool first_time) {
    int keys;
    int now_selecting = 1;
    int max = 4;
    int min = 1;
    // bool prefix = false;
    if (first_time) {
        std::cout << "Welcome to This program" << std::endl;
        std::cout << "Using the cursor to select gamemode you want."
                  << std::endl;
        std::cout << "There are Four different games you can try." << std::endl;
    }

    std::pair<int, int> coord = get_cursor();

    print_menu(now_selecting, coord);

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
        print_menu(now_selecting, coord);
    }

    return 0;
}
}  // namespace lobby