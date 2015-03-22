//#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 * Single Round Match 294 Round 1 - Division II, Level One
 */

class ThreeCardMonte {
public:

    string position(string swaps) {
        int ball = 2;

        int from, to;

        vector<string> vSwaps;

        for (int i = 0; i < swaps.length(); i++) {
            if (swaps[i] == 'L')
                vSwaps.push_back("1-2");
            else if (swaps[i] == 'R')
                vSwaps.push_back("3-2");
            else if (swaps[i] == 'E')
                vSwaps.push_back("3-1");
        }

        for (int i = 0; i < vSwaps.size(); i++) {
            sscanf(vSwaps[i].c_str(), "%i-%i", &from, &to);

            if (from == ball)
                ball = to;
            else if (to == ball)
                ball = from;

        }

        return (ball == 1) ? "L" : (ball == 2) ? "M" : (ball == 3) ? "R" : "";
    }

};

int main(int argc, char** argv) {

    ThreeCardMonte tc;

    cout << tc.position("FLRELFLRELLFRLFEELFLRFLELRFLRFREFRFLLRFERLFLREFRFL") << endl;

    return 0;
}