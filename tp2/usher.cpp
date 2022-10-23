#include <bits/stdc++.h>
#define INF 1e9;
using namespace std;

int c, p, q;
vector<pair<int, int>> ady[501];
vector<int> vuelven;
int dist[501];

int dijkstra() {
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
    for (int f: vuelven) {
        res = min(res, dist[f]);
    }
    return res;
}

int main() {
    int t; cin >> t;
    while (cin >> c >> p) {
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
                int m, v; cin >> m >> v;
                if (v == 0) vuelven.push_back(u);
                ady[u].push_back({v, m});
            }
        }
        cout << c / dijkstra() - 1 << endl;
    }
}