//#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
//#include <time.h>

using namespace std;

/*
 * 12504 - Updating a Dictionary
 */

std::string myReplace(std::string &s, std::string toReplace, std::string replaceWith) {
    return (s.replace(s.find(toReplace), toReplace.length(), replaceWith));
}

int main(int argc, char** argv) {

    //clock_t tStart = clock();

    map<string, string> d[2], mEmpty;
    // 0 = +, 1 = -, 2 = *
    vector<string> myChanges[3];
    char simbols[3] = {'+', '-', '*'};

    int cases;
    string s[2], part, key, value;
    bool updates;


    scanf("%d\n", &cases);

    for (int i = 0; i < cases; i++) {

        for (int i = 0; i < 2; i++) {
            getline(cin, s[i]);
            d[i] = mEmpty;
        }

        for (auto &v : myChanges)
            v.clear();

        for (int i = 0; i < 2; i++) {

            s[i] = myReplace(s[i], "{", "");
            s[i] = myReplace(s[i], "}", "");

            stringstream ss(s[i]);

            while (getline(ss, part, ',')) {
                stringstream ss2(part);

                getline(ss2, key, ':');
                getline(ss2, value, ':');

                d[i][key] = value;

            }
        }

        // -
        for (auto kv : d[0])
            if (d[1].find(kv.first) == d[1].end())
                myChanges[1].push_back(kv.first);

        // +
        for (auto kv : d[1])
            if (d[0].find(kv.first) == d[0].end())
                myChanges[0].push_back(kv.first);

        // *
        for (auto kv : d[0])
            if (d[1].find(kv.first) != d[1].end())
                if (d[1].at(kv.first) != kv.second)
                    myChanges[2].push_back(kv.first);

        updates = false;
        for (int i = 0; i < 3; i++) {
            if (myChanges[i].size() != 0) {
                updates = true;

                std::sort(myChanges[i].begin(), myChanges[i].end());

                printf("%c", simbols[i]);
                for (int j = 0; j < myChanges[i].size(); j++)
                    printf((j == myChanges[i].size() - 1) ? "%s" : "%s,", myChanges[i][j].c_str());
                puts("");
            }
        }

        if (!updates)
            puts("No changes\n");
        else
            puts("");

    }

    //printf("Time taken: %.2fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);

    return 0;
}