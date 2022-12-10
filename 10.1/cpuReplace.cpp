#include <stdio.h>

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ifstream data;
    data.open("data.txt");
    if (!data.is_open()) {
        printf("Cannot open file");
        return -1;
    }

    string operation;
    // for keeping track of which cycle
    int cycle = 0;
    // initial value
    int registerValX = 1;

    int signalStrengthSum = 0;

    while (true) {
        getline(data, operation);

        cycle++;
        if (cycle == 20 || cycle == 60 || cycle == 100 || cycle == 140 ||
            cycle == 180 || cycle == 220) {
            int signalStrength = cycle * registerValX;
            signalStrengthSum += signalStrength;
            cout << "cycle: " << cycle << " registerValX: " << registerValX
                 << " signalstrength: " << signalStrength << "\n";
        }
        if (!data) {
            break;
        }

        switch (operation[0]) {
            case 'n': {
                // if noop
                break;
            }
            case 'a': {
                // if add to register.
                cycle++;
                string temp = operation;
                string strVal = temp.substr(4, temp.length());
                registerValX += stoi(strVal);
                break;
            }
        }
        if (operation[0] == 'n') {
            continue;
        }
        if (cycle == 20 || cycle == 60 || cycle == 100 || cycle == 140 ||
            cycle == 180 || cycle == 220) {
            string strVal = operation.substr(5, operation.length());

            int intVal = stoi(operation.substr(4, operation.length()));

            int signalStrength = cycle * (registerValX - intVal);

            signalStrengthSum += signalStrength;
            cout << "cycle: " << cycle << " registerValX: " << registerValX - 1
                 << " signalstrength: " << signalStrength << "\n";
        }
    }

    cout << signalStrengthSum;
    return 0;
}