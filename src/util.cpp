#include "util.h"
#include <sstream>

using namespace std;

vector <string>split (const string& s, char sep) {
    vector<string>parts;
    istringstream in(s);
    for (string part; getline(in, part, sep);)
        parts.push_back(part);
    return parts;
}
