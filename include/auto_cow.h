#include <color.h>

#include <set>
#include <utility>
#include <vector>

#include "cows_and_bulls.h"
struct Guess {
    int guess[4];
    std::pair<int, int> result;
};

class AutoCow {
    Colorize color;
    CowsAndBulls cb;
    // std::pair<int,std::vector<int>> ans_appeared;
    std::set<int> ans_appeared_numbers;
    short ans_appeared;
    bool possibility_map[4][10];

    int* user_input_numbers();
    int* determine();
    void init();
    void save_guess(int*, std::pair<int, int>*);
    void save_status();
    std::pair<int, int> guess(int[4]);
    std::vector<Guess> guess_history;

   public:
    AutoCow() = default;
    void start();
};