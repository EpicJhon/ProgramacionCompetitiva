//#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 490 - Rotating Sentences
 */
int main(int argc, char** argv) {

    char phrases[100][100] = {
        {0}
    };

    string line;
    int lines = 0;
    int length = 0;

    while (getline(cin, line)) {

        length = (line.length() > length) ? line.length() : length;

        if (line.length() == 0)
            break;

        for (int j = 0; j < line.length(); j++)
            phrases[j][lines] = line[j];
        lines++;
    }

    for (int i = 0; i < length; i++) {
        for (int j = lines - 1; j >= 0; j--)
            if (phrases[i][j] != 0)
                cout << phrases[i][j];
            else
                cout << ' ';

        cout << endl;
    }

    return 0;
}

