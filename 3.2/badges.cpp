#include <stdio.h>

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

int main() {
    // opening data file
    std::ifstream data;
    data.open("data.txt");
    int sum = 0;
    std::string bag0, bag1, bag2, tempstr;

    // making sure file is open
    if (!data.is_open()) {
        printf("Cannot open file");
        return -1;
    }
    while (true) {
        std::getline(data, bag0);
        std::getline(data, bag1);
        std::getline(data, bag2);
        char common[100];
        memset(&common[0], 0, 100);
        int commonCounter = 0;
        // hack for not duplicating last line
        if (!data) {
            break;
        }
        for (int i = 0; i < bag0.length(); i++) {
            for (int j = 0; j < bag1.length(); j++) {
                if (bag0[i] == bag1[j]) {
                    common[commonCounter] = bag0[i];
                    commonCounter++;
                }
            }
        }
        int smallLetter = 0, largeLetter = 0, temp;
        for (int i = 0; i < bag2.length(); i++) {
            for (int j = 0; j < 100; j++) {
                if (bag2[i] == common[j]) {
                    temp = bag2[i] - 96;
                    if (temp < 0) {
                        largeLetter = bag2[i] - 38;
                        sum += largeLetter;
                        goto afterFor;
                    } else {
                        smallLetter = temp;
                        sum += smallLetter;
                        goto afterFor;
                    };
                }
            }
        }

    afterFor:;
    }
    std::cout << sum;
    data.close();
    return 0;
}