#include <iostream>
#include <sstream>
#include <map>

using namespace std;

/*
 * 10226 - Hardwood Species
 */
int main(int argc, char** argv) {

    string line;
    int tests, total;
    map<string, int> species;

    scanf("%d\n", &tests);

    for (int i = 1; i <= tests; i++) {
        total = 0;
        species.clear();

        while (getline(cin, line), !line.empty()) {
            if (species.count(line) != 0)
                species.at(line)++;
            else
                species.insert({line, 1});
            total++;
        }

        for (auto &kv : species)
            printf("%s %.4lf\n", kv.first.c_str(), (kv.second * 100.0) / total);

        if (i != tests)
            printf("\n");

    }

    return 0;
}
