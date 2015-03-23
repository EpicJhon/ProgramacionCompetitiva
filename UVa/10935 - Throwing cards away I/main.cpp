//#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

/*
 * 10935 - Throwing cards away I
 */

int main(int argc, char** argv) {

    int cards, tmp;
    std::queue<int> deck;

    while (scanf("%d", &cards), cards) {

        for (int i = 1; i <= cards; i++)
            deck.push(i);

        printf("Discarded cards:");

        do {
            if (deck.size() == 1) {
                printf("\nRemaining card: %d\n", deck.front());
                deck.pop();
                break;
            }

            if (deck.size() > 2)
                printf(" %d,", deck.front());
            else
                printf(" %d", deck.front());
            deck.pop();
            tmp = deck.front();
            deck.pop();
            deck.push(tmp);

        } while (true);

    }

    return 0;
}