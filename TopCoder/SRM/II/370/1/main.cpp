//#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 * Single Round Match 370 Round 1 - Division II, Level One 
 */
class Containers {
public:

    int wastedSpace(vector<int> containers, vector<int> packages) {

        int currentPackage = 0;
        int currentContainer = 0;
        int wastedSpace = 0;

steps:
        if (currentPackage == packages.size() || currentContainer == containers.size()) {
            //cout << "end step" << endl;
            for (int i = 0; i < containers.size(); i++)
                wastedSpace += containers[i];

            return wastedSpace;
        }

        //cout << "step 1" << endl;
        if (packages[currentPackage] > containers[currentContainer]) {
            //cout << "step 3" << endl;
            currentContainer++;
            goto steps;
        } else {
            //cout << "step 2" << endl;
            containers[currentContainer] -= packages[currentPackage];
            currentPackage++;
            goto steps;
        }
    }
};

int main(int argc, char** argv) {

    Containers ct;

    cout << ct.wastedSpace({3, 4, 5, 6},
    {
        3, 3, 3, 3, 3
    }) << endl;

    return 0;
}