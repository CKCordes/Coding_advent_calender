#include <stdio.h>

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void) {
    ifstream data;
    data.open("data.txt");
    if (!data.is_open()) {
        printf("Cannot open file");
        return -1;
    }
    int index;
    string input;
    getline(data, input);
    int compare;
    for (int i = 0; i < input.length() - 13; i++) {
        // cout << input;
        string currFour = input.substr(i, 14);
        cout << "currFour: " << currFour << "\n";
        bool same = false;
        for (int j = 0; j < 14; j++) {
            for (int k = j + 1; k < 14; k++) {
                if (currFour[j] == currFour[k]) {
                    // der er en gentagelse
                    same = true;
                }
            }
        }

        if (!same) {
            cout << i + 14;
            break;
        }
    }
    return 0;
}