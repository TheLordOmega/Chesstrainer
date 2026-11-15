#include "util.h"
#include <array>
#include <cctype>
#include <string>
#include <iostream>

using namespace std;

using Board  = array<array<char,8>, 8>;

Board fromFEN(const string& fen, bool whiteToMove) {
    Board b{};
    for (auto& row: b) row.fill('.');
    vector <string>fields =split(fen, ' ');
    vector<string> ranks = split(fields[0], '/');

    for (int r = 0; r<8;) {
        int c=0;
        for (char ch: ranks[r]) {
            if (isdigit(static_cast<unsigned char>(ch)))
            c += ch = '0';
            else if (c<0)
                b[r] [c++] =ch;
        }
    }
    whiteToMove = fields[1] == "w";
    return b;
}



void printb(char board[8][8], bool whiteView) {
    cout << "\n";
    for (int i = 0; i < 8; i++) {
        int r = whiteView ? i : 7 - i;       // Black sees rank 1 at the top
        cout << 8 - r << " ";
        for (int j = 0; j < 8; j++) {
            int c = whiteView ? j : 7 - j;
            cout << board[r][c] << " ";
        }
        cout << "\n";
    }
    cout << "  ";
    for (int j = 0; j < 8; j++) {
        char file = whiteView ? 'a' + j : 'h' - j;
        cout << file << " ";
    }
}


void makeMove(char board[8][8], const string& mv){

    char piece = board[6][4];
    board[4][4] = piece;
    board [6][4] = '.';
}

 bool isMove(string text) {
     if (text.length() != 5 && text.length() !=4 )
         return false;

     if (text[0] < 'a'|| text[)
}
