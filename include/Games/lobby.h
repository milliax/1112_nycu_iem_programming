#include <Tools/color.h>
#include <Tools/util.h>

#include <iostream>

class Lobby {
    Util util;
    Color color;
    int keys;
    int now_selecting;
    const int max = 4;
    const int min = 1;

   public:
    Lobby() = default;
    int lobby(bool);
    void print_menu(int, std::pair<int, int>);
};