//#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 * Single Round Match 385 Round 1 - Division II, Level One 
 */
class RussianSpeedLimits {
public:

    int getCurrentLimit(vector<string> signs) {

        bool city = true;

        if (is_number(signs[signs.size() - 1]))
            return stoi(signs[signs.size() - 1]);

        for (int i = 0; i < signs.size(); i++)
            if (signs[i] == "city")
                city = !city;

        return (city) ? 60 : 90;
    }

private:

    bool is_number(const std::string& s) {
        std::string::const_iterator it = s.begin();
        while (it != s.end() && std::isdigit(*it)) ++it;
        return !s.empty() && it == s.end();
    }
};

int main(int argc, char** argv) {

    RussianSpeedLimits rl;

    cout << rl.getCurrentLimit({"city", "50", "default"}) << endl;

    return 0;
}