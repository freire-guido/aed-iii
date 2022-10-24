#include <bits/stdc++.h>
#define INF 1e9;
using namespace std;

int r, c, q;
vector<int> ady[10000];
int parent[10000];

void bfs() {
    queue<int> c;
    for (int u = 0; u < r; ++u) {
        if (parent[u] == u) {
            c.push(u);
        }
    }
    while (!c.empty()) {
        int u = c.front(); c.pop();
        for (int v: ady[u]) {
            if (parent[v] != v) {
                parent[v] = u;
                c.push(v);
            }
        }
    }
}

void dfs() {
    for (int u = 0; u < r; ++u) {
        if (parent[u] == -1) {
            parent[u] = u;
            dfs_visit(u);
        }
    }
}

void dfs_visit(int u) {
    for (int v: ady[u]) {
        if (parent[v] == -1) {
            parent[v] = u;
            dfs_visit(v);
        } else {
            parent[v] = v;
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
        dfs();

        for (int i = 0; i < q; ++i) {
            int s, t; cin >> s >> t;
            cout << (parent[s] == parent[t] ? "Y" : "N") << endl;
        }
        cout << "-" << endl;
    }
}