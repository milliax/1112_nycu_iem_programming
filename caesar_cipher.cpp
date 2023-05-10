#include "caesar_cipher.h"

#include <stdio.h>

#include <fstream>
#include <iostream>
using namespace std;

void CaesarCipher::play() {
    cout << "Caesar_cipher start!!" << endl;

    fstream input;
    fstream output;

    cout << "Opening file" << endl;
    if (init(&input, &output)) {
        color.print_black_on_light_green(" Failed Openning files \n");
        color.print_black_on_bright_white(" Returnning to Lobby \n");
        return;
    }

    string str;
    int padding;

    input >> str;
    // getline(input, str);
    // input.ignore();
    input >> padding;

    for (unsigned long long i = 0; i < str.size(); ++i) {
        output << (char)(str[i] + padding);
    }

    output << endl;

    color.print_black_on_bright_white(" Encrypted sucessfully ");
    cout << endl;

    return;
}

int CaesarCipher::init(fstream* input, fstream* output) {
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

    output->open("decrypt.txt", fstream::trunc);
    return 0;
}

void CaesarCipher::close_stream(fstream* input, fstream* output) {
    input->close();
    output->close();
    return;
}