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
             << "4. Review\n "
             << "5. Rating graph \n"
             << "6. Quit \n";
        int choice = 0;
         cin >> choice;
         if (cin.fail() || choice == 6) {
             cout << "GoodBye!";
             break;
         }
         switch (choice) {
             case 1:
                 dailyPuzzle(puzzles, me);
                 break;
             case 2:
                practice(puzzles, me);
                break;
             case 3:
                showStats(me);
                break;
             case 4:
                 review(puzzles,me);
                 break;
             case 5:
                 showGraph();
                 break;
            default:
                cout << "Select an option";
    }
    }
    }
