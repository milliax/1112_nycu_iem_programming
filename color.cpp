#include "color.h"

#include <windows.h>

#include <iostream>

using namespace std;

void Color::setColor(int k) {
    SetConsoleTextAttribute(hConsole, k);
    return;
}

void Color::resetColor() {
    setColor(7);
    return;
}

void Color::setColor(int a, int b) {
    setColor(a + b * 16);
    return;
}

void Color::print_aqua(std::string str) {
    setColor(3);
    cout << str;
    resetColor();
    return;
}

void Color::print_blue(std::string str) {
    setColor(1);
    cout << str;
    resetColor();
    return;
}

void Color::print_purple(std::string str) {
    setColor(5);
    cout << str;
    resetColor();
    return;
}
void Color::print_red(std::string str) {
    setColor(4);
    cout << str;
    resetColor();
    return;
}
void Color::print_green(std::string str) {
    setColor(2);
    cout << str;
    resetColor();
    return;
}
void Color::print_light_red(std::string str) {
    setColor(12);
    cout << str;
    resetColor();
    return;
}
void Color::print_black_on_bright_white(std::string str) {
    setColor(0, 15);
    cout << str;
    resetColor();
    return;
}
void Color::print_black_on_grey(std::string str) {
    setColor(0, 8);
    cout << str;
    resetColor();
    return;
}
void Color::print_black_on_light_green(std::string str) {
    setColor(0, 10);
    cout << str;
    resetColor();
    return;
}
void Color::print_red_on_light_aqua(std::string str) {
    setColor(4, 11);
    cout << str;
    resetColor();
    return;
}
void Color::print_custom(std::string str, int n) {
    setColor(n);
    cout << str;
    resetColor();
    return;
}
