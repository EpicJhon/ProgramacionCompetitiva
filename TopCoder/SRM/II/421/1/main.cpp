//#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * Single Round Match 421 Round 1 - Division II, Level One
 */
class GymTraining {
public:

    int trainingTime(int needToTrain, int minPulse, int maxPulse, int trainChange, int restChange) {

        int train = 0;
        int minutes = 0;
        int x = minPulse;

        if (x + trainChange > maxPulse && x - restChange < minPulse)
            return -1;

        while (train != needToTrain) {
            minutes++;
            if (x + trainChange <= maxPulse) {
                x += trainChange;
                train++;
            } else {
                x -= restChange;
                x = (x < minPulse) ? minPulse : x;
            }
        }

        return minutes;

    }
};

int main(int argc, char** argv) {

    GymTraining gt;

    cout << gt.trainingTime(200, 50, 200, 150, 1) << endl;

    return 0;
}