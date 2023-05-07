// #include <windows.h>
#include <conio.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#include "color.hpp"
#include "util.h"

namespace black_jack {
int _min(int a, int b) {
    if (a > b) return b;
    return a;
}

int _max(int a, int b) {
    if (a > b) return a;
    return b;
}
std::string types[4] = {"♠", "♥", "♦", "♣"};
int cnt_point(int card) {
    if (card % 12 >= 10) {
        return 10;
    }
    if (!(card % 12)) {
        return 10;
    }
    return card % 12;
}

std::string get_type(int card) {
    if (!(card % 12)) {
        return types[card / 12 - 1];
    }
    return types[card / 12];
}

int cnt_all_points(std::vector<int> cards) {
    int total = 0;
    for (std::vector<int>::iterator it = cards.begin(); it != cards.end();
         ++it) {
        if (!(*it % 12)) {
            total += 10;
        } else if (*it % 12 < 10) {
            total += *it % 12;
        } else {
            total += 10;
        }
    }
    return total;
}

void print_continue(int index) {
    if (index == 1)
        std::cout << dye::aqua("continue getting new cards") << std::endl;
    else
        std::cout << "continue getting new cards" << std::endl;

    if (index == 2)
        std::cout << dye::aqua("Stop and check the result") << std::endl;
    else
        std::cout << "Stop and check the result" << std::endl;
}

int biggest_but_less_than_21(std::vector<int> cards) {
    // TODO: card 1 is not determined yet.
    return cnt_all_points(cards);
}

void play() {
    int keys;
    int now_selecting = 1;
    int min = 1;
    int max = 2;
    bool selected = false;
    std::cout << "Black Jack start!!" << std::endl;
    // 21 點

    int cards[52];
    // init
    for (int i = 0; i < 52; ++i) {
        cards[i] = i + 1;
    }
    std::random_shuffle(cards, cards + 52);
    std::queue<int> random_cards;
    for (int i = 0; i < 52; ++i) {
        random_cards.push(cards[i]);
    }

    int computer_total = 0;
    std::vector<int> computer_cards;

    // computer get points
    while (computer_total <= 18) {
        int last = random_cards.front();
        random_cards.pop();
        computer_total += cnt_point(last);
        computer_cards.push_back(last);
    }

    std::cout << "Computer has finished choosing its cards" << std::endl;
    std::cout << "now is your turn" << std::endl;

    // TODO: determine whether computer is lost already (cards bigger than 21)
    std::pair<int, int> cursor = util::get_cursor();

    std::vector<int> user_cards;

    // user get new cards;
    int top = random_cards.front();
    random_cards.pop();
    user_cards.push_back(top);

    while (cnt_all_points(user_cards) <= 21) {
        util::set_cursor(cursor.first, cursor.second);
        // list all cards user got
        std::cout << "These are Your cards" << std::endl;
        for (std::vector<int>::iterator it = user_cards.begin();
             it != user_cards.end(); ++it) {
            int value = *it / 12;
            if (!value) value = 12;
            std::cout << get_type(*it) << " " << value << " ";
        }
        std::cout << std::endl;
        // continue? prompt
        std::pair<int, int> continue_cursor = util::get_cursor();
        selected = false;
        print_continue(now_selecting);
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
                    std::cout << "Enter CLicked" << std::endl;
                    selected = true;
                    break;
            }
            if (selected) break;
            int top = random_cards.front();
            random_cards.pop();
            user_cards.push_back(top);
            util::set_cursor(continue_cursor.first, continue_cursor.second);
            print_continue(now_selecting);
        }
        if (selected && now_selecting == 2) break;
    }

    // printing the result

    if (cnt_all_points(user_cards) > 21) {
        // user must failed
        std::cout << dye::purple("You Lost") << std::endl;
        std::cout << "Your cards exceed 21" << std::endl;
    } else if (cnt_all_points(computer_cards) > 21) {
        // computer lost cards bigger than 21
        std::cout << dye::green("You WIN !!") << std::endl;
        std::cout << "Computer's cards exceed 21" << std::endl;
    } else if (biggest_but_less_than_21(computer_cards) ==
               biggest_but_less_than_21(user_cards)) {
        // fair
        std::cout << dye::blue("Fair") << std::endl;
        std::cout << "You got the same number as Computer" << std::endl;
    } else if (biggest_but_less_than_21(computer_cards) >
               biggest_but_less_than_21(user_cards)) {
        // computer wins
        std::cout << dye::purple("You Lost") << std::endl;
        std::cout << "Computer's number is bigger than yours" << std::endl;
    } else {
        // user wins
        std::cout << dye::green("You WIN !!") << std::endl;
        std::cout << "Your number is bigger than computer's" << std::endl;
    }

    // system("pause");
    return;
}
}  // namespace black_jack