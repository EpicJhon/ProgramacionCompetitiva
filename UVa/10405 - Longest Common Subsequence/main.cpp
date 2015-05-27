#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 10405 - Longest Common Subsequence
 */

/*
 * Info:http://es.wikipedia.org/wiki/Problema_de_Subsecuencia_Com%C3%BAn_mas_Larga#Calculando_la_longitud_del_LCS
 */
int LCSLength(string X, string Y) {
    int m = X.size();
    int n = Y.size();
    int C[m + 1][n + 1];

    for (auto &kv : C)
        for (auto &v : kv)
            v = 0;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (X[i - 1] == Y[j - 1])
                C[i][j] = C[i - 1][j - 1] + 1;
            else
                C[i][j] = max(C[i][j - 1], C[i - 1][j]);

    return C[m][n];
}

int main() {

    string a, b;

    while (getline(cin, a), getline(cin, b))
        cout << LCSLength(a, b) << endl;

    return 0;

}
