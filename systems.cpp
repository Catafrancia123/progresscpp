#include <iostream>
#include <unistd.h>
#include "headers.h"
using namespace std;

void settings();
void restart();
int shutdown();

void progressbar95() {
    string text = " \033[1;34mProgressbar 95\033[0m ";
    int totalWidth = 30;
    int padding = (totalWidth - text.length()) / 2;

    clears();
    cout << "P r o g r e s s b a r  9 5\nLoading..." << endl;
    sleep(5);
    clears();
    for (int i = 0; i < padding; i++) {
        cout << "-";
    }
    cout << text;
    for (int i = 0; i < padding; i++) {
        cout << "-";
    }

    string choice;
    cout << "\n\nSelect choice:\n1. Play\n2. Settings\n3. Restart\n4. Shutdown\n> ";
    cin >> choice;

    if (choice == "1") {
        settings();
    } else if (choice == "2") {
        settings();
    } else if (choice == "3") {
        restart();
    } else if (choice == "4") {
        shutdown();
    }
}

void restart() {
    clears();
    cout << "P r o g r e s s b a r  9 5\nShutting Down..." << endl;
    sleep(5);
    main();
}

int shutdown() {
    clears();
    cout << "P r o g r e s s b a r  9 5\nShutting Down..." << endl;
    sleep(5);
    return 0;
}

void settings() {
    cout << "Coming soon.";
}