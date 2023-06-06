#include <color.h>

#include <iostream>

#include "util.h"
class Lobby {
    Colorize color;
    Util util;
    int keys;
    int now_selecting;
    const int max = 3;
    const int min = 1;

   public:
    Lobby() = default;
    int lobby(bool);
    void print_menu(int, std::pair<int, int>);
};