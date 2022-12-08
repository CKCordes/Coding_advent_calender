#include <bits/stdc++.h>
#include <stdio.h>

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class File {
   public:
    // size of the file
    int size;
    // name of the file
    string fileName;

    File(int givenSize, string givenName) {
        size = givenSize;
        fileName = givenName;
    }
    // Function for getting the file size
    // int getFileSize(Directory) { return size; }

    // returns the filename
    // string getFileName(Directory) { return fileName; }
};

class Directory {
   public:
    // holds all the directories in the super dir
    vector<Directory*> underDir;

    // the list of files in the given directory
    vector<File> fileVector;

    // name of the given directory
    string dirName;

    // directory size, sum of all file sizes
    int size = 0;

    Directory* parent;

    Directory(string givenName, Directory* givenParent) {
        dirName = givenName;
        parent = givenParent;
    }
    ~Directory() {
        for (int i = 0; i < underDir.size(); i++) {
            free(underDir.at(i));
        }
        free(this);
    }

    void updateSize(int newSize) { size = newSize; }
    // Val is the key or the value that
    // has to be added to the data part
    int dfs_size() {
        int sum = 0;
        for (int i = 0; i < underDir.size(); i++) {
            sum += underDir.at(i)->dfs_size();
        }
        for (int i = 0; i < fileVector.size(); i++) {
            sum += fileVector.at(i).size;
        }
        this->size = sum;
        return sum;
    }

    int part1(int runningSum) {
        if (this->size < 100000) {
            runningSum += this->size;
        }
        for (int i = 0; i < underDir.size(); i++) {
            runningSum = underDir.at(i)->part1(runningSum);
        }

        return runningSum;
    }
    int part2(int smallest, const int deletionSize) {
        if (this->size > deletionSize && this->size < smallest) {
            smallest = this->size;
        }
        for (int i = 0; i < underDir.size(); i++) {
            smallest = underDir.at(i)->part2(smallest, deletionSize);
        }

        return smallest;
    }
};

int currentCommand(string cmd) {
    string temp = cmd;
    if (temp.substr(0, 3) == "dir") {
        return 0;
        // its a directory
    } else if (cmd[0] == '$') {
        // it is a command
        string temp = cmd;
        if (temp.substr(2, 2) == "cd") {
            return 1;
            // change directory
        }

        else if (cmd.substr(2, 2) == "ls") {
            return 2;
            // list
        }
    } else {
        // its size of file
        return 3;
    }
}

Directory* createDirTree() {
    ifstream input;
    input.open("data.txt");
    if (!input.is_open()) {
        printf("Cannot open file");
        return NULL;
    }
    // creating the root of all directories
    Directory* root = new Directory("/", NULL);
    Directory* currDir = root;

    while (true) {
        string cmd;
        getline(input, cmd);
        // det første i alle linjer kan enten være:
        //$ = char
        // dir = string
        // size = int
        if (!input) {
            break;
        }
        // Directory* parent = &root;

        while (currentCommand(cmd) != 2) {
            // when it isnt list, we want to create all the files and dir.
            // in the current directory. fx if it is the first time through,
            // we will create all the files and directories in the root, and
            // then go to next directory

            // finding out what the current command does
            switch (currentCommand(cmd)) {
                case 0: {
                    // there is a directory
                    string dirName = cmd.substr(4, cmd.length());
                    Directory* newDir = new Directory(dirName, currDir);
                    newDir->parent = currDir;

                    currDir->underDir.push_back(newDir);
                    break;
                }
                case 1: {
                    string temp = cmd;
                    // changing directories
                    if (temp.substr(5, cmd.length()).compare("..") == 0) {
                        currDir = currDir->parent;
                        // go back to currDir's, parent
                    } else {
                        // find the directory in currDir
                        string dirName = cmd.substr(5, cmd.length());
                        int indexSameName = 0;

                        for (int i = 0; i < currDir->underDir.size(); i++) {
                            if (dirName.compare(
                                    currDir->underDir.at(i)->dirName) == 0) {
                                indexSameName = i;
                                // de er ens
                            }
                        }
                        currDir = currDir->underDir.at(indexSameName);
                        // change directory to a certain directory in the
                        // parent
                    }
                    break;
                }
                case 3: {
                    // there is a file
                    int namePos = cmd.find(' ') + 1;
                    string currFileName = cmd.substr(namePos, cmd.length());

                    File newFile = File(stoi(cmd), currFileName);
                    currDir->fileVector.push_back(newFile);

                    break;
                }
            }
            std::getline(input, cmd);
            if (!input) {
                break;
            }
        }
    }
    return root;
}

int main() {
    Directory* root = createDirTree();
    root->dfs_size();
    // part 1:
    cout << root->part1(0) << endl;
    // part 2: to find out how much space we at least need to free up, we have
    // to finde out how much space we have left, and then find out how big a
    // directory we need to delete
    int deletionSize = 30000000 - (70000000 - root->size);
    cout << deletionSize << endl;
    cout << root->part2(root->size, deletionSize) << endl;
    return 0;
}