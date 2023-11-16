#include <iostream>
#include <fstream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <random> 
#include <ctime>
#include "functions.h"
#include "bridge.h"
using namespace std;

void unimplemented();
void settings();
void shutdown(int typeshutdown, string os);
void oses(string os);
void game(string os, bool newgame, bool reset);
int levelcount = 1;

void boot(string osload) {
    string spacedText;

    clears();
    for (size_t i = 0; i < osload.length(); i++) {
        spacedText += osload[i];
        if (i < osload.length() - 1) {
            spacedText += " ";
        }
    }

    cout << spacedText << "\nLoading..." << endl;
    wait(5);
    oses(osload);
}

void oses(string os) {
    string text, choice;
    if (os == "Progressbar 95" || os == "Progressbar 95+") {
        text = "\033[1;34m\u001b[3m " + os + " \033[0m\u001b[0m";
    }
    int totalWidth = 40, padding = (totalWidth - text.length()) / 2;

    while (true) {
        clears();
        for (int i = 0; i < padding; i++) {
            cout << "-";
        }
        cout << text;
        for (int i = 0; i < padding; i++) {
            cout << "-";
        }

        cout << "\n\nSelect choice:\n1. Play\n2. Settings\n3. Restart\n4. Shutdown\n> ";
        cin >> choice;

        if (choice == "1") {
            clears();
            bool gamesave = checklinefile("save.cpp", "LevelGame95", "game");
            string choice;

            if (gamesave == 1) {
                cout << "Select choice:\n1. Load Game\n2. New Game\n> ";
                cin >> choice;

                if (choice == "1") {
                    game(os, false, false);
                } else if (choice == "2") {
                    game(os, true, false);
                }
            } else if (gamesave == 0) {
                cout << "Select choice:\n1. New Game\n> ";
                cin >> choice;

                if (choice == "1") {
                    game(os, false, true);
                }
            }  
        } else if (choice == "2") {
            settings();
        } else if (choice == "3") {
            shutdown(1, os);
        } else if (choice == "4") {
            shutdown(0, os);
        }
    }
}

void settings() {
    ofstream save("save.cpps", ios_base::app);
    while (true) {
        clears();
        string text = " \u001b[3mSettings\u001b[0m ", choice;
        int totalWidth = 40;
        int padding = (totalWidth - text.length()) / 2;

        for (int i = 0; i < padding; i++) {
            cout << "-";
        }
        cout << text;
        for (int i = 0; i < padding; i++) {
            cout << "-";
        }
    
        cout << "\n\nSelect choice:\n1. ANSI escape terminal warning\n2. Exit\n> ";
        cin >> choice;

        if (choice == "1") {
            clears();
            string choicesetting;
            cout << "Do you want the ANSI escape terminal warning disabled/enabled?" << endl;
            cout << "If you want it to be enabled, input \"y\". Else input \"n\".\n> ";
            cin >> choicesetting;

            if (choicesetting == "y" || choicesetting == "Y") {
                bool filestringexist = checklinefile("save.cpps", "ANSIEscapeWarning", "systems");

                if (filestringexist == 1) {
                    savefile("English", "True", levelcount);
                    save.close();
                    ofstream save2("save.cppts");
                    save2 << "ANSIEscapeWarning: "<< ansiescapeh <<"\nLanguage: " << langh;
                    save2.close();

                    if (remove("save.cpps") == 0) {
                        if (rename("save.cppts", "save.cpps") != 0) {
                            cout << "FILE RENAME ERROR!";
                            cout << "If you see this, report to the devs immediately.";
                            exit(0);
                        }
                    } else {
                        cout << "FILE REMOVAL ERROR!";
                        cout << "If you see this, report to the devs immediately.";
                        exit(0);
                    }
                } else if (filestringexist == 0) {
                    save << "ANSIEscapeWarning: True\n";
                    save.close();
                }
            } else if (choicesetting == "n" || choicesetting == "N") {
                bool filestringexist = checklinefile("save.cpps", "ANSIEscapeWarning", "systems");

                if (filestringexist == 1) {
                    savefile("English", "False", levelcount);
                    save.close();
                    ofstream save2("save.cppts");
                    save2 << "ANSIEscapeWarning: "<< ansiescapeh <<"\nLanguage: " << langh;
                    save2.close();
                    
                    if (remove("save.cpps") == 0) {
                        if (rename("save.cppts", "save.cpps") != 0) {
                            cout << "FILE RENAME ERROR!";
                            cout << "If you see this, report to the devs immediately.";
                            exit(0);
                        }
                    } else {
                        cout << "FILE REMOVAL ERROR!";
                        cout << "If you see this, report to the devs immediately.";
                        exit(0);
                    }
                } else if (filestringexist == 0) {
                    save << "ANSIEscapeWarning: False\n";
                    save.close();
                }
            }
        clears();
        cout << "Please restart the game to take changes.";
        wait(3);
        } else if (choice == "2") {
            oses("Progressbar 95");
        }
    }

}

void unimplemented() {
    cout << "Coming soon.";
    wait(2);
}

void shutdown(int typeshutdown, string os) {
    string spacedText;

    clears();
    for (size_t i = 0; i < os.length(); i++) {
        spacedText += os[i];
        if (i < os.length() - 1) {
            spacedText += " ";
        }
    } 

    if (typeshutdown == 1) {
        clears();
        cout << spacedText << "\nShutting Down..." << endl << endl;
        wait(5);
        systemlist();
    } else if (typeshutdown == 0) {
        clears();
        cout << spacedText << "\nShutting Down..." << endl << endl;
        wait(5);
        cout << "\033[0;33mIt is now safe to close your Command Line Interface.\033[0m";
        wait(5);
        exit(0);
    }
}

