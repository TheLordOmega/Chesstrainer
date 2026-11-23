#ifndef rules_h
#define rules_h

#include "board.h"

bool isWhite( char piece);
bool isBlack( char piece);
bool isKnightmv(const Move& m);
bool isKingmv(const Move& m);

bool pathClear(char board[8][8], const Move& m);


bool isrookmv(char board[8][8], const Move& m);
bool isbishopmv(char board[8][8], const Move& m);
bool isqueenmv(char board[8][8], const Move& m);


bool canReach(char board[8][8], const Move& m);

bool canMove(char board[8][8], const Move& m, bool white);

bool isPawnmv( char board[8][8], const Move& m);

bool inCheck(char board[8][8], bool white);

bool isLegal(char board[8][8], const string& mv, bool white);

int countLegalMoves(char board[8][8], bool white);

bool isMate(char board[8][8], bool white);

#endif
