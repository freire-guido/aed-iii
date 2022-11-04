#include <bits/stdc++.h>
#define INF 1e9;
using namespace std;

struct Arista {
    int u, v, p;
    Arista(int a, int b, int c) { u = a; v = b; p = c; }
    Arista(const Arista& a) { u = a.u; v = a.v; p = a.p; }
    bool operator<(const Arista& a) const { return p > a.p; }
    bool operator==(const Arista& a) const { return a.u == u && a.v == v && a.p == p; }
};

int n, m;
vector<Arista> E;
pair<int, int> ady[5000][5000]; // {max, min}
int parent[5000];
int tam[5000];

int find_set(int x) {
    return parent[x] == x ? x : parent[x] = find_set(parent[x]);
}

int unite_set(int a, int b) {
    a = find_set(a); b = find_set(b);
    if (tam[b] > tam[a]) swap(a, b);
    tam[a] += tam[b];
    return parent[b] = a;
}


int kruskal() {
    sort(E.begin(), E.end());
    int res = 0;
    for (const Arista& a: E) {
        int u = find_set(a.u);
        int v = find_set(a.v);
        if (u != v) {
            if (tam[v] > tam[u]) swap(v, u);
            for (int j = 0; j < n; ++j) {
                ady[j][u].first = ady[u][j].first = max(ady[u][j].first, ady[v][j].first);
                ady[j][u].second = ady[u][j].second = min(ady[u][j].second, ady[v][j].second);
            }
            unite_set(a.u, a.v);
            ady[u][u].second = min(ady[u][u].second, ady[v][v].second);
            int maxExt = -1;
            int minInt = ady[u][u].second;
            for (int j = 0; j < n; ++j) {
                if (find_set(j) != u) {
                    maxExt = max(maxExt, ady[u][j].first);
                }
            }
            if (maxExt < minInt) {
                res += tam[u];
            }
        }
    }
    return res;
}

int main() {
    int t; cin >> t;
    while (cin >> n >> m) {
        E.clear();
        for (int i = 0; i < n; ++i) { parent[i] = i; }
        for (int i = 0; i < n; ++i) tam[i] = 1;
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) ady[i][j] = {-1, 1e9};

        for (int i = 0; i < m; ++i) {
            int v, w, k; cin >> v >> w >> k;
            E.push_back(Arista(--v, --w, k));
            ady[v][w] = {k, k};
            ady[w][v] = {k, k};
        }

        cout << kruskal() << endl;
    }       
}
