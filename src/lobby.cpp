#include "lobby.h"

#include <conio.h>
#include <windows.h>

#include <iostream>

using namespace std;

int Lobby::lobby(bool first_time) {
    now_selecting = 1;
    system("cls");
    // bool prefix = false;
    if (first_time) {
        std::cout << "Welcome to This program" << std::endl;
        std::cout << "Using the cursor to select gamemode you want."
                  << std::endl;
        std::cout << "There are Four different games you can try." << std::endl;
    }

    std::pair<int, int> coord = util.get_cursor();

    print_menu(now_selecting, coord);

    while (true) {
        fflush(stdin);
        keys = getch();

        switch (keys) {
            case 72:
                // code for arrow up
                now_selecting = util.max(min, now_selecting - 1);
                break;
            case 80:
                // code for arrow down
                now_selecting = util.min(max, now_selecting + 1);
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

void Lobby::print_menu(int index, std::pair<int, int> coord) {
    using namespace std;
    util.set_cursor(coord.first, coord.second);

    color.print_light_red("Press ctrl-C to exit this program");
    cout << endl;

    if (index == 1)
        color.print_aqua("1. Black Jack");
    else
        cout << "1. Black Jack";
    cout << "\t\r" << endl;

    if (index == 2)
        color.print_aqua("2. Bulls and Cows");
    else
        cout << "2. Bulls and Cows";
    cout << "\t\r" << endl;

    if (index == 3)
        color.print_aqua("3. Decrypt Message");
    else
        cout << "3. Decrypt Message";
    cout << "\t\r" << endl;

    if (index == 4)
        color.print_aqua("4. Automated Bulls and Cows");
    else
        cout << "4. Automated Bulls and Cows";
    cout << "\t\r" << endl;

    return;
}
