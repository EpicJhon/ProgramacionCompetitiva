//#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * 10763 - Foreign Exchange
 */

int main(int argc, char** argv) {

    int cases, iFrom, iTo;
    vector<int> clear, from, to;

    while (scanf("%d", &cases), cases) {

        from = to = clear;

        for (int i = 0; i < cases; i++) {
            scanf("%d %d", &iFrom, &iTo);
            from.push_back(iFrom);
            to.push_back(iTo);
        }

        std::sort(from.begin(), from.end());
        std::sort(to.begin(), to.end());

        printf("%s\n", (from == to) ? "YES" : "NO");
    }

    return 0;
}