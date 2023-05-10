#include <fstream>
#include <iostream>

#include "color.h"

class CaesarCipher {
    Color color;

    int init(std::ifstream*, std::ofstream*);

    void close_stream(std::ifstream*, std::ofstream*);

   public:
    CaesarCipher() = default;
    void play();
};