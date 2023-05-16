#include "cows_and_bulls.h"

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <tuple>

using namespace std;

int* CowsAndBulls::generate_question() {
    // static int result[4];
    int* result = new int[4];
    int temp[10];
    for (int i = 0; i < 10; ++i) {
        temp[i] = i;
    }
    std::sort(temp, temp + 10,
              [](int, int) { return (((double)rand() / (RAND_MAX)) > 0.5); });
    for (int i = 0; i < 4; ++i) {
        result[i] = temp[i];
    }
    return result;
}

void CowsAndBulls::print_ans(int* ans) {
    for (int i = 0; i < 4; ++i) {
        std::cout << ans;
    }
    std::cout << std::endl;
    return;
}

int* CowsAndBulls::parse_str2int(std::string input) {
    // static int ans[4];
    int* ans = new int[4];
    for (int i = 0; i < 4; ++i) {
        ans[i] = input[i] - '0';
    }
    return ans;
}

std::pair<int, int> CowsAndBulls::compare(int* input, int* ans) {
    int a = 0;
    int b = 0;
    bool table[10] = {};
    for (int i = 0; i < 4; ++i) {
        table[ans[i]] = true;
    }

    for (int i = 0; i < 4; ++i) {
        if (input[i] == ans[i]) {
            a++;
        }
        if (table[input[i]]) {
            b++;
        }
    }
    b -= a;
    return std::make_pair(a, b);
}

bool CowsAndBulls::check_input(std::string input) {
    if (input.size() != 4) {
        return false;
    }
    for (int i = 0; i < 4; ++i) {
        if (input[i] > '9' || input[i] < '0') return false;
    }
    return true;
}

void CowsAndBulls::play() {
    int attempts_remain = total_attempts;
    bool resolved = false;
    std::string input;
    system("cls");
    std::cout << "Cows_and_bulls start!!!" << std::endl;

    int* ans = generate_question();

    color.print_blue("Instruction:");
    std::cout << endl
              << "You have 10 chances to Guess the correct answer" << std::endl;
    std::cout
        << "Each time you type in the answer I will tell you how many numbers "
           "are in correct place and how many numbers are placed wrongly"
        << std::endl;
    std::cout << "In the form of xAxB" << std::endl;

    std::cout << std::endl;

    while (attempts_remain--) {
        std::string str = " Attempt ";
        str += (total_attempts - attempts_remain + '0');
        str += " ";
        color.print_black_on_light_green(str);
        std::cout << endl << "Your answer: ";
        bool checked = false;
        do {
            if (checked) {
                std::cout << "Please insert the correct form of your guess ";
                color.print_red("4 digits");
                cout << endl;
            }
            checked = true;
            std::cin >> input;
        } while (!check_input(input));

        int a, b;
        int* tmp_int = parse_str2int(input);
        tie(a, b) = compare(tmp_int, ans);
        delete [] tmp_int;
        if (a == 4) {
            color.print_red_on_light_aqua(
                " Congratulations!! You've resolved the problem ");
            cout << endl;
            resolved = true;
            break;
        }
        std::cout << std::endl;
        std::cout << a << "A" << b << "B" << std::endl;
    }

    if (!resolved) {
        color.print_black_on_grey("Correct Answer: ");
        for (int i = 0; i < 4; ++i) {
            std::cout << ans[i] << " ";
        }
        std::cout << std::endl;
    }


    delete [] ans;
    return;
}
