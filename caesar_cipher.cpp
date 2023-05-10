#include "caesar_cipher.h"

#include <fstream>
#include <iostream>

using namespace std;

void CaesarCipher::play() {
    cout << "Caesar_cipher start!!" << endl;

    cout << "Opening files" << endl;
    init();

    string str;
    int padding;

    getline(input, str);
    input.ignore();
    input >> padding;

    cout << "Encrypting" << endl;

    for (unsigned long long i = 0; i < str.size(); ++i) {
        output << (char)(str[i] + padding);
    }

    color.print_black_on_bright_white(" Encrypted sucessfully ");
    cout << endl;

    return;
}

void CaesarCipher::init(string input_name, string output_name) {
    string i = "../" + input_name;
    string o = "../" + output_name;

    while (true) {
        input.open(i);
    }
    output.open(o);
    return;
}

void CaesarCipher::init() {
    output.open("encrypt.txt");
    output << " ";
    output.close();

    do {
        cout << "Put your file in encrypt.txt" << endl;
        system("pause");
        input.open("encrypt.txt");
    } while (!input.fail());

    output.open("decrypt.txt");
    return;
}

void CaesarCipher::close_stream() {
    input.close();
    output.close();
    return;
}