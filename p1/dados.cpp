#include "../algo3.h"
using namespace std;

int k;

int DP(int n, int s, matrix<int>& M) {
    if (M[n][s] == -1) {
        int acum = 0;
        for (int i = 1; i <= min(s, k); ++i) {
            acum += DP(n-1, s-i, M);
        }
        M[n][s] = acum;
    }
    return M[n][s];
}

int main() {
    int n; cin >> n;
    int s; cin >> s;
    cin >> k;
    matrix<int> M(n + 1);
    M[0] = vector(s + 1, 0);
    M[0][0] = 1;
    for (int i = 1; i < n + 1; ++i) {
        M[i] = vector(s + 1, -1);
    }
    cout << M;
    cout << DP(n, s, M);
}