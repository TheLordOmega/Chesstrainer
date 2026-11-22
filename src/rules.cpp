#include "rules.h"
#include "board.h"
#include <cstdlib>
#include <cctype>

using namespace std;


bool isWhite(char piece) {
    return piece >= 'A' && piece <= 'Z';
}

bool isBlack(char piece) {
    return piece >= 'a' && piece <= 'z';
}


bool isKnightmv (const Move& m) {
    int rows = abs(m.toRow - m.fromRow);
    int cols = abs(m.toCol - m.fromCol);
    return (rows==2 && cols == 1 || rows == 1 && cols== 2);
}

bool isKingmv (const Move& m) {
    int rows = abs(m.toRow- m.fromRow);
    int cols = abs(m.toCol- m.fromCol);
    return rows <= 1 && cols <= 1 && rows + cols > 0;
}


bool pathClear(char board[8][8], const Move& m) {
    int stepR = 0;
    if (m.toRow > m.fromRow) stepR =1;
    if (m.toRow < m.fromRow) stepR = -1;

    int stepC = 0;
    if (m.toCol> m.fromCol) stepC =1 ;
    if (m.toCol < m.fromCol) stepC = -1;

    int r = m.fromRow + stepR;
    int c= m.fromCol + stepC;
    while (r != m.toRow || c != m.toCol) {
        if (board[r][c] != '.')
            return false;
        r = r+ stepR;
        c = c+ stepC;
    }
    return true;
}



bool isrookmv( char board[8][8], const Move& m) {
    bool straight = m.fromRow == m.toRow || m.fromCol == m.toCol;
    return straight && pathClear(board,m);
}

bool isbishopmv(char board[8][8], const Move& m) {
    bool diagonal = abs(m.fromCol -m.toCol) == abs(m.fromRow- m.toRow);
    return diagonal && pathClear(board,m);
}

bool isqueenmv(char board[8][8], const Move& m) {
    return isrookmv(board,m) || isbishopmv(board, m);
}


bool canReach(char board[8][8], const Move& m) {
    char piece = tolower(board[m.fromRow][m.fromCol]);
    switch (piece) {
        case 'n':
            return isKnightmv(m);
        case 'k':
            return isKingmv(m);
        case 'r':
            return isrookmv(board,m);
        case 'b':
            return isbishopmv(board,m);
        case 'q':
            return isqueenmv(board, m);
        case 'p':
            return ispawnmv(board, m);
        default:
            return false;
    }
}


bool canMove( char board[8][8], const Move& m, bool white) {
    char piece = board[m.fromRow][m.fromCol];
    char target = board [m.toRow] [m.toCol];

    if (piece == '.')
        return false;
    if (isWhite(piece)!= white)
        return false;
    if (target != '.' && isWhite(target) ==white)
        return false;
    return canReach( board, m);
}


bool isPawnmv(char board[8][8], const Move& m) {
    int forward = -1;
    int startRow = 6;

    if (isBlack(board[m.fromRow][m.fromCol])) {
        forward = 1;
        startRow = 1;
    }
    int rows = m.toRow - m.fromRow;
    int cols = abs(m.toCol - m.fromCol);
    char target = board[m.toRow][m.toCol];


    if (cols == 0 && rows == forward && target == '.')
        return true;
    if (cols == 0 && rows ==2 * forward && m.fromRow == startRow
        && target == '.' && board[m.fromRow +forward][m.fromCol] == '.')
        return true;
    if (cols ==1 && rows == forward && target != '.')
        return true;
    return false;
}


bool inCheck(char board[8][8], bool white) {
    char king = 'k';
    if (white)
        king = 'K';
    int kingRow = -1;
    int kingCol = -1;
    for (int r= 0; r < 8 ; r++) {
        for (int c= 0 ; c< 8 ; c++) {
            if (board[r][c] == king) {
                kingRow = r;
                kingCol = c;
            }
        }
    }
    if (kingRow == -1)
        return false;
    for (int r=0; r <8; r++){
        for (int c= 0 ; c <8 ; c++) {
            char piece = board[r][c];
            if (piece == '.'|| isWhite(piece)== white)
                continue;
            Move m;
            m.fromRow = r;
            m.fromCol = c;
            m.toRow = kingRow;
            m.toCol =  kingCol;
                if (canReach(board, m))
            return true;
        }
    }
    return false;
}


void copyBoard(char from[8][8], char to[8][8]) {
    for (int r = 0; r< 8; r++) {
        for (int c=0; c < 8; c++)
            to[r][c] = from[r][c];
    }
}


bool islegal(char board[8][8], const string& mv, bool white) {
    if (!canMove(board, parseMove(mv), white))
        return false;
    char after[8][8];
    copyBoard(board, after);
    Makemv(after , mv);
    return !inCheck(after, white);
}



int coutlegalmv(char board[8][8], bool white) {
    int count = 0;
    for (int fr = 0 ; fr < 8 ; fr++)
        for (int fc = 0; fc < 8; fc++)
            for (int tr = 0; tr < 8 ; tr++)
                for (int tc = 0; tc <8 ; tc++) {
                    string mv = "a1a1";
                    mv[0] = 'a' + fc;
                    mv[1] = '8' -fr;
                    mv[2] = 'a' +tc;
                    mv[3] = '8' - tr;
                    if (islegal(board, mv, white))
                        count = count + 1;
                }
    return count;
}
