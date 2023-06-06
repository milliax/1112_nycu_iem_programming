#ifndef __COLOR_H
#define __COLOR_H

#include <iostream>
#include <map>

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
    void set_color(int);
    void set_color(int, int);
    void reset();

   public:
    Colorize() = default;
    void red(std::string);
    void aqua(std::string);
    void blue(std::string);
    void green(std::string);
    void purple(std::string);
    void black_on_light_green(std::string);
    void red_on_light_green(std::string);
    void black_on_grey(std::string);
    void light_red(std::string);
    void black_on_bright_white(std::string);
    void blue_on_grey(std::string);
    void red_on_black(std::string);
};

#endif