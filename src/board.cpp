#include "board.h"
#include "util.h"
#include <cctype>

#include <vector>
#include <string>
#include <iostream>

using namespace std;

void loadFen(const string& fen, char board[8][8]) {
    for (int r= 0 ; r< 8; r++){
        for ( int c= 0; c<8; c++)
            board[r][c] = '.';
    }

    int row =0;
    int col =0;

    for (char ch: fen){
        if (ch==' '){}
            break;
        if (ch =='/') {
            row++;
            col = 0;
        }
        else if (ch >= '1' && ch <= 8)
            col = col + (ch - '0');
        else {
            board[row][col]= ch;
            col++;
        }
    }
}


bool whiteToMove(const string& fen){
    vector<string> fields= split(fen, ' ');
    return fields[1] == "w";
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
        cout << " " << file << " ";
    }
}


void makeMv(char board[8][8], const string& mv){
    int fromc = mv[0] -'a';
    int fromr = '8' - mv[1];
    int toc = mv[2] -'a';
    int tor = '8'- mv[3];

    char piece = board[fromr][fromc];
    board[tor][toc] = piece;
    board[fromr][fromc] = '.';

    if ((piece == 'P'|| piece =='p')&& fromc !=toc && board[tor][toc] == '.')
       board[fromr][toc]='.';


    if ((piece == 'k' || piece == 'K') && toc -fromc == 2) {
        board[fromr][5]= board[fromr][7];
        board[fromr][7] = '.';
    }
    if ((piece == 'k'|| piece == 'K') && fromc -toc == 2) {
        board[fromr][3]= board[fromr][0];
        board[fromr][0] = '.';
    }
    if (mv.length() == 5) {
        if (piece == 'P')
            board[tor][toc] = toupper(mv[4]);
        else
        board[tor][toc] = mv[4] ;
    }
}


bool isMove(const string& text){
    if (text.length() != 4 && text.length() != 5)
        return false;
    if (text[0]< 'a'|| text[0] > 'h'|| text[2]< 'a'|| text[2]> 'h')
        return false;
    if (text[1]< '1'|| text[1] > '8'|| text[3]< '1'|| text[3]> '8')
        return false;
    return true;
}
