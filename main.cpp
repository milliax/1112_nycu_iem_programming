#include <iostream>

#include "lib/black_jack.h"
#include "lib/caesar_cipher.h"
#include "lib/cows_and_bulls.h"
#include "lib/lobby.h"

int main() {
    std::cout << "Hello World" << std::endl;
    while (true) {
        int selection = lobby::lobby();
        std::cout << selection << std::endl;
        switch (selection) {
            case 0:
                std::cout << "Thank you for playing this game" << std::endl;
                std::cout << "Powered By Milliax" << std::endl;
                return 0;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                break;
        }
    }
    return 0;
}