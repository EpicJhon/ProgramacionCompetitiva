#include <iostream>

#ifdef IDE
#include <fstream>
#endif

using namespace std;

/*
 * 11172 - Relational Operators
 */

int main() {

#ifdef IDE
    std::ifstream in("tests");
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
#endif


    long tests, a, b;

    cin >> tests;

    for (int i = 0; i < tests; i++) {
        cin >> a >> b;

        if (a == b) {
            cout << '=';
        } else {
            cout << ((a > b) ? '>' : '<');
        }
        cout << endl;
    }

    return 0;
}