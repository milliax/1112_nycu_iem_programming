#include <Tools/color.h>
#include <Tools/util.h>

#include <iostream>
#include <vector>

class BlackJack {
    Util util;
    Color color;
    std::string types[4] = {"♠", "♥", "♦", "♣"};
    std::vector<int> computer_cards;
    std::vector<int> user_cards;
    int keys, now_selecting, min, max, selected, pos;
    int cards[52];

    void print_fair(std::string);
    void print_user_wins(std::string);
    void print_computer_wins(std::string);
    void print_points();
    void get_card(std::vector<int>*);
    void show_user_cards(std::pair<int, int>);
    void swap_vector(std::vector<int>*, std::vector<int>*);
    std::string get_card_value(int);

   public:
    BlackJack() = default;

    std::string get_type(int);

    int card_point(int);
    int cnt_all_points(std::vector<int>*);
    int biggest_but_less_than_21(std::vector<int>);
    void print_continue(int);
    void shuffle_cards();
    void list_cards(std::vector<int>);
    void play();
};