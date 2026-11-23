#include "trainer.h"
#include "play.h"
#include "profile.h"
#include "puzzle.h"


#include <cmath>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <map>


using namespace std;

int today(){
    return (time(nullptr) + 19800) / 86400;
}

vector<int> puzzlesNear(const vector<Puzzle>& puzzles, double rating, const string& theme) {
    vector<int> near;
    int totalmv = puzzles.size();

    for (int i= 0 ; i < totalmv;i++ ) {
        if (abs(puzzles[i].rating - rating) <= 200 && hasTheme(puzzles[i], theme))
            near.push_back(i);
    }
    if (near.empty()){
        for (int i= 0 ; i < totalmv;i++ )
            if (hasTheme(puzzles[i], theme))
                near.push_back(i);
    }
    return near;
}

void afterPuzzle(const Puzzle &p, bool won, Profile &me) {
    updateRating(me, p.rating, won);

    if (!won)
        me.missed.push_back(p.id);
    saveProfile(me);
    ofstream history("history.txt", ios::app);
    history << round(me.rating) << "\n";
}



void dailyPuzzle(const vector<Puzzle>& puzzles, Profile& me) {
    int day = today();
    if (me.last == day){
        cout << "You already did today's puzzle.\n";
    return;
    }
    vector<int> near = puzzlesNear(puzzles, me.rating, "");
    int pick = near[day % near.size()];
    const Puzzle& p= puzzles[pick];
    bool won = playPuzzle(p);
    if (me.last == day -1)
        me.streak++;
    else
        me.streak = 1;

    me.last = day;
    afterPuzzle(p, won, me);
    cout << "Streak: " << me.streak << " days\n";
}

void practice(const vector<Puzzle>& puzzles, Profile& me, const string& theme) {
    vector<int> near = puzzlesNear(puzzles, me.rating, theme);
    int pick = near[rand() % near.size()];
    const Puzzle& p= puzzles[pick];
    bool won= playPuzzle(p);
    afterPuzzle(p, won,me);
}

void practiceTheme(const vector<Puzzle>& puzzles, Profile& me) {
    cout << "Which theme? ";
    string theme;
    cin >> theme;
    if (themeCounts(puzzles).count(theme) == 0) {
        cout << "No puzzles with the theme " << theme << ".\n";
        return;
    }
    practice(puzzles, me, theme);
}

void review(const vector<Puzzle>& puzzles, Profile& me) {
    if (me.missed.empty()) {
        cout << "No puzzles to review.\n";
            return;
    }
    string id = me.missed[0];

    vector<string> rest;
    int totalmv = me.missed.size();
    for (int i = 1; i < totalmv ; i++)
        rest.push_back(me.missed[i]);
    me.missed = rest;
    for (const Puzzle& p: puzzles){
        if(p.id == id){
            if (!playPuzzle(p))
                me.missed.push_back(id);
            break;
        }
    }
    saveProfile(me);
}

void showStats(const Profile& me){
    cout << "\nRating: " << round(me.rating) << "\n";

    cout << "Solved: " << me.solved << " of " << me.played << " puzzles\n";
    cout << "Streak: " << me.streak << " days\n";
    cout << "Puzzles to review: " << me.missed.size() << "\n";
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

map<string, int> themeCounts(const vector<Puzzle>& puzzles) {
    map<string, int>counts;
    for (const Puzzle& p:puzzles) {
        for (const string& theme: p.themes)
        counts[theme]++;
    }
    return counts;
}


void streakMode(const vector<Puzzle>& puzzles) {
    cout << "Streak mode: the more you get right in a row, the harder the puzzles get.\n";
    double rating = 800;
    int streak = 0;
    while (true) {
        vector<int> near = puzzlesNear(puzzles, rating, "");
        const Puzzle& p = puzzles[near[rand() % near.size()]];
        if (!playPuzzle(p))
            break;
        streak = streak + 1;
        rating = rating + 100;
    }
    cout << "Streak: " << streak << "\n";
}
