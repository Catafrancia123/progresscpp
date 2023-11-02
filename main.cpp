#include <iostream>
#include <fstream>
#include "headers.h"
using namespace std;

void systemchoice(string name = "null");
void lang();
bool exists (const std::string& name);
void systemlist();
void ansiescape(string boolean);

// version and build date (do not touch!)
string ver = "0.2", build = "2-11-2023";

int main() {
    clears();
    bool existed = exists("save.cpps");

    if (existed == 1) {
        cout << "Save file exists.";
        checklinefile("save.cpps", "ANSIEscapeWarning", "main");
    } else if (existed == 0) {  
        ofstream ("save.cpps");
        lang();
    } 
}

void ansiescape(string boolean) {
    clears();
    if (boolean == "True") {
        string null;
        cout << "Its recommended to play the game in a terminal that supports ANSI escape codes for the best experience." << endl;
        cout << "Press any key to continue..." << endl;
        getline(cin, null);
        systemlist();
    } else if (boolean == "False") {
        systemlist();
    }
}

void systemlist() {
    while (true) {
        clears();
        string choicesystem;

        cout << "ProgressComputer BIOS.19.87 - \033[33mStarBright (un)activated\033[0m\nCLI ver. " << ver << " - compiled " << build << "\n\033[31mGAME UNDER DEVELOPMENT // EXPECT BUGS\033[0m\n\n";
        cout << "Select System:\n1. Progressbar 95\n2. Progressbar 95+\n> ";
        cin >> choicesystem;

        if (choicesystem == "1") {
            systemchoice("PB95");
        } else if (choicesystem == "2") {
            systemchoice("PB95PLUS");
        }
    }
}


bool exists (const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}

void lang() {
    ofstream save("save.cpps", ios_base::app);
    string lang;

    while (true) {
        clears();
        cout << "Select a language:\n\n";
        cout << "[en] Please select your language by entering the language code to the left." << endl;
        cout << "> ";
        cin >> lang;

        if (lang == "en") {
            save << "Language: English\nANSIEscapeWarning: True\n";
            save.close(); 
            break;
        }
    }
    main();
}


void systemchoice(string name) {
    if (name == "PB95") {
        boot("Progressbar 95");
    } else if (name == "PB95PLUS") {
        boot("Progressbar 95+");
    }
}