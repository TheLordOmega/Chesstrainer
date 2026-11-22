#include "board.h"
#include "util.h"
#include <cctype>

#include <vector>
#include <string>
#include <iostream>

using namespace std;

void loadFen(char board[8][8], const string& fen) {
    for (int r= 0 ; r< 8; r++){
        for ( int c= 0; c<8; c++)
            board[r][c] = '.';
    }

    int row =0;
    int col =0;

    for (char ch: fen){
        if (ch==' ')
            break;
        if (ch =='/') {
            row++;
            col = 0;
        }
        else if (ch >= '1' && ch <= '8')
            col = col + (ch - '0');
        else {
            board[row][col]= ch;
            col++;
        }
    }
}


bool whiteToMove(const string& fen){
    vector<string> fields= split(fen, ' ');
    if (fields.size() < 2)
        return true;
    return fields[1] == "w";
}


string pieceIcon (char piece) {
    char p = tolower(piece);
    if (p== 'k')
        return "♚";
    else if (p == 'n')
        return "♞";
    else if (p == 'q')
        return "♛";
    else if (p == 'p')
        return "♟";
    else if (p == 'b')
        return "♝";
    else if (p== 'r')
        return "♜";
    return " ";
}


string squareText(char piece, bool light, bool marked) {
    string background = "\033[48;2;135;95;66m";
    if (light)
        background = "\033[48;2;180;135;99m";
    if (marked && light)
        background = "\033[48;2;205; 210; 105";
    else if (marked)
        background = "\033[48;2;17-;160;58m";
    string colour = "\033[38;2;0;0;0m";
    if (isupper(piece))
        colour = "\033[38;2;255;255;255m";
    string reset = "\033[0m";
    return background + colour + " " + pieceIcon(piece)+ " " + reset;
}


void printb(char board[8][8], bool whiteView, const string& last) {
    bool hasLast = isMove(last);
    Move m;
    if (hasLast)
        m = parseMove(last);
    cout << "\n";
    for (int i = 0; i < 8; i++) {
        int r = i;
        if (!whiteView)
            r = 7 - i;
        cout << 8 - r << " ";
        for (int j = 0; j < 8; j++) {
            int c = j;
            if (!whiteView)
                c = 7 - j;
            bool light = (r + c) % 2 == 0;
            bool isStart = r == m.fromRow && c == m.fromCol;
            bool isEnd = r == m.toRow && c == m.toCol;
            bool marked = hasLast && (isStart || isEnd);
            cout << squareText(board[r][c], light, marked);
        }
        cout << "\n";
    }
    cout << "  ";
    for (int j = 0; j < 8; j++) {
        char file = whiteView ? 'a' + j : 'h' - j;
        cout << " " << file << " ";
    }
}



Move parseMove(const string &mv) {
    Move m;
    m.fromCol = mv[0] -'a';
    m.fromRow = '8'-  mv[1] ;
    m.toCol = mv[2] -'a' ;
    m.toRow  = '8' - mv[3];
    if (mv.length() == 5)
        m.promotion = mv[4];
    return m;
}


void Makemv(char board[8][8], const string& mv){
    int fromc = mv[0] -'a';
    int fromr = '8' - mv[1];
    int toc = mv[2] -'a';
    int tor = '8'- mv[3];

    char piece = board[fromr][fromc];
    if ((piece == 'P'|| piece =='p')&& fromc !=toc && board[tor][toc] == '.')
       board[fromr][toc]='.';

    board[tor][toc] = piece;
    board[fromr][fromc] = '.';


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

bool isFile(char c) {
    return c >= 'a' && c <= 'h';
}
bool isRank(char r){
    return r >= '1' && r <= '8';
}

bool isMove(const string& text){
    if (text.length() != 4 && text.length() != 5)
        return false;
    if (!isFile(text[0]) || !isFile(text[2]))
        return false;
    if (!isRank(text[1]) || !isRank(text[3]))
        return false;
    return true;
}

string cleanMove( const string& text) {
    string clean ="";
    for (char c : text) {
        if (c!= '-')
            clean += tolower(c);
    }
    return clean;
}
