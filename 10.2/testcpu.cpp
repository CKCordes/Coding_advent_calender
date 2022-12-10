#include <stdio.h>

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printScreen(vector<vector<char>> screen) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 40; j++) {
            cout << screen[i][j];
        }
        cout << endl;
    }
}

int main() {
    ifstream data;
    data.open("data.txt");
    if (!data.is_open()) {
        printf("Cannot open file");
        return -1;
    }

    vector<vector<char>> screen;
    ;

    vector<char> CRT;

    string operation;
    // for keeping track of which cycle
    int cycle = 0;
    // initial value
    int registerValX = 1;

    int signalStrengthSum = 0;

    int screenCounter = 0;
    int newI;

    while (true) {
        if (!data) {
            break;
        }

        for (int i = cycle - 40 * screenCounter; i < 40;) {
            getline(data, operation);
            vector<char> spriteRow;

            // setting sprite position
            for (int i = 0; i < 40; i++) {
                if (i == registerValX || i == registerValX + 1 ||
                    i == registerValX - 1) {
                    spriteRow.push_back('#');
                    // insert(spriteRow.begin() + i, '#');
                } else {
                    spriteRow.push_back('.');
                }
            }

            cycle++;
            i++;
            if (spriteRow[i - 1] == '#') {
                CRT.push_back('#');
            } else {
                CRT.push_back(' ');
            }

            switch (operation[0]) {
                case 'n': {
                    break;
                }
                case 'a': {
                    // if add to register.
                    cycle++;
                    i++;
                    string temp = operation;
                    string strVal = temp.substr(4, temp.length());
                    registerValX += stoi(strVal);

                    if (spriteRow[i - 1] == '#') {
                        CRT.push_back(('#'));
                    } else {
                        CRT.push_back(' ');
                    }

                    break;
                }
            }
        }
        screenCounter++;
        screen.push_back(CRT);
        for (int i = 0; i < 40; i++) {
            cout << CRT[i];
        }
        cout << endl;
        CRT.clear();
        if (screenCounter == 6) {
            break;
        }
    }
    // printScreen(screen);
    // FORSKYD PÅ ANDEN OG FEMTE LINJE SÅ VIRKER DET!
    return 0;
}