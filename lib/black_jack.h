#include <iostream>
#include <vector>

#define card_num 13

namespace black_jack {
int _min(int,int);
int _max(int,int);
std::string types[4];

int cnt_point(int);

std::string get_type(int);

int cnt_all_points(std::vector<int>);

void print_continue(int);

int biggest_but_less_than_21(std::vector<int>);

void shuffle_arr(int* );

void list_cards(std::vector<int>);

void play();
}  // namespace black_jack