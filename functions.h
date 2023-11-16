#pragma once
#include <string>

void clears();
bool checklinefile(std::string file, std::string textsearch, std::string mode);
void savefile(std::string language, std::string ansies, int levelgame95 = 0);
int randint(int n1, int n2);
void wait(int time);
void printbar(std::string color);
std::string randchoice(std::string valuevar1, std::string valuevar2);

extern std::string langh;
extern std::string ansiescapeh;
extern int levelgame95h;