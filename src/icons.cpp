#include <iostream>
#include <string>


using namespace std;

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


string squareText(char piece, bool light) {
    string background = "";
    if (light)
        background = "";
    string colour = "";
    if (isupper(piece))
        colour = "";
    string reset = "";
    return background + colour + " " + pieceIcon(piece)+ " " + reset;
}