void game(string os, bool newgame, bool reset) {
    bool ansiescapevalue = checklinefile("save.cpps", "ANSIEscapeWarning", "gameansivalue");
    string ansiescapevaluestr, choicesegment;
    
    if (ansiescapevalue == 1) {
        ansiescapevaluestr = "True";
    } else if (ansiescapevalue == 0) {
        ansiescapevaluestr = "False";
    }
    
    savefile("English", ansiescapevaluestr, levelcount);
    map <int, string> colorMap = {
        {1, "BLUE"}, {2, "LIGHT BLUE"}, {3, "YELLOW"}, {4, "PINK"},
        {5, "RED"}, {6, "GRAY"}, {7, "GREEN"}, {8, "BLUE"},
        {9, "LIGHT BLUE"}, {10, "YELLOW"}
    };

    int tempcount = 1, lives = 3;
    ofstream save("save.cpps", ios_base::app);
    
    if (newgame == 1 && os == "Progressbar 95") {
        save << "\nLevelGame95: 1";
    } else if (reset == 1) {
        cout << "waht";
    }

    clears();
    cout << "Level " << levelcount << endl;
    int segmentchoice = randint(1,10);
    
    if (colorMap.find(segmentchoice) != colorMap.end()) {
        int barnum = 1;
        map <int, string> bar = {
            {1, "NULL"}, {2, "NULL"}, {3, "NULL"}, {4, "NULL"},
            {5, "NULL"}, {6, "NULL"}, {7, "NULL"}, {8, "NULL"},
            {9, "NULL"}, {10, "NULL"}, {11, "NULL"}, {12, "NULL"},
            {13, "NULL"}, {14, "NULL"}, {15, "NULL"}, {16, "NULL"}, 
            {17, "NULL"}, {18, "NULL"}, {19, "NULL"}, {20, "NULL"},
        };

        while (true) {
            clears();

            if (lives == 0) {
                if (levelcount == 1) {
                    cout << "Level not taken.";
                } else {
                    levelcount--;
                    cout << "Negative Level.";
                    save << "LevelGame95: " << levelcount;
                }

                levelcount--;
                tempcount--;
                save << "LevelGame95: " << levelcount;
                cout << "You lose!";
                lives = 3;
                wait(3);
            }

            if (bar[20] != "NULL") {
                levelcount++;
                tempcount++;
                save << "LevelGame95: " << levelcount;
                cout << "You win!";
                wait(3);
                break;
            }

            srand(time(0));  
            int randomIndex = rand() % colorMap.size();
            auto it = colorMap.begin();
            advance(it, randomIndex); 
            string segchoice = it->second, barstr = "NULL";

            cout << "Level " << levelcount << endl;
            if (segchoice == "BLUE") {
                printbar("\033[34m");
            } else if (segchoice == "LIGHT BLUE") {
                printbar("\033[96m");
            } else if (segchoice == "YELLOW") {
                printbar("\033[93m");
            } else if (segchoice == "PINK") {
                printbar("\033[95m");
            } else if (segchoice == "RED") {
                printbar("\033[91m");
            } else if (segchoice == "GRAY") {
                printbar("\033[90m");
            } else if (segchoice == "GREEN") {
                printbar("\033[92m");
            }

            cout << "\nYou have " << lives << " lives left." << endl;
            cout << "Your bar: IN DEVELOPMENT" << endl;
            cout << "You have N/A% in your progressbar" << endl;
            cout << "To catch, enter 'c'. else press 'e' and 'q' to quit.\n> ";
            cin >> choicesegment;

            if (choicesegment == "c" && segchoice == "GREEN") {
                levelcount++;
                tempcount++;
                save << "LevelGame95: " << levelcount;
                cout << "You win!";
                wait(3);
                break;
            } else if (choicesegment == "c" && segchoice == "RED") {
                lives--;
                while (true) {
                    if (barnum == 0) {
                        break;
                    }

                    bar[barnum] = "NULL";
                    barnum--;
                }
            } else if (choicesegment == "c" && segchoice == "GRAY") {
                continue;
            } else if (choicesegment == "c" && segchoice == "BLUE") {
                bar[barnum] = "BLUE";
                barnum++;
            } else if (choicesegment == "c" && segchoice == "LIGHTBLUE") {
                int bonus = randint(0,1);

                if (bonus == 0) {
                    for (int i = 1; i < 2; i++) {
                        bar[barnum] = "BLUE";
                        barnum++;
                    }
                } else if (bonus == 1) {
                    for (int i = 1; i < 3; i++) {
                        bar[barnum] = "BLUE";
                        barnum++;
                    }
                }
            } else if (choicesegment == "c" && segchoice == "YELLOW") {
                bar[barnum] = "YELLOW";
                barnum++;
            } else if (choicesegment == "c" && segchoice == "PINK") {
                bar[barnum] = "NULL";
            } else if (choicesegment == "q") {
                cout << "Thanks for playing!";
                wait(3);
                break;
            } else if (choicesegment == "e") {
                continue;
            }
        }
    } else {
        cout << "error.";
        exit(0);
    }

    
}