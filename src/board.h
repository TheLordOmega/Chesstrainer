#ifndef board_h
#define board_h

#include <string>
using namespace std;


void loadFen(char board[8][8], const string& fen);

bool whiteToMove(const string& fen);

void printb(char board[8][8], bool whiteView);

struct Move {
    int fromRow= 0 ;
    int fromCol= 0;
    int toRow = 0;
    int toCol = 0;
    char promotion = ' ';
};


Move parseMove(const string& mv);
void Makemv(char board[8][8], const string& mv);
bool isMove(const string& text);


void copyBoard(char from[8][8], char to[8][8]);

string cleanMove(const string& text);
#endif
