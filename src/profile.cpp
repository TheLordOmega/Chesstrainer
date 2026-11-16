#include "profile.h"
#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

void updateRating(Profile& me, int puzzleRating, bool won) {
    double expected = 1.0 / (1.0 + pow(10.0, (puzzleRating - me.rating)/400));
    double result = 0;
    if (won) {
        result = 1;
    }
    double old = me.rating;
    me.rating = me.rating + 32 * (result - expected);
    me.played++;
    if (won)
        me.solved++;
    cout << "Rating:" << round(old) << "->" << round(me.rating) << "\n";
}

void saveProfile(const Profile& me) {
    ofstream file("profile.txt");
    file << me.rating << " " << me.played << " " << me.solved << "\n";

    file << me.last << " " << me.streak << "\n";

    ofstream missedFile("missed.txt");
    for (const string& id: me.missed)
        missedFile << id << "\n";
}

void loadProfile( Profile&  me) {
    ifstream file("profile.txt");
    file >> me.rating >> me.played >> me.solved>> me.last >> me.streak;
    ifstream missedFile("missed.txt");
    string id;
    while (missedFile >> id) {
        me.missed.push_back(id);
    }
}
