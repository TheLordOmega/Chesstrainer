#ifndef Puzzle_h
#define Puzzle_h

#include <string>
#include <vector>
using namespace std;

struct Puzzle
{
    string id{};
    string fen {};
    vector<std::string>moves;
    int rating = 0;
    vector<string> themes{};
};
vector<Puzzle> loadPuzzles(const string& file);

#endif
