#include "../algo3.h"
using namespace std;

int m, n;
matrix<int> M;
pair<int, int> C[5];
int c = 0;

bool encerrada(int x1, int x2) {
    return (0 <= x1 && x1 < m && 0 <= x2 && x2 < n && M[x1][x2] == -1) && (
        (0 > x1 + 1 || x1 + 1 >= m || M[x1 + 1][x2] != -1) &&
        (0 > x1 - 1 || x1 - 1 >= m || M[x1 - 1][x2] != -1) &&
        (0 > x2 + 1 || x2 + 1 >= n || M[x1][x2 + 1] != -1) &&
        (0 > x2 - 1 || x2 - 1 >= n || M[x1][x2 - 1] != -1));
}

bool encierra(int x1, int x2) {
    return ((0 > x1 + 1 || x1 + 1 >= m || M[x1 + 1][x2] != -1) &&
        (0 > x1 - 1 || x1 - 1 >= m || M[x1 - 1][x2] != -1) &&
        !(0 > x2 + 1 || x2 + 1 >= n || M[x1][x2 + 1] != -1) &&
        !(0 > x2 - 1 || x2 - 1 >= n || M[x1][x2 - 1] != -1)) ||
        (!(0 > x1 + 1 || x1 + 1 >= m || M[x1 + 1][x2] != -1) &&
        !(0 > x1 - 1 || x1 - 1 >= m || M[x1 - 1][x2] != -1) &&
        (0 > x2 + 1 || x2 + 1 >= n || M[x1][x2 + 1] != -1) &&
        (0 > x2 - 1 || x2 - 1 >= n || M[x1][x2 - 1] != -1));
}

int manhattan(int x1, int x2, int y1, int y2) {
    return abs(x1 - y1) + abs(x2 - y2);
}

int BT(int i, int j, int s) {
    //podas
    if (!(0 <= i && i < m) || !(0 <= j && j < n)) return 0;
    if (M[i][j] != -1 && M[i][j] != s) return 0;
    if (manhattan(i, j, C[c].first, C[c].second) > M[C[c].first][C[c].second] - s) return 0;
    if (encierra(i, j)) return 0;
    if (encerrada(i + 1, j) || encerrada(i - 1, j) || encerrada(i, j + 1) || encerrada(i, j - 1) ||
        encerrada(i + 1, j + 1) || encerrada(i + 1, j - 1) || encerrada(i - 1, j + 1) || encerrada(i - 1, j - 1)) return 0;
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
        if (m == 0 && n == 0) return 1;
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