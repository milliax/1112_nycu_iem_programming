#include "black_jack.h"

#include <conio.h>

#include <algorithm>
#include <iostream>
#include <vector>

#define card_num 13

using namespace std;

int BlackJack::card_point(int card) {
    if (card % card_num >= 10) {
        return 10;
    }
    if (!(card % card_num)) {
        return 10;
    }
    return card % card_num;
}

string BlackJack::get_card_value(int value) {
    int temp = value % card_num;
    switch (temp) {
        case 1:
            return "A";
        case 10:
            return "10";
        case 11:
            return "J";
        case 12:
            return "Q";
        case 0:
            return "K";
    }
    string a = "0";
    a[0] += temp;
    return a;
}

std::string BlackJack::get_type(int card) {
    if (!(card % card_num)) {
        return types[card / card_num - 1];
    }
    return types[card / card_num];
}

int BlackJack::cnt_all_points(std::vector<int>* cards) {
    int total = 0;
    for (std::vector<int>::iterator it = cards->begin(); it != cards->end();
         ++it) {
        total += card_point(*it);
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

void BlackJack::swap_vector(vector<int>* a, vector<int>* b) {
    auto t = a;
    a = b;
    b = t;
    return;
}

int BlackJack::biggest_but_less_than_21(std::vector<int> cards) {
    int number_of_1 = 0;
    int sum = 0;

    for (int card : cards) {
        if ((card % 13) == 1) {
            number_of_1++;
        } else {
            sum += card_point(card);
        }
    }

    vector<int>* combinitions = new vector<int>;
    vector<int>* temp = new vector<int>;
    combinitions->push_back(sum);

    for (int i = 0; i < number_of_1; ++i) {
        temp->clear();
        for (int e : *combinitions) {
            temp->push_back(e + 1);
            temp->push_back(e + 11);
        }

        combinitions->swap(*temp);
    }

    auto it = std::upper_bound(combinitions->begin(), combinitions->end(), 21);

    return (it == combinitions->begin()) ? *it : *(--it);
}

void BlackJack::shuffle_cards() {
    std::sort(cards, cards + 52, [](int, int) {
        return (((double)rand() / (RAND_MAX)) > 0.5);
    });
    return;
}

void BlackJack::list_cards(std::vector<int> cards) {
    for (auto e : cards) {
        std::cout << get_type(e) << " " << get_card_value(e) << " ";
    }
    return;
}

void BlackJack::get_card(std::vector<int>* card) {
    int top = cards[pos++];
    card->push_back(top);
    return;
}

void BlackJack::show_user_cards(pair<int, int> cursor_pos) {
    util.set_cursor(cursor_pos.first, cursor_pos.second);
    std::cout << "These are Your cards" << std::endl;
    list_cards(user_cards);
    return;
}

void BlackJack::play() {
    // preparing for a new game
    now_selecting = 1;
    min = 1;
    max = 2;
    selected = false;
    pos = 0;
    computer_cards.clear();
    user_cards.clear();
    for (int i = 0; i < 52; ++i) {
        cards[i] = i + 1;
    }
    shuffle_cards();

    system("cls");
    std::cout << "Black Jack start!!" << std::endl;
    // 21 點

    // computer get points

    do {
        std::cout << "Computer got a card" << endl;
        get_card(&computer_cards);
    } while (cnt_all_points(&computer_cards) <= 18);

    std::cout << "Computer has finished choosing its/his/her cards"
              << std::endl;
    std::cout << "Now is your turn" << std::endl;

    std::pair<int, int> cursor = util.get_cursor();

    // user get new cards;
    get_card(&user_cards);
    show_user_cards(cursor);

    do {
        // list all cards user got

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
                    now_selecting = util.max(min, now_selecting - 1);
                    break;
                case 80:
                    // code for arrow down
                    now_selecting = util.min(max, now_selecting + 1);
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
        // user get new cards;
        get_card(&user_cards);
        show_user_cards(cursor);
    } while (cnt_all_points(&user_cards) <= 21);

    // printing the result

    std::cout << std::endl << "\33[2K\r" << std::endl << "\33[2K\r";

    int computer_points = biggest_but_less_than_21(computer_cards);
    int user_points = biggest_but_less_than_21(user_cards);

    // cout << "Computer points: " << computer_points << endl;
    // cout << "User points: " << user_points << endl;

    if (user_points > 21 && computer_points > 21) {
        // fair
        print_fair("Your cards both exceeded 21");
    } else if (user_points > 21) {
        // computer wins
        print_computer_wins("Your cards exceeded 21");
    } else if (computer_points > 21) {
        // user wins
        print_user_wins("Computer's cards exceeded 21");
    } else if (user_points == computer_points) {
        // fair
        print_fair("You got the same number as Computer");
    } else if (user_points > computer_points) {
        // user wins
        print_user_wins("Your number is bigger than computer's");
    } else {
        // computer wins
        print_computer_wins("Computer's number is bigger than yours");
    }

    // system("pause");
    return;
}
// };

void BlackJack::print_fair(string reason) {
    color.print_blue("Fair");

    cout << endl << reason << endl;
    print_points();
    return;
}

void BlackJack::print_user_wins(string reason) {
    color.print_green("You WIN!!");
    std::cout << endl << reason << std::endl;
    print_points();
    return;
}

void BlackJack::print_computer_wins(string reason) {
    color.print_purple("You Lost");
    std::cout << endl << reason << std::endl;
    print_points();
    return;
}

void BlackJack::print_points() {
    std::cout << "Computer's cards: ";
    list_cards(computer_cards);
    std::cout << std::endl;
    cout << "Your Points: " << biggest_but_less_than_21(user_cards) << endl;
    cout << "Computer's Points: " << biggest_but_less_than_21(computer_cards)
         << endl;
    return;
}