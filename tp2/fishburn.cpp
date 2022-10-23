#include <bits/stdc++.h>
#define INF 1e9;
using namespace std;

int n, m, k;
vector<int> D;
// (!) n, m, k no acotados por enunciado
vector<int> ady[10000];
int dist[10000][10000];

int bellford() {

}

int main() {
    while (cin >> k >> n >> m) {
        for (int i = 0; i <= n; ++i) ady[i].clear();
        for (int i = 0; i <= n; ++i) for (int j = 0; j <= n; ++j) dist[i][j] = INF;
        for (int i = 0; i < k; ++i) {
            int a, b, c; cin >> a >> b >> c;
            ady[b].push_back(a);
            dist[b][a] = c;
        }
        for (int i = 0; i < m; ++i) {
            int d; cin >> d;
            D.push_back(d);
        }
    }
}