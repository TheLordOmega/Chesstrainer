#include "puzzle.h"
#include "util.h"


#include <fstream>
#include <string>
#include <vector>
#include <iostream>


using namespace std;

vector<Puzzle>loadPuzzles(const string& file) {
    vector<Puzzle> puzzles;
    ifstream inf{file};
    string line{};
    getline(inf, line);              // read the header line and throw it away
    while (getline(inf,line)) {
        vector<string> f=split(line, ',');
        if (f.size()< 8)
            continue;
        Puzzle one {};
        one.id = f[0];
        one.fen = f[1];
        one.moves = split(f[2], ' ');
        try {
        one.rating = stoi(f[3]);
        } catch (...) {
            continue;
        }
        one.themes =split(f[7], ' ');
        puzzles.push_back(one);
    }
    return puzzles;
}

bool hasTheme(const Puzzle& p, const string& theme) {
    if (theme.empty())
        return true;
    for (const string& t: p.themes) {
        if (t == theme)
            return true;
    }
    return false;
}
