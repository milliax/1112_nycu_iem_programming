#ifndef __COLORED_H
#define __COLORED_H

#include <windows.h>

#include <iostream>

class Color {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    void setColor(int);
    void setColor(int, int);
    void resetColor();

   public:
    Color() = default;
    void print_aqua(std::string);
    void print_blue(std::string);
    void print_purple(std::string);
    void print_green(std::string);
    void print_light_red(std::string);
    void print_red(std::string);
    void print_black_on_light_green(std::string);
    void print_red_on_light_aqua(std::string);
    void print_black_on_grey(std::string);
    void print_black_on_bright_white(std::string);
    void print_custom(std::string, int);
};

#endif