//#include <cstdlib>
#include <iostream>
#include <cstdio>

using namespace std;

/*
 * 694 - The Collatz Sequence
 */

int Collatz(long A, long limit) {
    int steps = 0;
step:

    if (A > limit)
        return steps;

    steps++;
    if (A == 1)
        return steps;

    if (A % 2 == 0) {
        A /= 2;
        goto step;
    } else {
        A = A * 3 + 1;
        goto step;
    }
}

int main(int argc, char** argv) {

    int i;
    long long A, limit;

    do {
        scanf("%lld %lld", &A, &limit);

        if (A < 0 && limit < 0)
            break;

        i++;
        if (A < limit)
            printf("Case %i: A = %lld, limit = %lld, number of terms = %i\n", i, A, limit, Collatz(A, limit));

    } while (true);

    return 0;
}