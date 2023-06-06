// #include <color.hpp>
#include <ctime>
#include <iostream>

#include "auto_cow.h"
#include "black_jack.h"
#include "caesar_cipher.h"
#include "cows_and_bulls.h"
#include "lobby.h"

using namespace std;

int main() {
    Lobby lb;
    CaesarCipher cc;
    CowsAndBulls cnb;
    BlackJack bj;
    AutoCow ac;
    srand(time(NULL));
    bool first_time = true;
    while (true) {
        int selection = lb.lobby(first_time);
        first_time = false;
        // std::cout << selection << std::endl;
        switch (selection) {
            case 0:
                cout << endl << "Thank you for playing this game" << endl;
                cout << "Powered By Milliax" << endl;
                return 0;
            case 1:
                // cout << dye::black_on_bright_white("Entering Black Jack")
                //      << endl;
                bj.play();
                system("pause");
                break;
            case 2:
                // cout << dye::black_on_bright_white("Entering Cows and Bulls")
                //      << endl;
                cnb.play();
                system("pause");
                break;
            case 3:
                // cout << dye::black_on_bright_white("Entering Caesar Cipher")
                //      << endl;
                cc.play();
                system("pause");
                break;
            case 4:
                // cout << dye::black_on_bright_white(
                //             "Entering Autoplay Cows and Bulls")
                //      << endl;
                ac.start();
                system("pause");
                break;
            default:
                break;
        }
        std::cout << std::endl;
    }
    return 0;
}