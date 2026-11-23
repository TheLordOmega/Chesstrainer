#include "../src/board.h"
#include "../src/rules.h"
#include <iostream>


using namespace std;
    int testRules() {

        {
            Move a = parseMove("e2e4");
            if (a.fromRow != 6 || a.fromCol != 4) return 1;
            if (a.toRow != 4 || a.toCol != 4) return 2;
            if( parseMove("e7e8q").promotion != 'q') return 3;
        }

            {
                if (!isWhite('Q')||isWhite('q')) return 4;
            if (isWhite('.') || isBlack('.')) return 5;
            }

        {
            if (!isKnightmv(parseMove("g1f3"))) return 6;
            if (isKnightmv(parseMove("g1g3"))) return 7;
        }
        {
            if (!isKingmv(parseMove("e1f2"))) return 8;
            if (isKingmv(parseMove("e1e3"))) return 9;
        }
        {
            char b[8][8];
            loadFen(b, "4k3/8/8/8/8/8/P7/R3K3 w - - 0 1");
            if (!pathClear(b, parseMove("a1d1"))) return 10;
            if (pathClear(b, parseMove("a1a3"))) return 11;
        }
        {
            char b[8][8];
            loadFen(b,"2b1k3/8/8/3q4/8/8/8/R3K1N1 w - - 0 1");
            if (!isrookmv(b, parseMove("a1a8"))) return 12;
            if (!isbishopmv(b, parseMove("c8h3"))) return 13;
            if (isbishopmv(b, parseMove("c8c1"))) return 14;
        }
        {
            char b[8][8];
            loadFen(b, "2b1k3/8/8/3q4/8/8/8/R3K1N1 w - - 0 1");
            if (!canReach(b, parseMove("g1f3"))) return 15;
            if (canReach(b, parseMove("e4e5"))) return 16;
        }
        {
            char b[8][8];
            loadFen(b, "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
            if (!canMove(b, parseMove("g1f3"), true)) return 17;
            if (canMove(b, parseMove("g1f3"), false)) return 18;
        }
        {
            char b[8][8];
            loadFen(b, "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
            if (!isPawnmv(b, parseMove("e2e4"))) return 19;
            if (isPawnmv(b, parseMove("e2e5"))) return 20;
            if (!isPawnmv(b, parseMove("e7e5"))) return 21;
        }
        {
            char b[8][8];
            loadFen(b, "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -0 1");
            if (!canMove(b, parseMove("e2e4"), true )) return 22;
        }


        {
            char b[8][8];
            loadFen(b, "4k3/8/8/8/8/8/4r3/4K3 w - - 0 1 ");
            if (!inCheck(b, true)) return 23;
            if (inCheck(b, false)) return 24;
            loadFen(b, "4k3/8/8/8/4r3/8/4P3/4K3 w - - 0 1");
            if (inCheck(b, true)) return 25;
        }


        {
            char b[8][8];
            loadFen(b, "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
            char c[8][8];
            copyBoard(b, c);
            if (c[7][4] != 'K') return 26;
        }

        {
            char b[8][8];
            loadFen(b, "8/2p5/3p4/KP5r/1R3p1k/8/4P1P1/8 w - - 0 1");
            if (isLegal(b, "b5b6", true)) return 27;
            if (!isLegal(b, "b4c4", true)) return 28;
        }
        {
            char b[8][8];
            loadFen(b, "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
            if (countLegalMoves(b, true) != 20) return 29;
            loadFen(b, "8/2p5/3p4/KP5r/1R3p1k/8/4P1P1/8 w - - 0 1");
            if (countLegalMoves(b, true) != 14) return 30;
        }

        {
            char b[8][8];
            loadFen(b, "rnb1kbnr/pppp1ppp/8/4p3/6Pq/5P2/PPPPP2P/RNBQKBNR w KQkq - 1 3");
            if (!isMate(b, true)) return 31;
        }
        {
            if (cleanMove("E2-E4") != "e2e4") return 32;
            if (cleanMove("HINT") != "hint") return 33;
        }
        return 0;
    }

int main() {
    int result= testRules();
    if (result ==0)
        cout << "All rule tests passed.\n";
    else
        cout << "Rule test " << result << " failed.\n";
    return result;
}
