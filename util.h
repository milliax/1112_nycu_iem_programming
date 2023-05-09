#pragma once

#include <windows.h>

#include <tuple>

class Util {
   public:
    Util() = default;
    int max(int, int);
    int min(int, int);
    std::pair<int, int> get_cursor();
    void set_cursor(int, int);
};