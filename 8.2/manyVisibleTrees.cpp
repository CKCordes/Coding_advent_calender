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

int visibilityScore(vector<vector<int>> treeGrid) {
    int maxScore = 0;
    for (int i = 0; i < treeGrid.size(); i++) {
        for (int j = 0; j < treeGrid[i].size(); j++) {
            int currScore = 0;
            // left, right, up, down
            // Adding score for trees to the left
            int visiScoreLeft = 0;
            if (j == 0) {
                visiScoreLeft = 0;
            } else {
                for (int k = j; k != 0; k--) {
                    if (treeGrid[i][j] <= treeGrid[i][k - 1]) {
                        visiScoreLeft++;
                        break;
                    }
                    visiScoreLeft++;
                }
            }

            // Adding score for trees to the right
            int visiScoreRight = 0;
            if (j == treeGrid[i].size() - 2) {
                visiScoreRight = 0;
            } else {
                for (int k = j; k != treeGrid[i].size() - 1; k++) {
                    if (treeGrid[i][j] <= treeGrid[i][k + 1]) {
                        visiScoreRight++;
                        break;
                    }
                    visiScoreRight++;
                }
            }

            // checking if visible from top or bottom
            int visiScoreTop = 0;
            if (i == 0) {
                visiScoreTop = 0;
            } else {
                for (int k = i; k != 0; k--) {
                    if (treeGrid[i][j] <= treeGrid[k - 1][j]) {
                        visiScoreTop++;
                        break;
                    }
                    visiScoreTop++;
                }
            }

            int visiScoreBottom = 0;
            if (i == treeGrid.size() - 2) {
                visiScoreBottom = 1;
            } else {
                for (int k = i; k < treeGrid.size() - 2; k++) {
                    if (treeGrid[i][j] <= treeGrid[k + 1][j]) {
                        visiScoreBottom++;
                        break;
                    }
                    visiScoreBottom++;
                }
            }
            /*cout << visiScoreTop << " " << visiScoreBottom << " "
                 << visiScoreLeft << " " << visiScoreRight;*/

            currScore =
                visiScoreBottom * visiScoreTop * visiScoreLeft * visiScoreRight;
            cout << currScore << " ";
            if (currScore > maxScore) {
                maxScore = currScore;
            }
        }
    }
    return maxScore;
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
    cout << treeGrid.size();
    cout << visibilityScore(treeGrid);

    return 0;
}