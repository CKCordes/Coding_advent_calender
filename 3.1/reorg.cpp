#include <stdio.h>

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

int main() {
    // opening data file
    std::ifstream data;
    data.open("data.txt");
    int bagNum = 0;
    int sum = 0;
    std::string bag;
    std::string firstComp;
    std::string secondComp;

    // making sure file is open
    if (!data.is_open()) {
        printf("Cannot open file");
        return -1;
    }
    while (true) {
        std::getline(data, bag);
        // hack for not duplicating last line
        if (!data) {
            break;
        }

        // splitting into compartments
        firstComp = bag.substr(0, bag.length() / 2);
        secondComp = bag.substr(bag.length() / 2, bag.length());
        int smallLetter = 0, largeLetter = 0, temp;
        for (int i = 0; i < bag.length() / 2; i++) {
            for (int j = bag.length() / 2; j < bag.length(); j++) {
                if (firstComp[i] == bag[j]) {
                    //  figuring out if the char is small or big, if 0>temp - 96
                    //  it must be largeLetter
                    temp = firstComp[i] - 96;
                    if (temp < 0) {
                        largeLetter = firstComp[i] - 38;
                        sum += largeLetter;
                        goto afterFor;
                    } else {
                        smallLetter = temp;
                        sum += smallLetter;
                        goto afterFor;
                    }
                }
            }
        }
    afterFor:;
    }
    std::cout << sum;
    data.close();
    return 0;
}