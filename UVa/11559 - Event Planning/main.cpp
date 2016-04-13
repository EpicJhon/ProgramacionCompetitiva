#include <iostream>

#ifdef IDE

#include <fstream>

#endif

using namespace std;

/*
 * 11559 - Event Planning
 */

int main() {

#ifdef IDE
    std::ifstream in("tests");
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to tests!
    std::ofstream out("result");
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to result!
#endif

    const long MAX = 500001;

    long n, b, h, w, p, a, cost, price;
    while (cin >> n >> b >> h >> w) {

        // reset cost
        cost = MAX;
        // hotels
        for (int i = 0; i < h; i++) {
            cin >> p;
            // get week a
            for (int j = 0; j < w; j++) {
                cin >> a;
                price = p * n;
                if (n <= a && price <= b) {
                    cost = (price < cost) ? price : cost;
                }
            }
        }

        if (cost < MAX)
            cout << cost;
        else
            cout << "stay home";
        cout << endl;

    }

    return 0;
}