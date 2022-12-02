#include <stdio.h>

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

// X = lose = 0pts
// Y = draw = 3pts
// Z = win = 6pts

// A = rock = 1
// B = paper = 2
// C = scissors = 3

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
        if (!data) {
            break;
        }
        strcpy(strat_array, strat.c_str());
        switch (strat_array[2]) {
            case 'X':
                // we lose
                switch (strat_array[0]) {
                    case 'A':
                        // they have rock, i lose w. scissor
                        score += 3;
                        break;
                    case 'B':
                        // they have paper i lose w. rock
                        score += 1;
                        break;
                    case 'C':
                        // they have scissor i lose w. paper
                        score += 2;
                        break;
                }
                break;
            case 'Y':
                // draw
                score += 3;
                switch (strat_array[0]) {
                    case 'A':
                        // they have rock, i choose rock
                        score += 1;
                        break;
                    case 'B':
                        // they have paper i choose paper
                        score += 2;
                        break;
                    case 'C':
                        // they have scissor i choose scissor
                        score += 3;
                        break;
                }
                break;
            case 'Z':
                // we must win
                score += 6;
                switch (strat_array[0]) {
                    case 'A':
                        // they have rock, i win w. paper
                        score += 2;
                        break;
                    case 'B':
                        // they have paper i win w. scissor
                        score += 3;
                        break;
                    case 'C':
                        // they have scissor i win w. rock
                        score += 1;
                        break;
                }
                break;
        }
        for (int i = 0; i < 4; i++) {
            std::cout << strat_array[i];
        }
        std::cout << "\n score: " << score << "\n";
    }
    std::cout << score;
    data.close();

    return 0;
}