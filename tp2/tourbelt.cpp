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

int kruskal() {
    sort(E.begin(), E.end());
    int res = 0;
    for (Arista& a: E) {
        if (find_set(a.u) != find_set(a.v)) {
            for (int i = 0; i < n; ++i) {
                int j = find_set(i);
                ady[find_set(a.u)][j].first = max(ady[find_set(a.u)][j].first, ady[find_set(a.v)][j].first);
                ady[j][find_set(a.u)].first = ady[find_set(a.u)][j].first;
                ady[find_set(a.u)][j].second = min(ady[find_set(a.u)][j].second, ady[find_set(a.v)][j].second);
                ady[j][find_set(a.u)].second = ady[find_set(a.u)][j].second;
            }
            parent[find_set(a.v)] = find_set(a.u);
            tam[find_set(a.u)] += tam[find_set(a.v)];
            int maxExt = -1;
            int minInt = ady[find_set(a.u)][find_set(a.u)].second;
            for (int j = 0; j < n; ++j) {
                if (find_set(j) != find_set(a.u)) {
                    maxExt = max(maxExt, ady[find_set(a.u)][j].first);
                }
            }
            if (maxExt < minInt) {
                res += tam[find_set(a.u)];
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
