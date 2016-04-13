#include <iostream>

#ifdef IDE

#include <fstream>

#endif

using namespace std;

/*
 * 11727 - Cost Cutting
 */

int main() {

#ifdef IDE
    std::ifstream in("tests");
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to tests!
    std::ofstream out("result");
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to result!
#endif


    long tests, a, b, c;

    cin >> tests;

    for (int i = 1; i <= tests; i++) {
        cin >> a >> b >> c;

        cout << "Case " << i << ": ";

        if (a > b) {
            if (c > a)
                cout << a;
            else {
                if (c > b)
                    cout << c;
                else
                    cout << b;
            }
        } else {
            if (c > b)
                cout << b;
            else {
                if (c > a)
                    cout << c;
                else
                    cout << a;
            }
        }

        cout << endl;
    }

    return 0;
}