#include "color.h"

#include <windows.h>

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <type_traits>
#include <utility>
using namespace std;

bool Colorize::is_good(int a) { return 0 <= a && a < 256; }

void Colorize::reset() {}

void Colorize::set(int a) {
    if (is_good(a)) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

void Colorize::set(int a, int b) { set(a + b * 16); }

void Colorize::set(string a, string b) {}

void Colorize::set_text(string a) {}

void Colorize::set_background(string a) {}

int Colorize::itoc(int a) { return is_good(a) ? a : BAD_COLOR; }

int Colorize::itoc(int a, int b) { return itoc(a + b * 16); }

int Colorize::stoc(string a) {
    // convert s to lowercase, and format variants like  "light_blue"
    transform(a.begin(), a.end(), a.begin(), [](char c) {
        if ('A' <= c && c <= 'Z')
            c = c - 'A' + 'a';
        else if (c == '_' || c == '-')
            c = ' ';
        return c;
    });

    // operator[] on std::map is non-const, use std::map::at instead
    return (CODES.find(a) != CODES.end()) ? CODES.at(a) : BAD_COLOR;
}

int Colorize::stoc(string a, string b) { return itoc(stoc(a), stoc(b)); }

// int Colorize::ctoc(int a) {
//     return is_good(a) ? "(text) " + NAMES.at(a % 16) + " + " +
//                                      "(background) " + NAMES.at(a / 16)
//                                : "BAD COLOR";
// }

int Colorize::color_get() {
    CONSOLE_SCREEN_BUFFER_INFO i;
    return GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &i)
               ? i.wAttributes
               : BAD_COLOR;
}

int Colorize::get_text() {
    return (color_get() != BAD_COLOR) ? color_get() % 16 : BAD_COLOR;
}

int Colorize::get_background() {
    return (color_get() != BAD_COLOR) ? color_get() / 16 : BAD_COLOR;
}

int Colorize::invert(int c) {
    if (is_good(c)) {
        int a = c % 16;
        int b = c / 16;
        return b + a * 16;
    }
    return BAD_COLOR;
}

// template<typename T> Colorize::colorful<T> operator+(colorful<T>
// lhs,colorful<T> rhs){

// }

template <typename T>
std::ostream& operator<<(std::ostream& os, const colorful<T>& colorful) {
    for (const auto& elem : colorful) os << elem;
    return os;
}

template <typename T>
Colorize::colorful<T> invert(colorful<T> col) {
    colorful<T> res(std::move(col));
    for (auto& elem : res) elem.invert();
    return res;
}

template <typename T>
class Colorize::item {
    T thing;
    int color;

   public:
    item(T t) : thing(std::move(t)), color(color_get()) {}
    item(T t, int a) : thing(std::move(t)), color(itoc(a)) {}
    item(T t, int a, int b) : thing(std::move(t)), color(itoc(a, b)) {}
    item(T t, std::string a) : thing(std::move(t)), color(stoc(a)) {}
    item(T t, std::string a, std::string b)
        : thing(std::move(t)), color(stoc(a, b)) {}

    item<T>& invert() {
        color = invert(color);
        return *this;
    }

    template <typename U>
    friend class colorful;

    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const item<U>&);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const item<T>& it) {
    hue::set(it.color);
    os << it.thing;
    hue::reset();
    return os;
}

template <typename T>
Colorize::R<T> Colorize::colorize(T, std::string str) {
    return R<T>{S<T>(t, str)};
}

std::ostream& Colorize::color_red(std::ostream& os) {
    set_text("r");
    return os;
}