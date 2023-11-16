#include <fstream>
#include "functions.h"
#include "bridge.h"

std::string langh, ansiescapeh;
int levelgame95h;

void savefile(std::string language, std::string ansies, int levelgame95) {
    langh = language;
    ansiescapeh = ansies;
    levelgame95h = levelgame95;

    std::ofstream save("save.cppts");
    save << "Language: " << langh << "\nANSIEscapeWarning: " << ansiescapeh << "\nLevelGame95: " << levelgame95h;
    save.close();
}