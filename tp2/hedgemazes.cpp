#include <bits/stdc++.h>
#define INF 1e9;
using namespace std;

int r, c, q;
vector<int> ady[10000];
vector<int> ady1[10000];
int parent[10000];
int tin[10000];
int raiz[10000];

void dfs_visit(int u, vector<int> ady[], int t, int r) {
    tin[u] = t++;
    for (int v: ady[u]) {
        raiz[v] = r;
        if (parent[v] == -1) {
            parent[v] = u;
            dfs_visit(v, ady, t, r);
        }
    }
}

void dfs(vector<int> ady[]) {
    for (int u = 0; u < r; ++u) {
        if (parent[u] == -1) {
            raiz[u] = u;
            parent[u] = u;
            dfs_visit(u, ady, 0, u);
        }
    }
}

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
        ady1[parent[s]].push_back(s);
    }
    return cant;
}

int main() {
    while (cin >> r >> c >> q) {
        if(r==0 && c==0 && q==0){
            continue;
        }
        for (int i = 0; i < r; ++i) {
            parent[i] = -1;
        }
        for (int i = 0; i < c; ++i) {
            int a, b; cin >> a >> b;
            ady[a - 1].push_back(b - 1);
            ady[b - 1].push_back(a - 1);
        }
        dp(0);
        for (int i = 0; i < r; ++i) parent[i] = -1;
        dfs(ady1);
        for (int i = 0; i < q; ++i) {
            int s, t; cin >> s >> t;
            cout << (raiz[s - 1] == raiz[t - 1] ? "Y" : "N") << endl;
        }
        cout << "-" << endl;
        for (int i = 0; i < r; ++i) {
            ady[i].clear();
            ady1[i].clear();
            tin[i] = -1;
            raiz[i] =i ;
            parent[i] = -1;
        }
    }
}
