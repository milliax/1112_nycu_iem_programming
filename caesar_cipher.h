#include <fstream>
#include <iostream>

#include "color.h"

class CaesarCipher {
    Color color;
    std::ifstream input;
    std::ofstream output;

    void init();
    void init(std::string, std::string);

    void close_stream();

   public:
    CaesarCipher() = default;
    void play();
};