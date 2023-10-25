#include <iostream>
#include <chrono>
#include <thread>
#include "headers.h"
using namespace std;

void unimplemented();
void settings();
void shutdown(int typeshutdown);
void oses(string os);

void boot(string osload) {
    string spacedText;

    clears();
    for (size_t i = 0; i < osload.length(); i++) {
        spacedText += osload[i];
        if (i < osload.length() - 1) {
            spacedText += " ";
        }
    }

    cout << spacedText << "\nLoading...";
    this_thread::sleep_for(chrono::seconds(5));
    oses(osload);
}

void oses(string os) {
    string text = "\033[1;34m\u001b[3m " + os + " \033[0m\u001b[0m", choice;
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
            shutdown(1);
        } else if (choice == "4") {
            shutdown(0);
        }
    }
}

void settings() {
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
            unimplemented();
        } else if (choice == "2") {
            oses("Progressbar 95");
        }
    }

}

void unimplemented() {
    cout << "Coming soon.";
    this_thread::sleep_for(chrono::seconds(2));
}

void shutdown(int typeshutdown) {
    if (typeshutdown == 1) {
        clears();
        cout << "P r o g r e s s b a r  9 5\nShutting Down..." << endl;
        this_thread::sleep_for(chrono::seconds(5));
        systemlist();
    } else if (typeshutdown == 0) {
        clears();
        cout << "P r o g r e s s b a r  9 5\nShutting Down...\n\n";
        this_thread::sleep_for(chrono::seconds(5));
        cout << "\033[0;33mIt is now safe to close your Command Line Interface.\033[0m";
        this_thread::sleep_for(chrono::seconds(2));
        exit(0);
    }
}