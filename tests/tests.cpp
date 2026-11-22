#include <iostream>
#include "../src/util.h"
#include "../src/board.h"

bool isLowerVowel(char c)
{
    switch (c)
    {
        case 'a':
        case 'b':
            return true;
        default:
            return false;
    }
}

using namespace std;
int testVowel() {
    if (!isLowerVowel('a')) return 1;
    if (!isLowerVowel('q')) return 0;
    return 0;
}

int testSplit(){
    if (split("a,b,c", ',').size() != 3) return 1;

    if (split("a,b,c", ',')[1] != "b") return 2;
    if (split("abc", ',').size() != 1 ) return 3;
    if (split("", ' ').size() != 0) return 4;
    return 0;

}

int testIsMove(){
    if (!isMove("e2e4")) return 1;
    if (isMove("e2z4")) return 2;
    if (isMove("e2e")) return 3;
    if (isMove("e7e8q")) return 4;
    return 0 ;
}

int report(const string& name, int result){
    if (result != 0)
        cout << name << result << "failed \n";
    else
        cout << name << "test passed \n";
    return 0;
}

int main()
{
int fails = 0 ;
    fails += report("split", testSplit());
    fails += report ("is A Move", testIsMove());
}
