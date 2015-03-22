//#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Single Round Match 495 Round 1 - Division II, Level One
 */

class CarrotBoxesEasy {
public:

    int theIndex(vector<int> carrots, int K) {

        for (int i = 0; i < K - 1; i++)
            carrots[maxElementFromVector(carrots)[1]]--;

        return maxElementFromVector(carrots)[1];
    }

private:

    vector<int> maxElementFromVector(vector<int> v) {
        auto biggest = std::max_element(std::begin(v), std::end(v));
        return vector<int>{*biggest, std::distance(std::begin(v), biggest)};
    }

};

int main(int argc, char** argv) {

    CarrotBoxesEasy cb;

    cout << cb.theIndex({14, 36, 52, 86, 27, 97, 3, 67}, 300) << endl;

    return 0;
}