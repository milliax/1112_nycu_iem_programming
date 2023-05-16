#include <utility>
#include <vector>

struct Guess {
    int guess[4];
    std::pair<int, int> result;
};

class AutoCow {
    bool possibility_map[4][10];
    std::pair<int,int> guess(int[4]);
    int* determine();
    void init();
    std::vector<Guess> guess_history;

   public:
    AutoCow() = default;

    void start();
};