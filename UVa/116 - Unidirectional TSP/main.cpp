#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

typedef long long ll;

struct RET {
    ll weight;
    vector<int> steps;
};

/*
 * 116 - Unidirectional TSP
 */

class TSP {
private:
    vector<vector<ll>> matrix;
    ll map[10][100];
    int m, n;
    ll _INFINITY = LLONG_MAX;

    ll min(ll a, ll b, ll c) {

        ll min;

        if (a <= b) {
            min = a;
        } else {
            min = b;
        }

        if (c < min) {
            min = c;
        }

        return min;
    }

    ll f(int i, int j) {

        if (map[i][j] < this->_INFINITY) {
            return map[i][j];
        }

        if (j == this->n - 1) {
            map[i][j] = matrix[i][j];
            return map[i][j];
        }

        map[i][j] = matrix[i][j] + min(f(A(i - 1, this->m), j + 1), f(A(i, this->m), j + 1), f(A(i + 1, this->m), j + 1));

        return map[i][j];
    }

    int A(int i, int m) {
        if (i == -1)
            return m - 1;
        else if (i == m)
            return 0;
        else
            return i;
    }

public:

    TSP(vector<vector<ll>> matrix, int m, int n) {
        this->matrix = matrix;
        this->m = m;
        this->n = n;

        for (auto &kv : map)
            for (auto &v : kv)
                v = this->_INFINITY;
    }

    RET GetMinimalPath() {
        vector<int> steps;

        // create map (DP)
        for (int i = 0; i < this->m; i++) {
            this->f(i, 0);
        }

        /*
         * get minimal path
         */
        int index, weight, ram_index;
        int i_a, i_b;
        int weight_root;

        for (int j = 0; j < this->n; j++) {

            if (j == 0) {
                index = 0;
                weight_root = map[0][j];
                for (int i = 1; i < this->m; i++) {
                    if (map[i][j] < weight_root) {
                        weight_root = map[i][j];
                        index = i;
                    }

                }

                steps.push_back(index + 1);
            } else {

                ram_index = index;

                i_a = this->A(ram_index - 1, this->m);
                i_b = this->A(ram_index, this->m);
                if (map[i_a][j] == map[i_b][j]) {
                    index = (i_a < i_b) ? i_a : i_b;
                    weight = map[index][j];
                } else {
                    if (map[i_a][j] < map[i_b][j]) {
                        weight = map[i_a][j];
                        index = i_a;
                    } else {
                        weight = map[i_b][j];
                        index = i_b;
                    }
                }


                i_b = this->A(ram_index + 1, this->m);
                if (map[index][j] == map[i_b][j]) {
                    index = (index < i_b) ? index : i_b;
                    weight = map[index][j];
                } else {
                    if (map[index][j] < map[i_b][j]) {
                        weight = map[index][j];
                    } else {
                        weight = map[i_b][j];
                        index = i_b;
                    }
                }

                steps.push_back(index + 1);
            }
        }

        return (RET) {
            weight_root,
                    steps
        };
    }
};

int main() {

    int m, n, tmp;

    vector<ll> field;
    vector<vector < ll>> matrix;

    while (cin >> m >> n) {

        matrix.clear();

        for (int i = 0; i < m; i++) {
            field.clear();

            for (int j = 0; j < n; j++) {
                scanf("%d", &tmp);
                field.push_back(tmp);
            }

            matrix.push_back(field);
        }


        TSP tsp(matrix, m, n);
        RET ret = tsp.GetMinimalPath();

        for (int i = 0; i < ret.steps.size(); i++)
            cout << ret.steps[i] << ((i == ret.steps.size() - 1) ? "" : " ");
        cout << endl << ret.weight << endl;
    }

    return 0;

}
