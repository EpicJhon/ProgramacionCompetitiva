//#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 494 - Kindergarten Counting Game
 */
int main(int argc, char** argv) {

    string line;
    int sum;
    int size;

    while (getline(cin, line)) {

        sum = 0;
        size = line.length();

        for (int i = 0; i < size; i++)
            if ((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z')) {
                sum++;
                for (; ((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z')) && i < size; i++);
            }

        cout << sum << endl;

    };

    return 0;
}

