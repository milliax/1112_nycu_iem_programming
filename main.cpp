#include <iostream>

#include "lib/black_jack.h"
#include "lib/caesar_cipher.h"
#include "lib/color.hpp"
#include "lib/cows_and_bulls.h"
#include "lib/lobby.h"

int main() {
    bool first_time = true;
    while (true) {
        int selection = lobby::lobby(first_time);
        first_time = false;
        std::cout << selection << std::endl;
        switch (selection) {
            case 0:
                std::cout << "Thank you for playing this game" << std::endl;
                std::cout << "Powered By Milliax" << std::endl;
                return 0;
            case 1:
                std::cout << dye::black_on_bright_white("Entering Black Jack")
                          << std::endl;
                black_jack::play();
                system("pause");
                break;
            case 2:
                std::cout << dye::black_on_bright_white(
                                 "Entering Cows and Bulls")
                          << std::endl;
                cows_and_bulls::play();
                system("pause");
                break;
            case 3:
                std::cout << dye::black_on_bright_white(
                                 "Entering Caesar Cipher")
                          << std::endl;
                system("pause");
                break;
            case 4:
                std::cout << dye::black_on_bright_white(
                                 "Entering Autoplay Cows and Bulls")
                          << std::endl;
                system("pause");
                break;
            default:
                break;
        }
        std::cout << std::endl;
    }
    return 0;
}