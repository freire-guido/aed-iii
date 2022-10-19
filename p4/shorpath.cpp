#include "../algo3.h"
using namespace std;

struct Estado {
    int u, v, p;
    Estado(int a, int b, int c) { u = a; v = b; p = c; };
    bool operator>(const Estado& e) const { return e.p > p; };
    bool operator==(const Estado& e) const {return e.u == u && e.v == v && e.p == p; };
};

int n, m, k;
vector<int> ady[3000];
vector<Estado> sup;

int dijkstra() {
    int dist[n][n];
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) dist[i][j] = INF;
    priority_queue<Estado, vector<Estado>, greater<Estado>> cp;
    cp.push(Estado(0, 0, 0));

    while (!cp.empty()) {
        Estado e = cp.top(); cp.pop();
        if (dist[e.u][e.v] < e.p) continue;
        dist[e.u][e.v] = e.p;
        
        for (int w: ady[e.v]) {
            if (find(sup.begin(), sup.end(), Estado(e.u, e.v, w)) == sup.end() && dist[e.v][w] > dist[e.u][e.v] + 1) {
                dist[e.v][w] = dist[e.u][e.v] + 1;
                cp.push(Estado(e.v, w, dist[e.u][e.v] + 1));
            }
        }
    }

    int min = INF;
    for (int i = 0; i < n; ++i) {
        if (min > dist[i][n-1]) {
            min = dist[i][n-1];
        }
    }
    return min;
}

int main() {
    while (cin >> n >> m >> k) {
        for (int i = 0; i < m; ++i) {
            int u, v; cin >> u >> v;
            ady[u-1].push_back(v-1);
        }
        for (int i = 0; i < k; ++i) {
            int a, b, c; cin >> a >> b >> c;
            sup.push_back(Estado(a, b, c));
        }
        cout << dijkstra() << endl;
    }
}