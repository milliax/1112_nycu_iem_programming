#include <Tools/color.h>

#include <algorithm>
#include <cstdlib>
#include <iostream>

class CowsAndBulls {
    Color color;
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