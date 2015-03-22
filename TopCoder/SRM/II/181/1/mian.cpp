//#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 * Single Round Match 181 Round 1 - Division II, Level One
 */

class KiloMan {
public:

    int hitsTaken(vector<int> pattern, string jumps) {
        int hits = 0;
        for (int i = 0; i < jumps.length(); i++)
            hits += (jumps[i] == 'S' && pattern[i] >= 1 && pattern[i] <= 2) ? 1 : (jumps[i] == 'J' && pattern[i] > 2) ? 1 : 0;
        return hits;
    }

};

int main(int argc, char** argv) {

    KiloMan km;

    vector<int> ok = {1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7};

    cout << km.hitsTaken(ok, "SSSSSSSSSSSSSSJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ") << endl;

    return 0;
}