#include <iostream>
#include <vector>

#include "color.h"
#include "util.h"

class BlackJack {
    Util util;
    Color color;
    std::string types[4] = {"♠", "♥", "♦", "♣"};

   public:
    BlackJack() = default;

    int mini(int, int);
    int maxi(int, int);

    std::string get_type(int);

    int cnt_point(int);
    int cnt_all_points(std::vector<int>);
    int biggest_but_less_than_21(std::vector<int>);
    void print_continue(int);
    void shuffle_arr(int*);
    void list_cards(std::vector<int>);
    void play();
};