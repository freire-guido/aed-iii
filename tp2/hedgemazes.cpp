#include <bits/stdc++.h>
#define INF 1e9;
using namespace std;

int r, c, q;
vector<int> ady[10000];
int res[10000][10000];

int dfs() {
    
}

int main() {
    while (cin >> r >> c >> q) {
        for (int i = 0; i < r; ++i) ady[i].clear();
        for (int i = 0; i < r; ++i) for (int j = 0; j < r; ++j) res[i][j] = 0;
        for (int i = 0; i < c; ++i) {
            int a, b; cin >> a >> b;
            ady[a - 1].push_back(b - 1);           
        }
        for (int i = 0; i < q; ++i) {
            int s, t; cin >> s >> t;
            cout << (res[s - 1][t - 1] == 1 ? "Y" : "N") << endl;
        }
    }
}