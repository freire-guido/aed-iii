#include "../algo3.h"
using namespace std;

int m, n;
matrix<int> M;

int BT(int i, int j, int s) {
    if (s = m * n) {
        return 1;
    }
    if (!(0 <= i && i < m) || !(0 <= j && j < n)) {
        return 0;
    }
    if (M[i][j] != -1 && M[i][j] != s) {
        return 0;
    }
    M[i][j] = s;
    int acum = 0;
    ++s;
    acum += BT(i + 1, j, s);
    acum += BT(i - 1, j, s);
    acum += BT(i, j + 1, s);
    acum += BT(i, j - 1, s);
    M[i][j] = -1;
    return acum;
}


int main() {
    while (true) {
        cin >> m;
        cin >> n;
        if (m == 0 && n == 0) return 1;

        M.resize(m);
        for (int i = 0; i < m; ++i) {
            M[i] = vector<int>(n, -1);
        }
        M[0][0] = 1;
        M[0][1] = m*n;
        for (int i = 0; i < 3; ++i) {
            int x; cin >> x;
            int y; cin >> y;
            M[x][y] = (0.25*(i + 1)*m*n);
        }
        cout << M;
        cout << BT(0, 0, 1);
    }
}