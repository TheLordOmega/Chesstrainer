#include "puzzle.h"
#include "util.h"


#include <fstream>
#include <iostream>
#include <string>
#include <vector>



using namespace std;


vector<Puzzle>loadPuzzles(const string& file) {
    vector<Puzzle> puzzles;
    ifstream inf{"puzzles.csv"};
    string line{};
    while (getline(inf,line)) {
        vector<string> f=split(line, ',');
        if (f.size()< 8)
            continue;
        Puzzle one {};
        one.id = f[0];
        one.fen = f[1];
        one.moves = split(f[2], ' ');
        one.rating = stoi(f[3]);
        one.themes =split(f[7], ' ');
        Puzzle push_back(one);
    }
        cout << line <<"\n";
    return puzzles;
};
