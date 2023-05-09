#include <ctime>
#include <iostream>

#include "black_jack.h"
#include "caesar_cipher.h"
#include "color.h"
#include "cows_and_bulls.h"
#include "lobby.h"

int main() {
    Lobby lb;
    CaesarCipher cc;
    CowsAndBulls cnb;
    BlackJack bj;
    Color color;
    srand(time(NULL));
    bool first_time = true;
    while (true) {
        int selection = lb.lobby(first_time);
        first_time = false;
        // std::cout << selection << std::endl;
        switch (selection) {
            case 0:
                std::cout << std::endl
                          << "Thank you for playing this game" << std::endl;
                std::cout << "Powered By Milliax" << std::endl;
                return 0;
            case 1:
                color.print_black_on_bright_white("Entering Black Jack");
                std::cout << std::endl;
                bj.play();
                system("pause");
                break;
            case 2:
                color.print_black_on_bright_white("Entering Cows and Bulls");
                std::cout << std::endl;
                cnb.play();
                system("pause");
                break;
            case 3:
                color.print_black_on_bright_white("Entering Caesar Cipher");
                std::cout << std::endl;
                system("pause");
                break;
            case 4:
                color.print_black_on_bright_white(
                    "Entering Autoplay Cows and Bulls");
                std::cout << std::endl;
                system("pause");
                break;
            default:
                break;
        }
        std::cout << std::endl;
    }
    return 0;
}