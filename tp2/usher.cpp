#include <bits/stdc++.h>
#define INF 1e9;
using namespace std;

int c, p, q;
vector<pair<int, int>> ady[501];
vector<pair<int, int>> vuelven;
int dist[501];

int dijkstra() {
    dist[0] = 0;
    priority_queue<int, vector<int>, greater<int>> cp;
    cp.push(0);
    while (!cp.empty()) {
        int u = cp.top(); cp.pop();
        for (auto v: ady[u]) {
            if (dist[v.first] > dist[u] + v.second) {
                dist[v.first] = dist[u] + v.second;
                cp.push(v.first);
            }
        }
    }
    int res = INF;
    for (auto v: vuelven) {
        res = min(res, dist[v.first] + v.second);
    }
    return res;
}

int main() {
    int t; cin >> t;
    while (cin >> c >> p) {
        vuelven.clear();
        for (int i = 0; i <= p; ++i) {
            ady[i].clear();
            dist[i] = INF;
        }
        cin >> q;
        for (int i = 0; i < q; ++i) {
            int f; cin >> f;
            ady[0].push_back({f, 0});
        }
        for (int u = 1; u <= p; ++u) {
            int r; cin >> r;
            for (int i = 0; i < r; ++i) {
            //  (!) Puede ocurrir que dos reglas distintas
            //      definan el pasaje de la caja hacia un mismo feligres.
            //  (?) Me quedo siempre con la de minimo costo
                int m, v; cin >> m >> v;
                if (v == 0) {
                    vuelven.push_back({u, m});
                } else {
                    ady[u].push_back({v, m});
                }
            }
        }
        cout << c / (dijkstra() - 1) << endl;
    }
}