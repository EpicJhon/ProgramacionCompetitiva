//#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
//#include <time.h>
#include <queue>

using namespace std;

/*
 * 12100 - Printer Queue
 */

struct sJobs {
    int pos, priority;
};

vector<int> maxElementFromVector(vector<int> v) {
    auto biggest = std::max_element(std::begin(v), std::end(v));
    return vector<int>{*biggest, std::distance(std::begin(v), biggest)};
}

int main(int argc, char** argv) {

    //clock_t tStart = clock();

    int cases, minutes = 0;
    int jobs, pos, priority;
    vector<int> priorities, maxPriority;
    queue<sJobs> quete, empty;
    sJobs actualJob;

    scanf("%d", &cases);

    for (int i = 0; i < cases; i++) {

        scanf("%d %d", &jobs, &pos);

        quete = empty;
        priorities.clear();
        minutes = 0;

        for (int i = 0; i < jobs; i++) {
            scanf("%d", &priority);
            quete.push(sJobs{i, priority});
            priorities.push_back(priority);
        }


        do {
other:
            maxPriority = maxElementFromVector(priorities);

            actualJob = quete.front();

            if (actualJob.priority == maxPriority[0]) {
                minutes++;
                quete.pop();
                priorities.erase(priorities.begin() + maxPriority[1]);

                if (actualJob.pos == pos)
                    break;
                else
                    goto other;
            } else {
                quete.pop();
                quete.push(actualJob);
            }
        } while (true);

        printf("%d\n", minutes);

    }



    //printf("Time taken: %.2fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);

    return 0;
}