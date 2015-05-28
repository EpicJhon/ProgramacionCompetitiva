#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

/*
 * 573 - The Snail
 */

int main() {

    int day;
    double HS, H, U, D, F, fatigue;

    do {
        cin >> H >> U >> D >> F;

        if (H == 0)
            break;

        day = 1;
        HS = 0.0;
        fatigue = (F * U) / 100.0;

        do {
            if (U >= 0)
                HS += U;

            if (HS > H) {
                cout << "success on day " << day << endl;
                break;
            }

            HS -= D;

            if (HS < 0.0) {
                cout << "failure on day " << day << endl;
                break;
            }
            U -= fatigue;
            day++;

        } while (true);


    } while (true);

    return 0;
}