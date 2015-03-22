//#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * Single Round Match 437 Round 1 - Division II, Level One
 */

class TheBeauty {
public:

    int find(int n) {
        int sum = 0;
        string num = to_string(n);
        for (int i = '0'; i <= '9'; i++) {
            if (num.find(i) != string::npos)
                sum++;
        }

        return sum;
    }

};

int main(int argc, char** argv) {

    TheBeauty tb;

    cout << tb.find(932400154) << endl;

    return 0;
}