#include "color.h"

#include <iostream>
using namespace std;

bool Colorize::is_good(int x) { return 0 <= x && x < 256; }

void Colorize::set_color(int x) {}

void Colorize::reset() {}

void Colorize::red(string str) {}