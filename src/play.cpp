#include "play.h"
#include "board.h"
#include "rules.h"


#include <algorithm>
#include <iostream>
#include <string>

#include <chrono>
#include <cmath>


using namespace std::chrono;
using namespace std;

auto start = steady_clock::now();

    duration<double> took = steady_clock::now() - start;
    std::cout << "Solved in" << round(took.count() * 10) / 10 << "seconds \n";


string askMove(){
    while (true){
        cout << "Your move: ";
        string answer;
        cin >> answer;
        if (cin.fail())
            return "";
    if (isMove(answer) || answer == "hint")
        return answer;
    cout << "Type a move like e2e4";
    }
}


bool playPuzzle(const Puzzle& p){
    char board[8][8];
    loadFen(board, p.fen);

    cout << "\n Puzzle" << p.id << ", rated" << p.rating << "\n";
    Makemv(board, p.moves[0]);
    cout<< "move played" << p.moves[0] << ".\n";

    bool pWhite = true;
        if (whiteToMove(p.fen)) {
            pWhite = false;
            cout << "You play as  Black \n";
        } else
            cout << "You play as White \n ";


    int totalmv = p.moves.size();
    for (int i= 1; i < totalmv ; i = i+2) {
        printb(board, pWhite);
        string answer = askMove();
        while (true) {
            if (answer == "hint") {
                cout << "Hint : move piece " << p.moves[i].substr(0,2) << ".\n";
                answer = askMove();
            }
            else if (answer != p.moves[i] || answer.empty())
                break;
            else if (canMove(board, parseMove(answer), pWhite))
                break;
            else if (isLegal(board, answer, pWhite))
                break;
            if (ismate(board, !pWhite))
                cout << "Checkmate\n";
            else if (isCheck(board, !pWhite))
                cout << "Check!\n";
            else
             cout << "that move is not legal, try again \n";
            answer = askMove();

        }

        Makemv(board, answer);
        if (isCheck(board, !pWhite))
            cout << "check! \n";
        if (i +1< totalmv){
            Makemv(board, p.moves[i+1]);
            cout << "Correct, moved played by opponent is " << p.moves[i+1] << "\n";
        }
        }
        printb(board, pWhite);
        cout << "Solved \n";
        return true;

}
