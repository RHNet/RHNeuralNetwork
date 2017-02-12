#include "Utils.h"
#include <iostream>
#include <stdlib.h> // rand
#include <limits>

double Utils::random() {
    return rand()/(((double)RAND_MAX) + 1);
}

int Utils::randomInt(int min, int max) {
    return min +  (int)(Utils::random() * (max - min));
}

int Utils::getInt() {
    int i;
    bool ok = false;
    do {
        std::cin >> i;
        if (std::cin.fail()) {
            std::cout << "Please enter an integer: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.sync();
        } else {
            ok = true;
        }
    } while (!ok);

    return i;
}