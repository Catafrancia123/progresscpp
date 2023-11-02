#pragma once
#include <string>
#include <fstream>

void clears();
void systemlist();
void boot(std::string osload);
void savefile(std::string language, std::string ansies = "True");
bool checklinefile(std::string file, std::string textsearch, std::string mode);
void ansiescape(std::string boolean = "True");

extern std::string langh;
extern std::string ansiescapeh;
