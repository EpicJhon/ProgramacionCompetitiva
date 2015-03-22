//#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 * Single Round Match 397 Round 1 - Division II, Level One
 */
class BreakingTheCode {
public:

    string decodingEncoding(string code, string message) {
        char f[2];
        string ret;

        if (is_number(message))
            for (int i = 0; i < message.length(); i += 2)
                ret = ret + code.at(atoi(message.substr(i, 2).c_str()) - 1);
        else
            for (int i = 0; i < message.length(); i++) {
                sprintf(f, "%02d", code.find(message[i]) + 1);
                ret = ret.append(f);
            }

        return ret.c_str();
    }

private:

    bool is_number(const std::string& s) {
        std::string::const_iterator it = s.begin();
        while (it != s.end() && std::isdigit(*it)) ++it;
        return !s.empty() && it == s.end();
    }
};

int main(int argc, char** argv) {

    BreakingTheCode bc;

    cout << bc.decodingEncoding("faxmswrpnqdbygcthuvkojizle", "02170308060416192402") << endl;

    return 0;
}