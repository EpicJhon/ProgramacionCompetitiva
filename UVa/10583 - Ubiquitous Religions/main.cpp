#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

/*
 * 10583 - Ubiquitous Religions
 */

/*
 * Info: https://jariasf.wordpress.com/2012/04/02/disjoint-set-union-find/
 */

class UnionFind {
private:
    vector<int> tree;
public:

    UnionFind(int n) {
        for (int i = 0; i <= n; i++)
            this->tree.push_back(i);
    }

    /* Metodo para encontrar la raiz del vertice actual X */
    int Find(int x) {
        if (x == this->tree[x]) { //Si estoy en la raiz
            return x; //Retorno la raiz
        }//else return Find( padre[ x ] ); //De otro modo busco el padre del vertice actual, hasta llegar a la raiz.
        else return this->tree[x] = Find(this->tree[x]); //Compresion de caminos
    }

    /* Metodo para unir 2 componentes conexas */
    void Union(int x, int y) {
        int xRoot = Find(x); //Obtengo la raiz de la componente del vertice X
        int yRoot = Find(y); //Obtengo la raiz de la componente del vertice Y
        this->tree[xRoot] = yRoot; //Mezclo ambos arboles o conjuntos, actualizando su padre de alguno de ellos como la raiz de otro
    }

    void Dump() {
        for (int i = 0; i < this->tree.size(); i++)
            cout << i << " = " << this->tree[i] << endl;
    }

};

int main() {

    map<int, bool> m;
    int i_i, i_n, i_m, a, b;

    i_i = 1;
    do {
        cin >> i_n >> i_m;

        if (i_n == 0 && i_m == 0)
            break;

        m.clear();
        UnionFind uf(i_n);

        for (int i = 0; i < i_m; i++) {
            cin >> a >> b;
            uf.Union(a, b);
        }

        for (int i = 1; i <= i_n; i++)
            m.insert({uf.Find(i), true});

        cout << "Case " << i_i++ << ": " << m.size() << endl;
    } while (true);

    return 0;

}