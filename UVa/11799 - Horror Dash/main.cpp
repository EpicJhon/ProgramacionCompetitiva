#include <iostream>

#ifdef IDE

#include <fstream>

#endif

using namespace std;

/*
 * 11799 - Horror Dash
 */

int main() {

#ifdef IDE
    std::ifstream in("tests");
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to tests!
    std::ofstream out("result");
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to result!
#endif

    long tests, monsters, speed, max;

    cin >> tests;

    for (int i = 1; i <= tests; i++) {
        // reset max
        max = -1;
        cin >> monsters;

        for (int j = 0; j < monsters; j++) {
            cin >> speed;
            max = (speed > max) ? speed : max;
        }

        cout << "Case " << i << ": " << max << endl;
    }


    return 0;
}