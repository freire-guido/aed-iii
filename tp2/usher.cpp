#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

int c, p, q;
map<int, int> ady[501];
map<int, int> vuelven;
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
    t = 0;
    while (cin >> c >> p) {
        t++;
        vuelven.clear();
        for (int i = 0; i <= p; ++i) {
            ady[i].clear();
            dist[i] = INF;
        }
        cin >> q;
        for (int i = 0; i < q; ++i) {
            int f; cin >> f;
            ady[0][f] = 0;
        }
        for (int u = 1; u <= p; ++u) {
            int r; cin >> r;
            for (int i = 0; i < r; ++i) {
                int m, v; cin >> m >> v;
                if (v == 0) {
                    vuelven[u] = min(vuelven.count(u) ? vuelven[u] : INF, m);
                } else {
                    ady[u][v] = min(ady[u].count(v) ? ady[u][v] : INF, m);
                }
            }
        }
        cout << (c - 2) / (dijkstra() - 1) << endl;
    }
}