#include "../algo3.h"
using namespace std;

int n;
vector<int> w;
vector<int> s;

int BU(int Sm) {
    int Sm = 0;
    for (int i = n; i >= 0; --i) {
        for (int j = 0; j <)
    }
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
    int Sm = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        if (s[i] > Sm) {
            Sm = s[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        M[i].resize(Sm);
        cin >> w[i];
    }
    cout << DP(0, INT_MAX);
}