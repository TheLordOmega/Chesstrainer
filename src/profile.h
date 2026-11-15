#ifndef profile_h
#define profile_h ;

#include <string>
#include <vector>
using namespace std;


struct Profile{
    double rating = 1200;
    int played= 0;
    int solved= 0;
    int last = 0;
    int streal = 0;

    vector<string> missed;
};

#endif
