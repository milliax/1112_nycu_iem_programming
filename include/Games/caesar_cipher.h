#include <Tools/color.h>

#include <fstream>
#include <iostream>
class CaesarCipher {
    Color color;

    int init(std::ifstream*, std::ofstream*);

    void close_stream(std::ifstream*, std::ofstream*);

   public:
    CaesarCipher() = default;
    void play();
};