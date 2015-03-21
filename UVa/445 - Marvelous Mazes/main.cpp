//#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

/*
 * 445 - Marvelous Mazes
 */

void processParts(string part) {

    int times = 0;

    for (int i = 0; i < part.length(); i++)
        if (part[i] >= '0' && part[i] <= '9')
            times += ((int) part[i]) - 48;
        else {
            for (int j = 0; j < times; j++)
                cout << ((part[i] == 'b') ? ' ' : part[i]);
            times = 0;
        }

    cout << endl;
}

int main(int argc, char** argv) {

    string line;
    string part;

    while (getline(cin, line)) {
        if (line.find('!') != string::npos) {
            stringstream ss(line);

            while (getline(ss, part, '!'))
                processParts(part);

        } else
            processParts(line);
    }

    return 0;
}

