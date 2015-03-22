//#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

/*
 * 489 - Hangman Judge
 */

void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if (from.empty())
        return;
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}

int main(int argc, char** argv) {

    int round;
    string expected, received, tmp;

    std::ios::sync_with_stdio(false);

    do {
        std::cin >> round;

        if (round == -1)
            break;

        std::cin >> expected >> received;

        std::cout << "Round " << round << endl;

        tmp = expected;

        for (int i = 0; i < tmp.length(); i++)
            if (received.find(tmp[i]) != string::npos) {
                replaceAll(received, string(1, tmp[i]), "");
                replaceAll(expected, string(1, tmp[i]), "");
            }

        if (expected.length() == 0 && received.length() == 0)
            std::cout << "You win." << endl;
        else if (received.length() == 7)
            std::cout << "You lose." << endl;
        else
            std::cout << "You chickened out." << endl;

    } while (true);

    return 0;
}