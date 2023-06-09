#include "caesar_cipher.h"

#include <stdio.h>

// #include <color.hpp>
#include <fstream>
#include <iostream>
using namespace std;

void CaesarCipher::play() {
    cout << "Caesar_cipher start!!" << endl;

    ifstream input;
    ofstream output;

    cout << "Opening file" << endl;
    if (init(&input, &output)) {
        color.black_on_light_green(" Failed Opening Files \n");
        color.black_on_bright_white(" Returnning to Lobby \n");
        return;
    }
    system("cls");
    system("start encrypt.txt");
    string str;
    int padding;

    getline(input, str);
    input >> padding;

    for (unsigned long long i = 0; i < str.size(); ++i) {
        char temp;
        if (str[i] >= 'a' && str[i] <= 'z') {
            // 小寫
            temp = str[i] - padding;
            if (temp < 'a') {
                temp += 26;
            }
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            // 大寫
            temp = str[i] - padding;
            if (temp < 'A') {
                temp += 26;
            }
        } else {
            temp = str[i];
        }
        output << temp;
    }

    // output << "Hello" << endl;

    color.black_on_bright_white(" Encrypted successfully \n");
    input.close();
    output.close();

    system("start decrypt.txt");

    return;
}

int CaesarCipher::init(ifstream* input, ofstream* output) {
    // input.open("encrypt.txt");
    int attempts = 5;
    do {
        cout << "Put your file in encrypt.txt" << endl;
        system("pause");
        input->open("encrypt.txt");
    } while (input->fail() && --attempts);
    // input.fail() 如果檔案開啟失敗，會回傳 1，檔案成功開啟，會回傳 0。
    if (attempts <= 0) {
        return 1;
    }

    output->open("decrypt.txt");
    return 0;
}

void CaesarCipher::close_stream(ifstream* input, ofstream* output) {
    input->close();
    output->close();
    return;
}