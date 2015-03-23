//#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

/*
 * 1594 - Ducci Sequence
 */
int main(int argc, char** argv) {

    int cases;
    int len;
    bool zero;

    scanf("%i", &cases);

    for (int i = 0; i < cases; i++) {
        scanf("%i", &len);

        int tuple[len];
        int preTuple[len];

        for (int j = 0; j < len; j++)
            scanf("%i", &tuple[j]);

        for (int i = 0; i < 1000; i++) {

            std::copy(tuple, tuple + len, preTuple);

            for (int j = 0; j < len; j++)
                if (j + 1 < len)
                    tuple[j] = fabs(preTuple[j] - preTuple[j + 1]);
                else
                    tuple[j] = fabs(preTuple[j] - preTuple[0]);

            zero = true;
            for (int t : tuple)
                zero = zero & (t == 0);

            if (zero) {
                puts("ZERO");
                break;
            }
        }

        if (!zero)
            puts("LOOP");

    }
    return 0;
}