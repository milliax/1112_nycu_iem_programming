#include "auto_cow.h"

#include <iostream>

using namespace std;

void AutoCow::start() {
    init();
    bool is_passed = false;

    // generate the question

    while (!is_passed) {
        // determine what number to guess
        int* possible_guess = nullptr;
        possible_guess = determine();

        for (int i = 0; i < 4; ++i) {
            cout << possible_guess[i] << " ";
        }
        // guess the number

        delete possible_guess;
        // if passed the break;

        // save the result
    }
}

int* AutoCow::determine() {
    // via possibility table and guess
    int* possible_ans = new int[4];

    if (guess_history.empty()) {
        for (int i = 0; i < 4; ++i) possible_ans[i] = i;
        return possible_ans;
    }

    // i have no idea
    return possible_ans;
}

void AutoCow::init() {
    // clear vector
    guess_history.clear();
    // clear possibility map
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 10; ++j) {
            possibility_map[i][j] = false;
        }
    }
}