#include "play.h"
#include "board.h"

#include <iostream>
#include <string>


using namespace std;


string askMove(){
    while (true){
        cout << "Your move:";
        string answer;
        cin >> answer;
        if (cin.fail())
            return "";
        if (isMove(answer))
            return answer;
    cout << "Type a move like e2e4";
    if (isMove(answer) || answer == "hint")
        return answer
    }
}


bool playPuzzle(const Puzzle& p){
    char board[8][8];
    loadFen(board, p.fen);


    cout << "\n Puzzle" <<p.id << ", rated" << p.rating << "\n";
    makeMove(board, p.moves[0]);
    cout<< "Your opponent played" << p.moves[0] << ".\n";

    bool pWhite = true;
        if (whiteToMove(p.fen)) {
            pWhite = false;
            cout << "You play as  Black";
        } else
            cout << "You play as White";


    int totalmv = p.moves.size();
    for (int i= 1; i < totalmv ; i = i+2) {
        printb(board, pWhite);
        string answer = askMove();

        if (answer == "hint") {
            cout << "Hint : move piece " << p.moves[i].substr(0,2) << ".\n";
            answer = askMove();
        }
        if (answer != p.moves[i]) {
            cout << "wrong move, solution was" << p.moves[i] << ".\n";
            return false;
        } else {
            makeMove(board, p.moves[i+1]);
            cout << "Correct, moved played by opponent is " << p.moves[i+1] << "\n";
        }
        printb(board, pWhite);
        cout << "Solved \n";
        return true;
    }
}
