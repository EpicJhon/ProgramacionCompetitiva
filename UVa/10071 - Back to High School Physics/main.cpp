#include <iostream>

using namespace std;

/*
 * 10071 - Back to High School Physics
 */
int main(int argc, char** argv) {

    int v, t;

    do {

        if ((cin >> v) and (cin >> t))
            cout << (v * t * 2) << endl;
        else
            break;

    } while (true);
    return 0;
}
