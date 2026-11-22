#ifndef trainer_h
#define trainer_h

#include "profile.h"
#include "puzzle.h"

#include <map>
#include <vector>
using namespace std;

int today();

vector<int> puzzlesNear(const vector<Puzzle>& puzzles, double rating);

void dailyPuzzle(const vector<Puzzle>& puzzles, Profile& me);

void afterPuzzle(const Puzzle& p, bool won, Profile& me);
void practice (const vector<Puzzle>& puzzles, Profile& me);

void review(const vector<Puzzle>& puzzles, Profile& me);

void showStats(const Profile& me);
void showGraph();

map<string, int>themeCounts(const vector<Puzzle>& puzzles);

void streakMode(const vector<Puzzle>& puzzles);

#endif
