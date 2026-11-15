#ifndef trainer_h
#define trainer_h

#include "profile.h"
#include "puzzle.h"

#include <vector>
using namespace std;

int today();

vector<int> puzzlesNear(const vector<Puzzle>& puzzles, double rating);

void dailyPuzzle(const vector<Puzzle>& puzzles, Profile& me);


#endif
