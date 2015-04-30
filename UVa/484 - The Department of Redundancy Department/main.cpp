#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

/*
 * 484 - The Department of Redundancy Department
 */
int main(int argc, char** argv) {

    string line;
    int number;
    vector<map<int, int>> r;
    map<int, int> m;
    bool findOK = false;

    while (getline(cin, line)) {

        if (line.empty())
            break;

        istringstream tmp(line);
        while (tmp >> number) {
            findOK = false;
            for (auto &vm : r) {
                if (vm.find(number) != vm.end()) {
                    vm.at(number)++;
                    findOK = true;
                    break;
                }
            }

            if (!findOK) {
                m.clear();
                m.insert({number, 1});
                r.push_back(m);
            }
        }
    }

    for (auto vm : r)
        printf("%d %d\n", vm.begin()->first, vm.begin()->second);

    return 0;
}

