#include <iostream>
#include <sstream>
#include <map>

using namespace std;

/*
 * 10282 - Babelfish
 */
int main(int argc, char** argv) {

    string wordEn, wordWaterloo, line;
    map<string, string> dic;

    while (getline(cin, line), !line.empty()) {
        stringstream ss(line);
        getline(ss, wordEn, ' ');
        getline(ss, wordWaterloo, ' ');
        dic.insert({wordWaterloo, wordEn});
    }

    while (getline(cin, line), !line.empty())
        if (dic.find(line) != dic.end())
            printf("%s\n", dic.at(line).c_str());
        else
            printf("eh\n");

    return 0;
}
