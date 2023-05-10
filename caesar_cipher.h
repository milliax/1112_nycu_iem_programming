#include <fstream>
#include <iostream>

#include "color.h"

class CaesarCipher {
    Color color;

    int init(std::fstream*, std::fstream*);

    void close_stream(std::fstream*, std::fstream*);

   public:
    CaesarCipher() = default;
    void play();
};