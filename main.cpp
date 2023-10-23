#include <iostream>
#include <string>
#include "headers.h"
using namespace std;

void systemchoice(string name = "null");

int main() {
    clears();
    string null;
    cout << "Its recommended to play the game in a True Color terminal for the best experience." << endl;
    cout << "Press any key to continue..." << endl;
    getline(cin, null);

    clears();
    // version and build date (do not touch!)
    string ver = "0.1", build = "23-10-2023", choicesystem;

    cout << "ProgressComputer BIOS.19.87 - \033[33mStarBright (un)activated\033[0m\nCLI ver. " << ver << " - compiled " << build << "\n\033[31mGAME UNDER DEVELOPMENT // EXPECT BUGS\033[0m\n\n";
    cout << "Select System:\n1. Progressbar 95\n> ";
    cin >> choicesystem;

    if (choicesystem == "1") {
        systemchoice("PB95");
    }

    return 0;
}

void systemchoice(string name) {
    if (name == "PB95") {
        progressbar95();
    }
    return;
}