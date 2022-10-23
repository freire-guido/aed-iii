#include <bits/stdc++.h>
#define INF 1e9;
using namespace std;

int c, p, q;
vector<int> ady[501];
int dist[501][501];

int dijkstra() {

}

int main() {
    int t; cin >> t;
    while (cin >> c >> p) {
        for (int i = 0; i <= p; ++i) ady[i].clear();
        for (int i = 0; i <= p; ++i) for (int j = 0; j <= p; ++j) dist[i][j] = INF;
        cin >> q;
        for (int i = 0; i < q; ++i) {
            int f; cin >> f;
            ady[0].push_back(f);
            dist[0][f] = 0;
        }
        for (int u = 0; u < p; ++u) {
            int r; cin >> r;
            for (int i = 0; i < r; ++i) {
            //  (!) Puede ocurrir que dos reglas distintas
            //      definan el pasaje de la caja hacia un mismo feligres.
                int m, v; cin >> m >> v;
                ady[u].push_back(v);
                dist[u][v] = m;
            }
        }
    }
}