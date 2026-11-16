#include "trainer.h"
#include "play.h"


#include <cmath>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int today(){
    return (time(nullptr) + 19800) / 86400;
}

vector <int> puzzlesNear(const vector<Puzzle>& puzzles, double rating) {
    vector<int> near;
    int totalmv = puzzles.size();

    for (int i= 0 ; i < totalmv;i++ ) {
        if (abs(puzzles[i].rating - rating) <= 200)
            near.push_back(i);
    }
    if (near.empty()){
        for (int i= 0 ; i < totalmv;i++ )
                near.push_back(i);
    }
    return near;
}

void afterPuzzle(const Puzzle &p, bool won, Profile &me) {
    updateRating(me, p.rating, won);
    saveProfile(me);

    if (!won)
        me.missed.push_back(p.id);
    ofstream history("history.txt", ios::app);
    history << round(me.rating) << "\n";
}



void dailyPuzzle(const vector<Puzzle>& puzzles, Profile& me) {
    int day = today();
    if (me.last == day)
        cout << "Already completed today's puzzle";
    return;
    vector<int> near = puzzlesNear(puzzles, me.rating);
    int pick = near[day % near.size()];
    const Puzzle& p= puzzles[pick];
    bool won = playpuzzle(p);
    if (me.last == day -1)
        me.streak++;
    else
        me.streak = 1;

    me.last = day;
    afterPuzzle(p, won, me);
    cout << "streak:" << me.streak << "days";
}

void practice(const vector<Puzzle>& puzzles, Profile& me) {
    vector<int> near= puzzlesNear(puzzles, me.rating);
    int pick = near[rand() % near.size()];
    const Puzzle& p= puzzles[pick];
    bool won= playPuzzle(p);
    afterPuzzle(p, won,me);
}


void review(const vector<Puzzle>& puzzles, Profile& me) {
    if (me.missed.empty()) {
        cout << "no Puzzles to review";
            return;
    }
    string id = me.missed[0];

    vector<string> rest;
    int totalmv = me.missed.size();
    for (int i = 1; i < totalmv ; i++)
        rest.push_back(me.missed[i]);
    me.missed = rest;

}

void showStats(const Profile& me){
    cout << "\n Rating:" << round(me.rating) << "\n";

    cout  << "Solved:" << me.solved << "of" << me.played << "puzzles\n";
    cout << "streak: " << me.streak << "days \n";
    cout << "Puzzles to review: " << me.missed.size();
}

void showGraph(){
    ifstream file("history.txt");
    int r;
    while (file >> r){
        int length = (r- 800)/20;
        if (length < 1)
            length = 1;
    cout << r << " " << string(length, '#') << "\n";
    }
}
