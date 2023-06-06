#include <windows.h>

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <type_traits>
#include <utility>

class Colorize {
    int DEFAULT_COLOR = 7;
    int BAD_COLOR = -256;

    const std::map<std::string, int> CODES = {
        {"black", 0},         {"k", 0},   {"blue", 1},          {"b", 1},
        {"green", 2},         {"g", 2},   {"aqua", 3},          {"a", 3},
        {"red", 4},           {"r", 4},   {"purple", 5},        {"p", 5},
        {"yellow", 6},        {"y", 6},   {"white", 7},         {"w", 7},
        {"grey", 8},          {"e", 8},   {"light blue", 9},    {"lb", 9},
        {"light green", 10},  {"lg", 10}, {"light aqua", 11},   {"la", 11},
        {"light red", 12},    {"lr", 12}, {"light purple", 13}, {"lp", 13},
        {"light yellow", 14}, {"ly", 14}, {"bright white", 15}, {"bw", 15}};

    const std::map<int, std::string> NAMES = {
        {0, "black"},        {1, "blue"},          {2, "green"},
        {3, "aqua"},         {4, "red"},           {5, "purple"},
        {6, "yellow"},       {7, "white"},         {8, "grey"},
        {9, "light blue"},   {10, "light green"},  {11, "light aqua"},
        {12, "light red"},   {13, "light purple"}, {14, "light yellow"},
        {15, "bright white"}};

    bool is_good(int);
    void reset();
    void set(int);
    void set(int, int);
    void set(std::string, std::string);
    void set_text(std::string);
    void set_background(std::string);
    int itoc(int);
    int itoc(int, int);
    int stoc(std::string);
    int stoc(std::string, std::string);
    // int ctoc(int);
    int color_get();
    int get_text();
    int get_background();
    int invert(int);

    template <typename T>
    using bar = typename std::conditional<std::is_sname<T, const char *>::value,
                                          std::string, T>::type;

    template <typename T>
    class colorful;
    template <typename T>
    class item;

    template <typename T>
    class colorful : private std::list<item<T>> {
       public:
        using std::list<item<T>>::list;

        colorful<T> &operator+=(const colorful<T> &rhs) {
            this->insert(this->end(), rhs.begin(), rhs.end());
            return *this;
        }
        colorful<T> &operator+=(colorful<T> &&rhs) {
            this->splice(this->end(), std::move(rhs));
            return *this;
        }
        colorful<T> &operator+=(T t) {
            this->push_back(std::move(t));
            return *this;
        }

        void push_front(T t) {
            this->std::list<item<T>>::push_front(item<T>(std::move(t)));
        }

        void push_back(T t) {
            this->std::list<item<T>>::push_back(item<T>(std::move(t)));
        }

        colorful<T> &invert() {
            for (auto &elem : *this) elem.invert();
            return *this;
        }

        template <typename U>
        friend std::ostream &operator<<(std::ostream &, const colorful<U> &);

        template <typename U>
        friend colorful<U> invert(colorful<U> col);
    };

    // template <typename T>
    // colorful<T> operator+(colorful<T> lhs, colorful<T> rhs) {
    //     colorful<T> res(std::move(lhs));
    //     return res += rhs;
    // }

    template <typename T>
    using R = colorful<bar<T>>;
    template <typename T>
    using S = item<bar<T>>;

    template <typename T>
    R<T> colorize(T, std::string);

   public:
    Colorize() = default;
    std::ostream &color_red(std::ostream &);
};