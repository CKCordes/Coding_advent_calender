#include <stdio.h>

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// function for printing the tree grid.
void printGrid(vector<vector<int>> treeGrid) {
    for (int i = 0; i < treeGrid.size(); i++) {
        for (int j = 0; j < treeGrid[i].size(); j++) {
            cout << treeGrid[i][j];
        }
        cout << endl;
    }
    cout << "\n\n";
}

int main() {
    // creating a vector for the tree grid
    vector<vector<int>> treeGrid;
    int numVisibleTrees = 0;
    ifstream data;
    data.open("data.txt");
    if (!data.is_open()) {
        printf("Cannot open file");
        return -1;
    }
    // loading in the tree grid
    while (true) {
        if (!data) {
            break;
        }
        string stringTree;
        getline(data, stringTree);
        vector<int> rowOfTrees;
        for (int i = 0; i < stringTree.length(); i++) {
            int oneTree = stringTree[i] - '0';
            rowOfTrees.push_back(oneTree);
        }
        treeGrid.push_back(rowOfTrees);
    }
    // printing the tree grid
    printGrid(treeGrid);
    cout << treeGrid[2][2];
    for (int i = 0; i < treeGrid.size(); i++) {
        for (int j = 0; j < treeGrid[i].size(); j++) {
            // checking if visible from the sides
            bool givenVisibleLeft = true;
            for (int k = 0; k != j; k++) {
                if (treeGrid[i][j] <= treeGrid[i][k]) {
                    givenVisibleLeft = false;
                    // break;
                }
            }
            // treeGrid[i].size() - 1
            bool givenVisibleRight = true;
            for (int k = j + 1; k != treeGrid[i].size(); k++) {
                if (treeGrid[i][j] <= treeGrid[i][k]) {
                    givenVisibleRight = false;

                    // break;
                }
            }

            // checking if visible from top or bottom
            bool givenVisibleTop = true;
            for (int k = 0; k < i; k++) {
                if (treeGrid[i][j] <= treeGrid[k][j]) {
                    givenVisibleTop = false;
                    // break;
                }
            }
            bool givenVisibleBottom = true;
            for (int k = i + 1; k < treeGrid.size() - 1; k++) {
                if (treeGrid[i][j] <= treeGrid[k][j]) {
                    givenVisibleBottom = false;
                    // break;
                }
            }

            if (givenVisibleRight || givenVisibleLeft || givenVisibleBottom ||
                givenVisibleTop || (j == 0) || (i == 0) ||
                (j == treeGrid[i].size() - 1) || (i == treeGrid.size() - 2)) {
                cout << "true ";
                numVisibleTrees++;
                continue;
            } else {
                cout << "false ";
            }
            /*
            // looking if we are visible, left, right, up, down:
            else if (treeGrid[i][j] > treeGrid[i][j - 1] ||
                     treeGrid[i][j] > treeGrid[i][j + 1] ||
                     treeGrid[i][j] > treeGrid[i - 1][j] ||
                     treeGrid[i][j] > treeGrid[i + 1][j]) {
                cout << "true ";
                numVisibleTrees++;
            }
            else {
                cout << "false ";
            }
            */
        }
        cout << "\n";
    }
    cout << numVisibleTrees;
    // printGrid(visibilityGrid);

    return 0;
}