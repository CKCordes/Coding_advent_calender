#include <stdio.h>

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

// X, A = rock = 0
// Y, B = paper = 1
// Z, C = scissors = 2

int main() {
    std::ifstream data;
    data.open("data.txt");
    std::string strat;
    char strat_array[4];
    int score = 0;

    if (!data.is_open()) {
        printf("Cannot open file");
        return -1;
    }
    while (true) {
        std::getline(data, strat);
        // hack for not duplicating last line
        if (!data) {
            break;
        }
        strcpy(strat_array, strat.c_str());
        switch (strat_array[2]) {
            case 'X':
                score += 1;
                break;
            case 'Y':
                score += 2;
                break;
            case 'Z':
                score += 3;
                break;
        }
        // Not very smart implemented, however it works
        // if its a draw
        if (strat_array[0] == 'A' && strat_array[2] == 'X' ||
            strat_array[0] == 'B' && strat_array[2] == 'Y' ||
            strat_array[0] == 'C' && strat_array[2] == 'Z') {
            score += 3;
        }

        // If i win
        else if (strat_array[0] == 'C' && strat_array[2] == 'X' ||
                 strat_array[0] == 'B' && strat_array[2] == 'Z' ||
                 strat_array[0] == 'A' && strat_array[2] == 'Y') {
            score += 6;
        }
        // for printing
        /*for (int i = 0; i < 4; i++) {
            std::cout << strat_array[i];
        }*/
        // std::cout << "\n score: " << score << "\n";
    }
    std::cout << score;
    data.close();

    return 0;
}