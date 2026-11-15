#include "play.h"
#include "board.h"

#include <iostream>
#include <string>


using namespace std;


string askMove(){
    while (true){
        cout << "Your move:";
        string answer;
        cin >> answer;
        if (cin.fail())
            return "";
        if (isMove(answer))
            return answer;
    cout << "Type a move like e2e4";
    }
}
