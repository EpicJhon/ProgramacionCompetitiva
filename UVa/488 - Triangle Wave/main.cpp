//#include <cstdlib>
//#include <iostream>
#include <cstdio>

using namespace std;

/*
 * 488 - Triangle Wave
 */
int main(int argc, char** argv) {

    int cases;
    int a, f;

    do {
        //cin >> cases;
        scanf("%i", &cases);

        for (int i = 1; i <= cases; i++) {
            scanf("%i\n%i", &a, &f);
            //cin >> a >> f;

            for (int fr = 1; fr <= f; fr++) {

                for (int j = 1; j <= a; j++) {
                    for (int k = 0; k < j; k++)
                        //cout << j;
                        printf("%i", j);
                    //cout << endl;
                    printf("\n");
                }

                for (int j = a - 1; j >= 1; j--) {
                    for (int k = 0; k < j; k++)
                        //cout << j;
                        printf("%i", j);
                    //cout << endl;
                    printf("\n");
                }

                if ((i == cases) && (f == fr))
                    return 0;
                else
                    //cout << endl;
                    printf("\n");
            }
        }

        return 0;

    } while (true);

    return 0;
}

