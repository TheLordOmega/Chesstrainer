#ifndef board_h
#define board_h

#include <string>
using namespace std;


void loadFen(char board[8][8], const string& fen);

bool whiteToMove(const string& fen);

void printb(char board[8][8], bool whiteView);

void Makemv(char board[8][8], const string& mv);
bool isMove(const string& text);

#endif
