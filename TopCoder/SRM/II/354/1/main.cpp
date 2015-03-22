//#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 * Single Round Match 354 Round 1 - Division II, Level One
 */

class Thimbles {
public:

    int thimbleWithBall(vector<string> swaps) {
        int ball = 1;

        int from, to;

        for (int i = 0; i < swaps.size(); i++) {
            sscanf(swaps[i].c_str(), "%i-%i", &from, &to);

            if (from == ball)
                ball = to;
            else if (to == ball)
                ball = from;

        }
        return ball;
    }

};

int main(int argc, char** argv) {

    Thimbles tb;

    cout << tb.thimbleWithBall({"1-2", "3-1"}) << endl;

    return 0;
}