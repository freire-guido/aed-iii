#include <bits/stdc++.h>
#define INF 1e9;
using namespace std;

int r, c, q;
vector<int> ady[10000];
vector<int> ady1[10000];
int parent[10000];
int tin[10000];
int puente[10000];

int dp(int s) {
    dfs(ady);
    int cant = 0;
    for (int u: ady[s]) {
        if (parent[u] == s) cant += dp(u);
        else if (tin[s] > tin[u] && parent[s] != u) cant++;
        else if (tin[s] < tin[u]) cant--;
    }
    if (cant == 0 && parent[s] != s) {
        ady1[s].push_back(parent[s]);
    }
    return cant;
}

void dfs_visit(int u, vector<int> ady[], int t = 0) {
    tin[u] = t++;
    for (int v: ady[u]) {
        if (parent[v] == -1) {
            parent[v] = u;
            dfs_visit(v, ady, t);
        }
    }
}

void dfs(vector<int> ady[]) {
    for (int u = 0; u < r; ++u) {
        if (parent[u] == -1) {
            parent[u] = u;
            dfs_visit(u, ady, 0);
        }
    }
}

int main() {
    while (cin >> r >> c >> q) {
        for (int i = 0; i < r; ++i) {
            ady[i].clear();
            parent[i] = -1;
        }
        for (int i = 0; i < c; ++i) {
            int a, b; cin >> a >> b;
            ady[a - 1].push_back(b - 1);
            ady[b - 1].push_back(a - 1);
        }
        dp(0);
        for (int i = 0; i < q; ++i) {
            int s, t; cin >> s >> t;
            cout << (parent[s] == parent[t] ? "Y" : "N") << endl;
        }
        cout << "-" << endl;
    }
}
