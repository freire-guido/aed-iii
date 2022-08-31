#include "../algo3.h"
using namespace std;

int n;
vector<int> w;
vector<int> s;

int BU(int Sm) {
    Sm++;
    matrix<int> M(n);
    M[n - 1].resize(Sm);
    for (int c = 0; c < Sm; ++c) {
        M[n - 1][c] = c - w[n - 1] >= 0;
    }
    for (int i = n - 2; i >= 0; --i) {
        M[i].resize(Sm);
        for (int c = 0; c < Sm; ++c) {
            int con = min(c - w[i], s[i]) < 0 ? -1e9 : 1 + M[i + 1][min(c - w[i], s[i])];
            int sin = M[i + 1][c];
            M[i][c] = max(con, sin);
        }
    }
    return M[0][Sm - 1];
}

int BT(int i, int c) {
    if (c == 0 || i == n) {
        return 0;
    } else if (c < 0) {
        return INT_MIN;
    } else {
        return max(1 + BT(i + 1, min(s[i], c - w[i])), BT(i + 1, c));
    }
}

int main() {
    cin >> n;
    matrix<int> M(n);
    w.resize(n); s.resize(n);
    int Wm = 0;
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        if (w[i] > Wm) {
            Wm = w[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        M[i].resize(Wm);
    }
    cout << BU(Wm);
}