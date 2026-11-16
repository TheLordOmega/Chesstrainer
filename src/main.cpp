#include "trainer.h"
#include "puzzle.h"
#include "profile.h"

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
    srand(time(nullptr));
    cout << "Chess Puzzle Trainer \n";
    vector<Puzzle> puzzles = loadPuzzles("puzzles.csv");
    cout<< "loaded" << puzzles.size() << "puzzles \n";

    if (puzzles.empty()) {
        cout << "No puzzles found!";
        return 1;
    }
    Profile me;
    loadProfile(me);
    cout << "Your rating: " << round(me.rating) << ".\n";
    cout << "type hint to see which piece to move. \n";
    while (true) {
        cout << "\n"
             << "1. Daily puzzle \n"
             << "2. Practice \n"
             << "3. My stats \n"
             << "4. Rating graph \n"
             << "5. Quit \n"
             << " Choose: ";
        int choice = 0;
         cin >> choice;
         if (cin.fail() || choice == 5) {
             cout << "GoodBye!";
             break;
         }
        if (choice == 1)
            dailyPuzzle(puzzles, me);
        else if (choice ==2)
            practice(puzzles, me);
        else if  (choice == 3)
            showStats(me);
        else if (choice == 4)
            showGraph();
        }
        return 0;
    }
