//
// Created by Екатерина on 21/12/2019.
//
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

float Divide (float n, float m) {
 if ((n == 0) || (m == 0)) {
     throw std::invalid_argument( "Can't devide by zero" );
 }
 return n/m;
}

bool readFile(ifstream &file, float f[2]) {
    int i = 0;
    int n;
    int m;
    std::string number;

    file.open("../file.txt"); // file is open

    if (!file) {
        throw std::domain_error( "File is not open" );
    }

    while (!file.eof() ) {
        file >> number;
        if (i == 0) {
            f[0] = stoi(number);
        } else {
            f[1] = stoi(number);
        }
        ++i;
    }

    if (i < 2) {
        throw std::runtime_error ( "Not enough numbers" );
    }
}