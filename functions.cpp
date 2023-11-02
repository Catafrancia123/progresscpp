#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "headers.h"
using namespace std;

void clears();
bool checklinefile(string file, string textsearch, string mode);

void clears() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

bool checklinefile(string file, string textsearch, string mode) {
    bool ansiescapes;
    if (mode == "main") {
        clears();
        ifstream fileInput(file);
        if (!fileInput.is_open()) {
            cerr << "Error opening file." << endl;
            exit(0);
        }

        string search = textsearch+": True", search2 = textsearch+": False", line; 
        unsigned int curLine = 0;

        while (getline(fileInput, line)) {
            curLine++; // Increment the line number

            if (line.find(search) != string::npos) {
                cout << "Found: " << search << " at line: " << curLine << endl;
                ansiescapes = true;
            } else if (line.find(search2) != string::npos) {
                cout << "Found: " << search2 << " at line: " << curLine << endl;
                ansiescapes = false;
            }
        }
    } else if (mode == "systems") {
        clears();
        ifstream fileInput(file);
        if (!fileInput.is_open()) {
            cerr << "Error opening file." << endl;
            exit(0);
        }

        string search = textsearch+": True", search2 = textsearch+": False", line; 
        unsigned int curLine = 0;

        while (getline(fileInput, line)) {
            curLine++; // Increment the line number

            if (line.find(search) != string::npos || line.find(search2) != string::npos) {
                cout << "Found: " << (line.find(search) != string::npos ? search : search2) << " at line: " << curLine << endl;
                return true;
            }
        }
    }

    if (ansiescapes == 1) {
        ansiescape("True");
    } else if (ansiescapes == 0) {
        ansiescape("False");
    } else {
        cout << "error";
        exit(0);
    }
}