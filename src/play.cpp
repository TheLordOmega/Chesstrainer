#include "play.h"
#include "board.h"
#include "rules.h"


#include <iostream>
#include <string>

#include <chrono>
#include <cmath>


using namespace std::chrono;
using namespace std;


string askMove(){
    while (true){
        cout << "Your move: ";
        string answer;
        cin >> answer;
        if (cin.fail())
            return "";
        answer = cleanMove(answer);
        if (isMove(answer) || answer == "hint")
            return answer;
        cout << "Type a move like e2e4.\n";

    }
}


bool playPuzzle(const Puzzle& p){
    char board[8][8];
    loadFen(board, p.fen);

    cout << "\nPuzzle " << p.id << ", rated " << p.rating << "\n";
    Makemv(board, p.moves[0]);
    cout << "Your opponent played " << p.moves[0] << ".\n";

    bool pWhite = true;
        if (whiteToMove(p.fen)) {
            pWhite = false;
            cout << "You play as Black.\n";
        } else
            cout << "You play as White.\n";

    auto start = steady_clock::now();



    int totalmv = p.moves.size();
    for (int i= 1; i < totalmv ; i = i+2) {
        printb(board, pWhite, p.moves[i - 1]);
        string answer = askMove();
        while (true) {
            if (answer == "hint")
                cout << "Hint: move the piece on " << p.moves[i].substr(0, 2) << ".\n";
            else if (answer == p.moves[i] || answer.empty())
                break;
            else if (isLegal(board, answer, pWhite))
                break;
            else
                cout << "That move is not legal here. Try again.\n";
            answer = askMove();
        }
            if (answer != p.moves[i]) {
                cout << "Wrong. The answer was " << p.moves[i] << ".\n";
                return false;
            }
            Makemv(board, answer);
            if (isMate(board, !pWhite))
                cout << "Checkmate!\n";
            else if (inCheck(board, !pWhite))
                cout << "Check!\n";
            if (i + 1 < totalmv) {
                Makemv(board, p.moves[i + 1]);
                cout << "Correct. Your opponent played " << p.moves[i + 1] << ".\n";
            }
    }
    printb(board, pWhite, p.moves[totalmv - 1]);
    duration<double> took = steady_clock::now() - start;
    cout << "Solved in " << round(took.count() * 10) / 10 << " seconds\n";
    return true;
}
