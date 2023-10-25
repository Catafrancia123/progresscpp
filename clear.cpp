#include <cstdlib>
#include "headers.h"

void clears() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}