#include <bits/stdc++.h>
#define INF 1e9;
using namespace std;

int n, m;
vector<int> ady[5000];
int dist[5000][5000];

int kruskal() {

}

int main() {
    int t; cin >> t;
    while (cin >> n >> m) {
        for (int i = 0; i < n; ++i) ady[i].clear();
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) dist[i][j] = 0;
        for (int i = 0; i < m; ++i) {
            int v, w, k; cin >> v >> w >> k;
            ady[v - 1].push_back(w - 1);
            dist[v - 1][w - 1] = k;
        }
    }       
}