#ifndef rules_h
#define rules_h

#include "board.h"

bool isWhite( char piece);
bool isBlack( char piece);
bool isKnightmv(char piece);
bool isKingmv(char piece);

bool pathClear(char board[8][8], const Move& m);


bool isrookmv(char board[8][8], const Move& m);
bool isbishopmv(char board[8][8], const Move& m);
bool isqueenmv(char board[8][8], const Move& m);


bool canReach(char board[8][8], const Move& m);

bool canMove(char board[8][8], const Move& m, bool white);

bool ispawnmv( char board[8][8], const Move& m);

bool isCheck(char board[8][8], bool white);

bool isLegal(char board[8][8], const string& mv, bool white);

int countlegalmv(char board[8][8], bool white);

bool ismate(char board[8][8], bool white);

#endif
