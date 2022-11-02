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

struct Componente {
    int p, minInt, tam;
    Arista maxExt = Arista(0, 0, -1);
    Componente(int a, int b, const Arista& c, int d) { p = a; minInt = b; maxExt = Arista(c); tam = d; }
};


int n, m;
vector<Arista> E;
vector<Componente> C;
vector<Arista> ady[5000];
int parent[5000];

int find_set(int x) {
    return parent[x] == x ? x : parent[x] = find_set(parent[x]);
}

int kruskal() {
    sort(E.begin(), E.end());
    int res = 0;
    for (Arista& a: E) {
        // Es externa
        if (find_set(a.u) != find_set(a.v)) {
            parent[find_set(a.u)] = find_set(a.v);
            C[find_set(a.u)].tam += (C[find_set(a.v)]).tam;
            C[find_set(a.u)].minInt = min(C[find_set(a.u)].minInt, min(C[find_set(a.v)].minInt, a.p));
            if (C[find_set(a.u)].maxExt == a) {
                // Busco la segunda
            } else {
                C[find_set(a.u)].maxExt = max(C[find_set(a.u)].maxExt, C[find_set(a.v)].maxExt);
            }

            if (C[find_set(a.u)].minInt > C[find_set(a.u)].maxExt.p) {
                res += C[find_set(a.u)].tam;
            }
        // Es interna
        } else {
            if (a.p < C[find_set(a.u)].minInt) {
                C[find_set(a.u)].minInt = a.p;
                if (C[find_set(a.u)].minInt <= C[find_set(a.u)].maxExt.p) {
                    res -= C[find_set(a.u)].tam;
                }
            }
        }
    }
    return res;
}

int main() {
    int t; cin >> t;
    while (cin >> n >> m) {
        E.clear();
        for (int i = 0; i < m; ++i) {
            int v, w, k; cin >> v >> w >> k;
            E.push_back(Arista(v, w, k));
            ady[v].push_back(Arista(v, w, k));
        }
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;

            Arista maxExt = Arista(0, 0, -1);
            for (auto a: ady[i]) {
                // min es max !!!
                maxExt = min(maxExt, a);
            }
            C.push_back(Componente(i, 1e9, maxExt, 1));
        }
        cout << kruskal() << endl;
    }       
}
