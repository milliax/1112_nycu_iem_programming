#include <iostream>
#include <vector>

#define card_num 13

namespace black_jack {
int _min(int, int);
int _max(int, int);

// std::string types[4];
std::string get_type(int);

int cnt_point(int);
int cnt_all_points(std::vector<int>);
int biggest_but_less_than_21(std::vector<int>);
void print_continue(int);
void shuffle_arr(int*);
void list_cards(std::vector<int>);
void play();
}  // namespace black_jack