#include <stdio.h>

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
    // opening stack instructions
    std::ifstream stack;
    stack.open("stack.txt");
    std::string currLine;
    int stackAmount = 9;
    // creating the ultimate stack, the bigStacks index equals which stack we
    // have. eg index 0 is the first stack
    std::vector<std::vector<char>> bigStack;
    // making sure file is open
    if (!stack.is_open()) {
        printf("Cannot open file");
        return -1;
    }
    // for all the stacks index ill load in the stack
    for (int i = 0; i < stackAmount; i++) {
        std::getline(stack, currLine);
        std::vector<char> currStack;
        for (int i = 0; i < currLine.length(); i++) {
            currStack.push_back(currLine[i]);
        }
        bigStack.push_back(currStack);
    }
    stack.close();
    // printing all stacks
    for (int i = 0; i < bigStack.size(); i++) {
        for (int j = 0; j < bigStack[i].size(); j++) {
            std::cout << bigStack[i][j];
        }
        std::cout << "\n";
    }

    // retrieving the moves
    std::ifstream moves;
    moves.open("moves.txt");
    if (!moves.is_open()) {
        printf("Cannot open file");
        return -1;
    }
    while (true) {
        std::string currMove;
        getline(moves, currMove);
        if (!moves) {
            break;
        }

        // assigning number of ops, and the other stacks
        int number = stoi(currMove);
        int ogStack, newStack;
        if (currMove[2] == ' ') {
            ogStack = (int)currMove[3] - 48 - 1;
        } else {
            ogStack = (int)currMove[2] - 48 - 1;
        }

        if (currMove[4] == ' ') {
            newStack = (int)currMove[5] - 48 - 1;
        } else {
            newStack = (int)currMove[4] - 48 - 1;
        }
        char temp;

        if (number == 1) {
            temp = bigStack[ogStack].back();
            bigStack[newStack].push_back(temp);
            bigStack[ogStack].pop_back();
        } else {
            char tempArray[number];
            int atPos = bigStack[ogStack].size() - number;
            int i = 0;
            while (atPos != bigStack[ogStack].size()) {
                tempArray[i] = bigStack[ogStack].at(atPos);
                bigStack[ogStack].erase(bigStack[ogStack].begin() + atPos);
                // std::cout << ;
                i++;
            }
            std::cout << "\n";
            // pusher alle crates
            for (int i = 0; i < number; i++) {
                bigStack[newStack].push_back(tempArray[i]);
            }
        }
    }

    std::cout << "\nnew stacks: \n";
    for (int i = 0; i < bigStack.size(); i++) {
        for (int j = 0; j < bigStack[i].size(); j++) {
            std::cout << bigStack[i][j];
        }
        std::cout << "\n";
    }
    moves.close();
    return 0;
}