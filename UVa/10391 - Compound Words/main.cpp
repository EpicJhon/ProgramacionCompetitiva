//#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
//#include <time.h>

using namespace std;

/*
 * 10391 - Compound Words
 */

bool thereWord(vector<string> words, string search) {

    for (string str : words)
        if (str == search)
            return true;

    return false;
}

int main(int argc, char** argv) {

    string word, partA, partB;
    int len, a, b;
    map<int, map<char, vector < string>>> words;
    vector <string> success;

    //clock_t tStart = clock();

    while (getline(cin, word)) {
        len = word.length();

        if (len == 0)
            break;

        words[len][word[0]].push_back(word);

    }

    // iterar tamaños
    for (auto const &v : words) {
        if (v.first == 1)
            continue;

        len = v.first;

        // iterar letras del abecedario
        for (auto const &subMap : v.second) {

            // iterar palabras
            for (string const &str : subMap.second) {

                //cout << "iterando: " << str << endl;

                for (int i = 1; i < len; i++) {

                    b = len - i;
                    a = len - b;

                    //cout << "-->partA: " << a << "; partB: " << b << endl;

                    partA = str.substr(0, a);
                    partB = str.substr(a, b);

                    if (words.find(a) != words.end() && words.find(b) != words.end() && words.at(a).find(partA[0]) != words.at(a).end() && words.at(b).find(partB[0]) != words.at(b).end()) {

                        //cout << "-->partA: " << partA << "; partB: " << partB << endl;

                        if (thereWord(words.at(a).at(partA[0]), partA) && thereWord(words.at(b).at(partB[0]), partB)) {
                            success.push_back(str);
                            //puts(str.c_str());
                            break;
                        }

                    }

                }
            }
        }
    }

    std::sort(success.begin(), success.end());

    for (string str : success)
        puts(str.c_str());

    //printf("Time taken: %.2fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);

    return 0;
}