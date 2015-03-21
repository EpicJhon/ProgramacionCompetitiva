//#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 458 - The Decoder
 */
int main(int argc, char** argv) {

    string letters;

    do {

        getline(cin, letters);

        if (letters.length() == 0)
            break;

        for (int i = 0; i < letters.length(); i++)
            cout << (char) (letters[i] - 7);

        cout << endl;

    } while (true);

    return 0;
}

