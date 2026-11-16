#ifndef profile_h
#define profile_h

#include <string>
#include <type_traits>
#include <vector>
using namespace std;


struct Profile{
    double rating = 1200;
    int played= 0;
    int solved= 0;
    int last = 0;
    int streak = 0;

    vector<string> missed;
};

void updateRating(Profile& me, int puzzleRating, bool won);
void saveProfile(const Profile& me);
void loadProfile(Profile& me);

#endif
