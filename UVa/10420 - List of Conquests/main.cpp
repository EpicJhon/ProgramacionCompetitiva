#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

/*
 * 10420 - List of Conquests
 */

int main() {


    int tests;
    string sC;
    map<string, int> c;

    cin >> tests;

    for (int i = 0; i < tests; i++) {
        cin >> sC;
        c[sC] = (!c[sC]) ? 1 : ++c[sC];
        getline(cin, sC);
    }

    for (auto &kv : c)
        cout << kv.first << " " << kv.second << endl;

    return 0;
}