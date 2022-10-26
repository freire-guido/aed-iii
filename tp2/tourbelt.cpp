#include <bits/stdc++.h>
#define INF 1e9;
using namespace std;

struct Arista {
    int u, v, p;
    Arista(int a, int b, int c) { u = a; v = b; p = v; }
    bool operator>(const Arista& a) { return p > a.p; }
};

int n, m;
int parent[5000];
int tam[5000];
vector<Arista> E;

int find_set(int x) {
    return x != parent[x] ? parent[x] = find_set(parent[x]) : parent[x];
}

int kruskal() {
    sort(E.begin(), E.end());
    int res = 0;
    for (int i = 0; i < m - 1; ++i) {
        if (find_set(E[i].u) == find_set(E[i].v)) {
            
        }
    }
}

int main() {
    int t; cin >> t;
    while (cin >> n >> m) {
        E.clear();
        for (int i = 0; i < n; ++i) parent[i] = i
        for (int i = 0; i < m; ++i) {
            int v, w, k; cin >> v >> w >> k;
            E.push_back(Arista(v, w, k));
        }
        cout << kruskal() << endl;
    }       
}