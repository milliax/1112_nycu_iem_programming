#include <fstream>
#include <iostream>

class CaesarCipher {
    int init(std::ifstream*, std::ofstream*);

    void close_stream(std::ifstream*, std::ofstream*);

   public:
    CaesarCipher() = default;
    void play();
};