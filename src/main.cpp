#include "play.h"
#include "puzzle.h"
#include "profile.h"

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

    Profile me;
    loadProfile(me);
    const Puzzle& p = puzzles[0];
    bool won= playPuzzle(p);
    updateRating(me, p.rating, won);
    saveProfile(me);
}
