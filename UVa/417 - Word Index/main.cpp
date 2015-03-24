//#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
//#include <time.h>

using namespace std;

/*
 * 417 - Word Index
 */

/* tnx marioyc */
map<string, int> createIndex(int length = 5) {

    map<string, int> index;
    queue<string> Q;
    string s;
    int cont;

    for (char c = 'a'; c <= 'z'; c++)
        Q.push(string(1, c));

    cont = 1;

    while (!Q.empty()) {
        s = Q.front();
        Q.pop();

        index[s] = cont;
        cont++;

        if (s.size() == length)
            continue;

        for (char c = s[s.size() - 1] + 1; c <= 'z'; c++)
            Q.push(s + c);
    }

    return index;
}

int main(int argc, char** argv) {

    //clock_t tStart = clock();

    string line;
    map<string, int> index = createIndex();

    while (getline(cin, line))
        printf("%d\n", (index.find(line) != index.end()) ? index.at(line) : 0);

    //printf("Time taken: %.2fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);

    return 0;
}