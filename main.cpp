#include <iostream>
#include <fstream>
#include "headers.h"
using namespace std;

void systemchoice(string name = "null");
void lang();
bool exists (const std::string& name);

// version and build date (do not touch!)
string ver = "0.1.2", build = "25-10-2023";

int main() {
    bool existed = exists("save.cpps");

    if (existed == 1) {
        cout << "Save file exists.";
    } else if (existed == 0) {
        ofstream ("save.cpps");
        lang();
    } 

    clears();
    string null;
    cout << "Its recommended to play the game in a terminal that supports ANSI escape codes for the best experience." << endl;
    cout << "Press any key to continue..." << endl;
    getline(cin, null);
    systemlist();
}

void systemlist() {
    while (true) {
        clears();
        
        string choicesystem;

        cout << "ProgressComputer BIOS.19.87 - \033[33mStarBright (un)activated\033[0m\nCLI ver. " << ver << " - compiled " << build << "\n\033[31mGAME UNDER DEVELOPMENT // EXPECT BUGS\033[0m\n\n";
        cout << "Select System:\n1. Progressbar 95\n> ";
        cin >> choicesystem;

        if (choicesystem == "1") {
            systemchoice("PB95");
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
            save << "Language: English\n";
            save.close(); 
            break;
        }
    }
    main();
}


void systemchoice(string name) {
    if (name == "PB95") {
        boot("Progressbar 95");
    }
    return;
}