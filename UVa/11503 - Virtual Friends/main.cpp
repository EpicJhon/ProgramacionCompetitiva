#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

/*
 * 11503 - Virtual Friends
 */

/*
 * Info: https://jariasf.wordpress.com/2012/04/02/disjoint-set-union-find/
 */

class UnionFind {
private:
    vector<int> tree;
    vector<int> size;
public:

    UnionFind(int n) {
        for (int i = 0; i <= n; i++) {
            this->tree.push_back(i);
            this->size.push_back(1); // 1 amigo
        }
    }

    /* Metodo para encontrar la raiz del vertice actual X */
    int Find(int x) {
        if (x == this->tree[x]) { //Si estoy en la raiz
            return x; //Retorno la raiz
        }//else return Find( padre[ x ] ); //De otro modo busco el padre del vertice actual, hasta llegar a la raiz.
        else return this->tree[x] = Find(this->tree[x]); //Compresion de caminos
    }

    /* Metodo para unir 2 componentes conexas
     * Retorna el tamaño del nuevo conjunto */
    int Union(int x, int y) {
        int xRoot = Find(x); //Obtengo la raiz de la componente del vertice X
        int yRoot = Find(y); //Obtengo la raiz de la componente del vertice Y

        if (xRoot != yRoot) {
            this->size[yRoot] += this->size[xRoot];
            this->tree[xRoot] = yRoot; //Mezclo ambos arboles o conjuntos, actualizando su padre de alguno de ellos como la raiz de otro
        }

        return this->size[yRoot];
    }

    void Dump() {
        for (int i = 0; i < this->tree.size(); i++)
            cout << i << " = " << this->tree[i] << endl;
    }

};

int main() {

    map<string, int> index;
    string a, b;
    int tests, F;

    cin >> tests;

    for (int i = 0; i < tests; i++) {
        cin >> F;
        UnionFind uf(F * 2);

        index.clear();
        for (int i = 0, j = 1; i < F; i++) {
            cin >> a >> b;
            if (!index[a]) index[a] = j++;
            if (!index[b]) index[b] = j++;
            cout << uf.Union(index[a], index[b]) << endl;
        }

    }

    return 0;
}