#pragma once

#include <windows.h>

#include <tuple>

namespace util {
std::pair<int, int> get_cursor();

void set_cursor(int, int);
}  // namespace util