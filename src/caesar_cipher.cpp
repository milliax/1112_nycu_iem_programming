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
        // cout << dye::black_on_light_green(" Failed Opening Files ") << endl;
        // cout << dye::black_on_bright_white(" Returnning to Lobby ") << endl;
        return;
    }

    string str;
    int padding;

    input >> str;
    input >> padding;

    for (unsigned long long i = 0; i < str.size(); ++i) {
        output << (char)(str[i] + padding);
    }

    // output << "Hello" << endl;

    // cout << dye::black_on_bright_white(" Encrypted successfully ") <<endl;

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