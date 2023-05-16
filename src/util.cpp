#include "util.h"

#include <windows.h>

#include <tuple>

std::pair<int, int> Util::get_cursor() {
    HANDLE handle;
    CONSOLE_SCREEN_BUFFER_INFO cbsi;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(handle, &cbsi);
    return std::make_pair(cbsi.dwCursorPosition.X, cbsi.dwCursorPosition.Y);
}

void Util::set_cursor(int x = 0, int y = 0) {
    HANDLE handle;
    COORD coordinates;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(handle, coordinates);
    return;
}

int Util::max(int a, int b) {
    if (a > b) return a;
    return b;
}

int Util::min(int a, int b) {
    if (a > b) return b;
    return a;
}