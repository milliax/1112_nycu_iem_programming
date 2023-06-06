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
        cout << "Welcome to This program" << endl;
        cout << "Using the cursor to select gamemode you want." << endl;
        cout << "There are Four different games you can try." << endl;
    }

    pair<int, int> coord = util.get_cursor();

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
                cout << "Terminate Key detected" << endl;
                return 0;
            default:
                break;
        }
        print_menu(now_selecting, coord);
    }

    return 0;
}

void Lobby::print_menu(int index, pair<int, int> coord) {
    using namespace std;
    util.set_cursor(coord.first, coord.second);

    color.light_red("Press Ctrl-C to exit this program\n");

    util.clear_line();
    if (index == 1)
        color.aqua("1. Black Jack\n");
    else
        cout << "1. Black Jack" << endl;

    util.clear_line();
    if (index == 2)
        color.aqua("2. Bulls and Cows\n");
    else
        cout << "2. Bulls and Cows" << endl;

    util.clear_line();
    if (index == 3)
        color.aqua("3. Decrypt Message\n");
    else
        cout << "3. Decrypt Message" << endl;

    // util.clear_line();
    // if (index == 4)
    //     color.aqua("4. Automated Bulls and Cows\n");
    // else
    //     cout << "4. Automated Bulls and Cows" << endl;

    return;
}
