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
    int commaIndex = 0, dashIndex = 0;
    std::string currLine, firstInt, secondInt;

    // making sure file is open
    if (!data.is_open()) {
        printf("Cannot open file");
        return -1;
    }
    while (true) {
        std::getline(data, currLine);
        if (!data) {
            break;
        }
        commaIndex = currLine.find(",");
        firstInt = currLine.substr(0, commaIndex);
        secondInt = currLine.substr(commaIndex + 1, currLine.length());
        // first interval, converting to int
        dashIndex = firstInt.find("-");
        int fLowerInt = stoi(firstInt.substr(0, dashIndex));
        int fUpperInt = stoi(firstInt.substr(dashIndex + 1, firstInt.length()));

        // second interval converting to int
        dashIndex = secondInt.find("-");
        int sLowerInt = stoi(secondInt.substr(0, dashIndex));
        int sUpperInt =
            stoi(secondInt.substr(dashIndex + 1, secondInt.length()));

        std::cout << currLine << "\n" << sum << "\n\n";
        // if the first interval contains the second:
        if (fLowerInt <= sLowerInt && fUpperInt >= sLowerInt) {
            sum++;
        } else if (fLowerInt >= sLowerInt && fLowerInt <= sUpperInt) {
            sum++;
        }
    }
    std::cout << sum;
    data.close();
    return 0;
}