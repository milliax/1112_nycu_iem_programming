#ifndef __COWS_AND_BULLS_H
#define __COWS_AND_BULLS_H

#include <algorithm>
#include <cstdlib>
#include <iostream>

class CowsAndBulls {
    const int total_attempts = 10;

   public:
    CowsAndBulls() = default;
    int* generate_question();
    void print_ans(int*);
    int* parse_str2int(std::string);

    std::pair<int, int> compare(int*, int*);

    bool check_input(std::string);
    void play();
};

#endif