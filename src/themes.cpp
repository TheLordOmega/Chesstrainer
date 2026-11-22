#include <map>
#include <string>
#include <iostream>

using namespace std;

map<string, int>themes = {{"knight", 33},
    {"checks", 44}, {"sacrifice", 355}};

 int main() {
     cout << "light mode" << themes.at("light") << "\n";
     themes.at("light") = 32;

     themes.insert({"other themes", 33});
     themes.clear();
     themes.size();

 }
