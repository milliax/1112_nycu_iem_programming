#include "auto_cow.h"

#include <color.hpp>
#include <iostream>

using namespace std;

void AutoCow::start() {
    system("cls");
    init();
    bool is_passed = false;

    // generate the question
    // int* ans = cb.generate_question();
    int* ans = user_input_numbers();

    // cout << "This"

    while (!is_passed) {
        // determine what number to guess
        int* possible_guess = nullptr;
        possible_guess = determine();

        for (int i = 0; i < 4; ++i) {
            cout << possible_guess[i] << " ";
        }

        // guess the number
        pair<int, int> result = cb.compare(possible_guess, ans);

        // if passed the break;

        if (result.first == 4) {
            cout << "Computer got the answer" << endl;
            break;
        }

        // save the result
        save_guess(possible_guess, &result);
        save_status();
        delete[] possible_guess;
    }

    // end of program
    delete[] ans;
    return;
}

int* AutoCow::user_input_numbers() {
    string input;
    bool valid_numbers[10];
    int* result = new int[4];
    bool valid;
    bool first_time = true;

    cout << "Please Input four digits of numbers that does not repeat." << endl;
    cout << "Computer will try its best to solve it." << endl;

    while (true) {
        memset(valid_numbers, false, sizeof(valid_numbers));
        valid = true;

        // print dialog to user
        if (!first_time) {
            cout << "Please Input " << dye::red_on_black("Four digits")
                 << " of numbers that " << dye::red_on_black("does not repeat.")
                 << endl;
        }
        first_time = false;
        cin >> input;

        // validate input numbers
        if (input.size() != 4) continue;

        for (int i = 0; i < 4; ++i) {
            if (valid_numbers[input[i] - '0']) {
                valid = false;
                break;
            }
            valid_numbers[input[i] - '0'] = true;
            result[i] = input[i] - '0';
        }

        if (valid) break;
    }
    return result;
}

void AutoCow::save_status() {
    Guess last_guess = guess_history.back();
    int sum_of_AB = last_guess.result.first + last_guess.result.second;

    int numbers[10] = {};
    switch (sum_of_AB) {
        case 0:
            // 4 digits in history.guess definately not the answer
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    possibility_map[i][last_guess.guess[i]] = false;
                }
            }
            break;
        case 4:
            // 4 digits in history.guess are answers but permutation is
            // incorrect
            ans_appeared = 4;

            for (int i = 0; i < 4; ++i) {
                numbers[last_guess.guess[i]] = true;
            }
            for (int i = 0; i < 10; ++i) {
                if (numbers[i]) continue;
                for (int j = 0; j < 4; ++j) {
                    possibility_map[j][i] = false;
                }
            }

            break;
        default:
            // 1,2,3 if no unexpected error
            ans_appeared += sum_of_AB;
            // TODO: we need to do something but i dont know
    }

    if (ans_appeared == 4) {
        // can narrow down the possibility_map;
    }

    return;
}

void AutoCow::save_guess(int* guess, pair<int, int>* result) {
    Guess temp;
    for (int i = 0; i < 4; ++i) {
        temp.guess[i] = guess[i];
    }
    temp.result = *result;
    guess_history.push_back(temp);
    return;
}

int* AutoCow::determine() {
    // via possibility table and guess
    int* possible_ans = new int[4];

    if (guess_history.empty()) {
        for (int i = 0; i < 4; ++i) possible_ans[i] = i;
        return possible_ans;
    }

    // Guess last_guess = guess_history.back();

    return possible_ans;
}

void AutoCow::init() {
    // clear vector
    guess_history.clear();
    ans_appeared = 0;
    // clear possibility map
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 10; ++j) {
            // every number in any place could be answer
            possibility_map[i][j] = true;
        }
    }
}