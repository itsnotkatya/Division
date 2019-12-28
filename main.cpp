#include <iostream>
#include <fstream>
#include <stdexcept>
#include <stdlib.h>
#include "lib.h"
using namespace std;

int main() {
    ifstream file("../file.txt");  //making an object of class ifsteam
    float f[2];
    try {
        readFile(file,f);
        cout << f[0] << endl;
        cout << f[1] << endl;
        cout << Divide(f[0], f[1]) << endl;
    }
    catch (invalid_argument) {
       cout << "Can't devide by zero";
    }
    catch (domain_error) {
        cout << "File doesn't exist";
    }
    catch (runtime_error) {
       cout << "Not enough arguments";
    }
    return 0;
}