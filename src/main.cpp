#include "puzzle.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
    cout << "Chess Puzzle Trainer \n";
    vector<Puzzle> puzzles = loadPuzzles("puzzles.csv");
    cout<< "loaded" << puzzles.size() << "puzzles \n";

    if (puzzles.empty()) {
        cout << "No puzzles found!";
        return 1;
    }

    const Puzzle& p= puzzles[0];
    cout << "first puzzle:" << p.id << "rated:" << p.rating << '\n';
    cout << "Moves:";

    for (const string& m : p.moves)
        cout << " " << m;
    return 0;
}
