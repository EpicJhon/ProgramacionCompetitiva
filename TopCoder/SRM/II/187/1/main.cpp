//#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

/*
 * Single Round Match 187 Round 1 - Division II, Level One
 */
class OfficeParking {
public:

    int spacesUsed(vector<string> events) {

        int max = 0;
        int ret = 0;
        vector<string> buffer;
        vector<string> parts;

        for (int i = 0; i < events.size(); i++) {
            parts = split(events[i], ' ');

            switch (resolveOption(parts[1])) {
                case arrives:
                    buffer.push_back(parts[0]);
                    break;

                case departs:
                    ret = findElement(buffer, parts[0]);

                    if (ret != -1)
                        buffer.erase(buffer.begin() + ret);

                    break;
            }

            max = (buffer.size() > max) ? buffer.size() : max;
        }

        return max;
    }


private:

    enum options {
        arrives, departs
    };

    options resolveOption(string op) {
        if (op == "arrives")
            return arrives;
        else
            return departs;
    }

    vector<string> split(string str, char delimiter) {
        vector<string> parts;
        if (str.find(delimiter) != string::npos) {
            stringstream ss(str);
            string part;

            while (getline(ss, part, delimiter))
                parts.push_back(part);

        }

        return parts;
    }

    int findElement(vector<string> v, string search) {
        for (int i = 0; i < v.size(); i++)
            if (v[i] == search)
                return i;
        return -1;
    }

};

int main(int argc, char** argv) {

    OfficeParking op;

    cout << op.spacesUsed({"AdminBrett arrives", "AdminBrett departs", "AdminBrett arrives", "AdminBrett departs",
        "AdminBrett arrives", "AdminBrett departs", "AdminBrett arrives", "AdminBrett departs",
        "AdminBrett arrives", "AdminBrett departs", "AdminBrett arrives", "AdminBrett departs",
        "AdminBrett arrives", "AdminBrett departs", "AdminBrett arrives", "AdminBrett departs"}) << endl;

    return 0;
}