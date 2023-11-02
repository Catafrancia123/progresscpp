#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include <cstdio>
#include "headers.h"
using namespace std;

void unimplemented();
void settings();
void shutdown(int typeshutdown, string os);
void oses(string os);
static bool checklinefile(string file, string textsearch);

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
    this_thread::sleep_for(chrono::seconds(5));
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
            unimplemented();
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
                    savefile("English", "True");
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
                    savefile("English", "False");
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
        this_thread::sleep_for(chrono::seconds(3));
        } else if (choice == "2") {
            oses("Progressbar 95");
        }
    }

}

void unimplemented() {
    cout << "Coming soon.";
    this_thread::sleep_for(chrono::seconds(2));
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
        this_thread::sleep_for(chrono::seconds(5));
        systemlist();
    } else if (typeshutdown == 0) {
        clears();
        cout << spacedText << "\nShutting Down..." << endl << endl;
        this_thread::sleep_for(chrono::seconds(5));
        cout << "\033[0;33mIt is now safe to close your Command Line Interface.\033[0m";
        this_thread::sleep_for(chrono::seconds(2));
        exit(0);
    }
}