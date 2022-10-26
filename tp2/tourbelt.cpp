#include <bits/stdc++.h>
#define INF 1e9;
using namespace std;

struct Arista {
    int u, v, p;
    Arista(int a, int b, int c) { u = a; v = b; p = c; }
    bool operator<(const Arista& a) const { return p > a.p; }
};

int n, m;
int parent[5000];
int tam[5000];
vector<Arista> E;

int find_set(int x) {
    return parent[x] == x ? x : parent[x] = find_set(parent[x]);
}

int kruskal() {
    sort(E.begin(), E.end());
    int res = 0;
    parent[find_set(E[0].u)] = find_set(E[0].v);
    tam[find_set(E[0].v)] += tam[find_set(E[0].u)];
    res += tam[E[0].v];
    for (int i = 1; i < m; ++i) {
        parent[find_set(E[i].u)] = E[i].v;
        if (E[i].p != E[i-1].p) {
            tam[find_set(E[i].v)] += tam[find_set(E[i].u)];
            res += tam[E[0].v];
        }
    }
    return res;
}

int main() {
    int t; cin >> t;
    while (cin >> n >> m) {
        E.clear();
        for (int i = 0; i <= n; ++i) { parent[i] = i; tam[i] = 1; }
        for (int i = 0; i < m; ++i) {
            int v, w, k; cin >> v >> w >> k;
            E.push_back(Arista(v, w, k));
        }
        cout << kruskal() << endl;
    }       
}