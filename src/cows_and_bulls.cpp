#include "cows_and_bulls.h"

#include <algorithm>
// #include <color.hpp>
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
    sort(temp, temp + 10,
              [](int, int) { return (((double)rand() / (RAND_MAX)) > 0.5); });
    for (int i = 0; i < 4; ++i) {
        result[i] = temp[i];
    }
    return result;
}

void CowsAndBulls::print_ans(int* ans) {
    for (int i = 0; i < 4; ++i) {
        cout << ans;
    }
    cout << endl;
    return;
}

int* CowsAndBulls::parse_str2int(string input) {
    // static int ans[4];
    int* ans = new int[4];
    for (int i = 0; i < 4; ++i) {
        ans[i] = input[i] - '0';
    }
    return ans;
}

pair<int, int> CowsAndBulls::compare(int* input, int* ans) {
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
    string input;
    system("cls");
    cout << "Cows_and_bulls start!!!" << endl;

    int* ans = generate_question();

    // cout << dye::blue("Instruction:") << endl;
    cout << "You have 10 chances to Guess the correct answer" << endl;
    cout << "Each time you type in the answer I will tell you how many numbers "
            "are in correct place and how many numbers are placed wrongly"
         << endl;
    cout << "In the form of xAxB" << endl;

    cout << endl;

    while (attempts_remain--) {
        std::string str = " Attempt ";
        str += (total_attempts - attempts_remain + '0');
        str += " ";
        // cout << dye::black_on_light_green(str) << endl;
        cout << "Your answer: ";
        bool checked = false;
        do {
            // if (checked) {
            //     cout << "Please insert the correct form of your guess "
            //          << dye::red("4 digits") << endl;
            // }
            checked = true;
            cin >> input;
        } while (!check_input(input));

        int a, b;
        int* tmp_int = parse_str2int(input);
        tie(a, b) = compare(tmp_int, ans);
        delete[] tmp_int;
        if (a == 4) {
            // cout << dye::red_on_light_green(
            //             " Congratulations!! You've resolved the problem ")
            //      << endl;

            resolved = true;
            break;
        }
        cout << endl;
        cout << a << "A" << b << "B" << endl;
    }

    if (!resolved) {
        // cout << dye::black_on_grey("Correct Answer: ");
        for (int i = 0; i < 4; ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    delete[] ans;
    return;
}
