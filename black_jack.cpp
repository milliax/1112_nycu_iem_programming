#include "black_jack.h"

#include <conio.h>

#include <algorithm>
#include <iostream>
#include <vector>

#define card_num 13

using namespace std;

int BlackJack::mini(int a, int b) {
    if (a > b) return b;
    return a;
}

int BlackJack::maxi(int a, int b) {
    if (a > b) return a;
    return b;
}

int BlackJack::cnt_point(int card) {
    if (card % card_num >= 10) {
        return 10;
    }
    if (!(card % card_num)) {
        return 10;
    }
    return card % card_num;
}

std::string BlackJack::get_type(int card) {
    if (!(card % card_num)) {
        return types[card / card_num - 1];
    }
    return types[card / card_num];
}

int BlackJack::cnt_all_points(std::vector<int> cards) {
    int total = 0;
    for (std::vector<int>::iterator it = cards.begin(); it != cards.end();
         ++it) {
        total += cnt_point(*it);
    }
    return total;
}

void BlackJack::print_continue(int index) {
    if (index == 1)
        color.print_aqua("continue getting new cards");
    else
        cout << "continue getting new cards";
    cout << endl;
    if (index == 2)
        color.print_aqua("Stop and check the result");
    else
        cout << "Stop and check the result";
    cout << endl;
}

int BlackJack::biggest_but_less_than_21(std::vector<int> cards) {
    int number_of_1 = 0;
    int sum = 0;
    for (auto card : cards) {
        if (card == 1) {
            number_of_1++;
        } else {
            sum += cnt_point(card);
        }
    }

    int pos = 0;
    int k = 1;
    std::vector<int> combinitions = {sum};

    while (number_of_1--) {
        for (int i = 0; i < k; ++i) {
            combinitions.push_back(combinitions[pos] + 1);
            combinitions.push_back(combinitions[pos++] + 11);
        }
        k *= 2;
    }
    std::vector<int>::iterator it =
        std::upper_bound(combinitions.begin(), combinitions.end(), 21);

    return (it == combinitions.begin()) ? *it : *(it--);
}

void BlackJack::shuffle_arr(int* arr) {
    std::sort(arr, arr + 52, [](int a, int b) {
        return (((double)rand() / (RAND_MAX)) > 0.5);
    });
    return;
}

void BlackJack::list_cards(std::vector<int> cards) {
    for (auto e : cards) {
        int value = e % card_num;
        if (!value) value = card_num;
        std::cout << get_type(e) << " " << value << " ";
    }
    return;
}

void BlackJack::play() {
    int keys;
    int now_selecting = 1;
    int min = 1;
    int max = 2;
    bool selected = false;
    int pos = 0;
    system("cls");
    std::cout << "Black Jack start!!" << std::endl;
    // 21 點

    int cards[52];
    // init
    for (int i = 0; i < 52; ++i) {
        cards[i] = i + 1;
    }

    shuffle_arr(cards);

    std::vector<int> computer_cards;

    // computer get points
    while (cnt_all_points(computer_cards) <= 18) {
        int first = cards[pos++];
        computer_cards.push_back(first);
    }

    std::cout << "Computer has finished choosing its cards" << std::endl;
    std::cout << "now is your turn" << std::endl;

    // TODO: determine whether computer is lost already (cards bigger than
    // 21)
    std::pair<int, int> cursor = util.get_cursor();

    std::vector<int> user_cards;

    // user get new cards;
    int top = cards[pos++];
    user_cards.push_back(top);
    // list all cards user got
    std::cout << "These are Your cards" << std::endl;
    list_cards(user_cards);

    while (cnt_all_points(user_cards) <= 21) {
        std::cout << std::endl;
        // continue? prompt
        std::pair<int, int> continue_cursor = util.get_cursor();
        selected = false;
        print_continue(now_selecting);
        while (true) {
            fflush(stdin);
            keys = getch();
            switch (keys) {
                case 72:
                    // code for arrow up
                    now_selecting = maxi(min, now_selecting - 1);
                    break;
                case 80:
                    // code for arrow down
                    now_selecting = mini(max, now_selecting + 1);
                    break;
                case 13:
                    selected = true;
                    break;
            }
            if (selected) break;
            util.set_cursor(continue_cursor.first, continue_cursor.second);
            print_continue(now_selecting);
        }
        if (selected && now_selecting == 2) break;
        // deploy new card
        int top = cards[pos++];
        user_cards.push_back(top);
        util.set_cursor(cursor.first, cursor.second);
        // list all cards user got
        std::cout << "These are Your cards" << std::endl;
        list_cards(user_cards);
    }

    // printing the result
    std::cout << std::endl << "\33[2K\r" << std::endl << "\33[2K\r";

    if (cnt_all_points(user_cards) > 21) {
        // user must failed or fair
        if (cnt_all_points(computer_cards) > 21) {
            color.print_blue("Fair");
            cout << endl << "Your cards both exceeded 21" << endl;
        } else {
            color.print_purple("You Lost");
            std::cout << endl << "Your cards exceeded 21" << std::endl;
            std::cout << "Computer's cards: ";
            list_cards(computer_cards);
        }
    } else if (cnt_all_points(computer_cards) > 21) {
        // computer lost cards bigger than 21
        color.print_green("You WIN!!");
        std::cout << endl << "Computer's cards exceeded 21" << std::endl;
    } else if (biggest_but_less_than_21(computer_cards) ==
               biggest_but_less_than_21(user_cards)) {
        // fair
        color.print_blue("Fair");
        std::cout << endl << "You got the same number as Computer" << std::endl;
    } else if (biggest_but_less_than_21(computer_cards) >
               biggest_but_less_than_21(user_cards)) {
        // computer wins
        color.print_purple("You Lost");
        std::cout << endl
                  << "Computer's number is bigger than yours" << std::endl;
        std::cout << "Computer's cards: ";
        list_cards(computer_cards);
    } else {
        // user wins
        color.print_green("You WIN!!");
        std::cout << endl
                  << "Your number is bigger than computer's" << std::endl;
    }

    std::cout << std::endl;

    // system("pause");
    return;
}
// };