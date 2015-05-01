#include <iostream>
#include <sstream>
#include <map>

using namespace std;

/*
 * 10295 - Hay Points
 */
int main(int argc, char** argv) {

    string word, line;
    int dic, tests, amount, paid;
    map<string, int> paidWords;

    scanf("%d %d", &dic, &tests);

    for (int i = 1; i <= dic; i++) {
        cin >> word >> amount;
        paidWords.insert({word, amount});
    }

    for (int i = 1; i <= tests; i++) {
        paid = 0;

        while (cin >> line, line != ".") 
            if (paidWords.find(line) != paidWords.end())
                paid += paidWords.at(line);

        printf("%d\n", paid);
    }

    return 0;
}
