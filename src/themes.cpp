#include <map>
#include <string>
#include <iostream>

using namespace std;

map<string, int>themes = {{"light", 33},
    {"dark", 44}, {"amoled", 355}};

 int main() {
     cout << "light mode" << themes.at("light") << "\n";
     themes.at("light") = 32;

     themes.insert({"other themes", 33});
     themes.clear();
     themes.size();

 }
