#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
 * 12788 - Smooth Factor
 */
int main(int argc, char** argv) {

    string line;
    int length, num, sizeBefore, longest;
    vector<int> a, tmp;
    vector<vector<int>> s;
    vector<int> ab;


    while (cin >> length) {
        a.clear();
        s.clear();
        tmp.clear();

        for (int i = 1; i <= length; i++) {
            cin >> num;
            a.push_back(num);
        }

        for (auto kv : a)
            if (tmp.size() == 0)
                tmp.push_back(kv);
            else {
                if (kv >= tmp.back())
                    tmp.push_back(kv);
                else {
                    s.push_back(tmp);
                    tmp.clear();
                    tmp.push_back(kv);
                }
            }

        if (tmp.size() > 0) {
            s.push_back(tmp);
            tmp.clear();
        }

        sizeBefore = s.size();

        for (int i = 0; i < sizeBefore; i++) {
            if (i == sizeBefore - 1)
                continue;

            ab.clear();
            ab.reserve(s[i].size() + s[i + 1].size());
            ab.insert(ab.end(), s[i].begin(), s[i].end());
            ab.insert(ab.end(), s[i + 1].begin(), s[i + 1].end());
            s.push_back(ab);
        }

        longest = 0;

        for (auto m : s)
            longest = (m.size() > longest) ? m.size() : longest;

        cout << longest << endl;
    }

    return 0;
}
