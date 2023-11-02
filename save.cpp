#include "headers.h"

std::string langh, ansiescapeh;

void savefile(std::string language, std::string ansies) {
    langh = language;
    ansiescapeh = ansies;

    std::ofstream save("save.cppts");
    save << "ANSIEscapeWarning: " << ansiescapeh << "\nLanguage: " << langh;
    save.close();
}