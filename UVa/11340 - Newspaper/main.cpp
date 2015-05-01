#include <iostream>
#include <sstream>
#include <map>

using namespace std;

/*
 * 11340 - Newspaper
 */
int main(int argc, char** argv) {

    string line;
    int tests, letters, cents, lines;
    unsigned long long paid;
    char letter;
    map<char, int> paidLetters;

    scanf("%d", &tests);

    for (int i = 1; i <= tests; i++) {

        paid = 0;
        paidLetters.clear();

        scanf("%d", &letters);

        for (int i = 1; i <= letters; i++) {
            scanf(" %c %d", &letter, &cents);
            paidLetters.insert({letter, cents});
        }

        scanf("%d", &lines);
        cin.ignore();

        for (int i = 1; i <= lines; i++) {
            getline(cin, line);
            for (char c : line)
                if (paidLetters.find(c) != paidLetters.end())
                    paid += paidLetters.at(c);
        }

        printf("%.2f$\n", paid / 100.0);
    }

    return 0;
}
