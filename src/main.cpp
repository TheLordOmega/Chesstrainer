#include "board.h"
#include "puzzle.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;


void tryMoves(){
    char game[8][8];
    loadFen(game, "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    while (true) {
        printb(game, true);
        cout << "Move:";
        string mv;
        cin >> mv;
    if (mv== "quit" ||cin.fail()) {
        break;
    };
    if (isMove(mv)){
        Makemv(game,mv);
    } else
        cout << "Not a recognised move";
    };
};


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
    cout<< "Moves:";
    for (const string& m: p.moves)
        cout << " " << m;

    Makemove(board, p.moves[0]);
        cout << "Your opponent played " << p.moves[0] << ".\n";

    bool pWhite = true;
        if (whiteToMove(p.fen)) {
            pWhite = false;
            cout << "You play as  Black";
        } else
            cout << "You play as White";
    printb(board, pWhite);
    tryMoves();
    return 0;
}
in the FEN.
    bool youAreWhite = true;
