#include "color.h"

#include <conio.h>
#include <windows.h>

#include <iostream>
using namespace std;

bool Colorize::is_good(int x) { return 0 <= x && x < 256; }

void Colorize::set_color(int x) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}

void Colorize::set_color(int a, int b) { set_color(a + b * 16); }

void Colorize::reset() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFAULT_COLOR);
}

void Colorize::red(string str) {
    set_color(CODES.at("red"));
    cout << str;
    reset();
}

void Colorize::aqua(string str) {
    set_color(CODES.at("aqua"));
    cout << str;
    reset();
}

void Colorize::blue(string str) {
    set_color(CODES.at("blue"));
    cout << str;
    reset();
}

void Colorize::green(string str) {
    set_color(CODES.at("green"));
    cout << str;
    reset();
}

void Colorize::purple(string str) {
    set_color(CODES.at("purple"));
    cout << str;
    reset();
}

void Colorize::black_on_light_green(string str) {
    set_color(CODES.at("black"), CODES.at("light green"));
    cout << str;
    reset();
}

void Colorize::red_on_light_green(string str) {
    set_color(CODES.at("red"), CODES.at("green"));
    cout << str;
    reset();
}

void Colorize::black_on_grey(string str) {
    set_color(CODES.at("black"), CODES.at("grey"));
    cout << str;
    reset();
}

void Colorize::light_red(string str) {
    set_color(CODES.at("light red"));
    cout << str;
    reset();
}

void Colorize::black_on_bright_white(string str) {
    set_color(CODES.at("black"), CODES.at("bright white"));
    cout << str;
    reset();
}

void Colorize::blue_on_grey(string str) {
    set_color(CODES.at("blue"), CODES.at("grey"));
    cout << str;
    reset();
}

void Colorize::red_on_black(string str) {
    set_color(CODES.at("red"), CODES.at("black"));
    cout << str;
    reset();
}