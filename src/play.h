#ifndef play_h
#define play_h

#include "puzzle.h"
#include <string>


using namespace std;

string askMove();

bool playPuzzle(const Puzzle& p);
#endif
