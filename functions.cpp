#include <fstream>
#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <stdlib.h>
#include "bridge.h"
using namespace std;

void clears();
int randint(int n1, int n2);
string randchoice(string valuevar1, string valuevar2);
bool checklinefile(string file, string textsearch, string mode);

void clears() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int randint(int n1, int n2) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(n1,n2);

    int random_integer = uni(rng);
    return random_integer;
}

string randchoice(string valuevar1, string valuevar2) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(0,1); 

    return uni(rng) ? valuevar1 : valuevar2;
}

void wait(int time) {
    this_thread::sleep_for(chrono::seconds(time));
}

void printbar(string color) {
    char unicode = 219;
    string colorcode = color, reset = "\033[0m";
    for (int i=0; i<2; ++i) { 
        cout << colorcode << string(3, unicode) << reset << endl;
    }
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
    } else if (mode == "game") {
        clears();
        ifstream fileInput(file);
        if (!fileInput.is_open()) {
            cerr << "Error opening file." << endl;
            exit(0);
        }

        string search = textsearch, line; 
        unsigned int curLine = 0;

        while (getline(fileInput, line)) {
            curLine++; // Increment the line number

            if (line.find(search) != string::npos) {
                cout << "Found: " << search << " at line: " << curLine << endl;
                return true;
            } else {
                return false;
            }
        }
    } else if (mode == "gameansivalue") {
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
                return true;
            } else if (line.find(search2) != string::npos) {
                cout << "Found: " << search2 << " at line: " << curLine << endl;
                return false;
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