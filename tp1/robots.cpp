#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<int>> M;
pair<int, int> C[5];
int c = 0;

bool encierra(int x1, int x2, int k) {
    return ((0 > x1 + 1 || x1 + 1 >= m || (M[x1 + 1][x2] != -1 && M[x1 + 1][x2] < k)) &&
        (0 > x1 - 1 || x1 - 1 >= m || M[x1 - 1][x2] != -1 && M[x1 - 1][x2] < k) &&
        !(0 > x2 + 1 || x2 + 1 >= n || M[x1][x2 + 1] != -1 && M[x1][x2 + 1] < k) &&
        !(0 > x2 - 1 || x2 - 1 >= n || M[x1][x2 - 1] != -1 && M[x1][x2 - 1] < k)) ||
        (!(0 > x1 + 1 || x1 + 1 >= m || M[x1 + 1][x2] != -1 && M[x1 + 1][x2] < k) &&
        !(0 > x1 - 1 || x1 - 1 >= m || M[x1 - 1][x2] != -1 && M[x1 - 1][x2] < k) &&
        (0 > x2 + 1 || x2 + 1 >= n || M[x1][x2 + 1] != -1 && M[x1][x2 + 1] < k) &&
        (0 > x2 - 1 || x2 - 1 >= n || M[x1][x2 - 1] != -1 && M[x1][x2 - 1] < k));
}

int manhattan(int x1, int x2, int y1, int y2) {
    return abs(x1 - y1) + abs(x2 - y2);
}

int BT(int i, int j, int s) {
    //podas
    if (!(0 <= i && i < m) || !(0 <= j && j < n)) return 0;
    if (M[i][j] != -1 && M[i][j] != s) return 0;
    if ((4*s) % (m*n) == 0 && (i != C[(4*s) / (m*n)].first || j != C[(4*s) / (m*n)].second)) return 0;
    if (encierra(i, j, s)) return 0;
    //if (manhattan(i, j, C[c].first, C[c].second) > M[C[c].first][C[c].second] - s) return 0; (no se porque no anda)
    //caso base
    if (s == m * n) return 1;
    //me guardo el relleno de la casilla para resetearla
    int pre = M[i][j]; 
    if (pre == s) {
        ++c;
    }
    M[i][j] = s;
    //doy todos los pasos
    int acum = 0;
    acum += BT(i + 1, j, s + 1);
    acum += BT(i - 1, j, s + 1);
    acum += BT(i, j + 1, s + 1);
    acum += BT(i, j - 1, s + 1);
    //reinicio casilla
    M[i][j] = pre;
    if (pre == s) {
        --c;
    }
    return acum;
}


int main() {
    int t = 0;
    while (cin >> m >> n) {
        if (m == 0 && n == 0) return 0;
        ++t;
        c = 0;

        M.resize(m);
        for (int i = 0; i < m; ++i) {
            M[i] = vector<int>(n, -1);
        }
        M[0][0] = 1;
        M[0][1] = m*n;
        C[0] = {0, 0};
        C[4] = {0, 1};
        for (int i = 0; i < 3; ++i) {
            int x; cin >> x;
            int y; cin >> y;
            M[x][y] = (0.25*(i + 1)*m*n);
            C[i + 1] = {x, y};
        }
        cout << "Case " << t << ": " << BT(0, 0, 1) << endl;
    }
}