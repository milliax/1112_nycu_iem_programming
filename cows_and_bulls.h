#include <algorithm>
#include <cstdlib>
#include <iostream>

#include "color.hpp"

namespace cows_and_bulls {
int* generate_question();
int* parse_str2int(std::string);

std::pair<int, int> compare(int*, int*);

bool check_input(std::string);

void print_ans(int*);
void play();
}  // namespace cows_and_bulls