#include "../algo3.h"
using namespace std;

int m, n;
matrix<int> M;
pair<int, int> C[5];
int c = 0;

int manhattan(int x1, int x2, int y1, int y2) {
    return abs(x1 - y1) + abs(x2 - y2);
}

int BT(int i, int j, int s) {
    if (!(0 <= i && i < m) || !(0 <= j && j < n)) {
        return 0;
    }
    if (M[i][j] != -1 && M[i][j] != s) {
        return 0;
    }
    if (s == m * n) {
        return 1;
    }
    if (manhattan(i, j, C[c].first, C[c].second) > M[C[c].first][C[c].second] - s) {
        int t = M[i][j];
        M[i][j] = s;
        cout << M << manhattan(i, j, C[c].first, C[c].second) << " > " << M[C[c].first][C[c].second] - s << ' ' << c << endl << endl;
        M[i][j] = t;
        return 0;
    }
    int pre = M[i][j];
    if (pre == s) {
        ++c;
        // cout << pre << endl;
    }
    M[i][j] = s;
    int acum = 0;
    ++s;
    acum += BT(i + 1, j, s);
    acum += BT(i - 1, j, s);
    acum += BT(i, j + 1, s);
    acum += BT(i, j - 1, s);
    M[i][j] = pre;
    if (pre == s) {
        --c;
    }
    return acum;
}


int main() {
    int t = 0;
    while (true) {
        ++t;
        cin >> m;
        cin >> n;
        if (m == 0 && n == 0) return 1;

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
        cout << M << endl;
        BT(0, 0, 1);
        // cout << "Case " << t << ": " << BT(0, 0, 1) << endl;
    }
}