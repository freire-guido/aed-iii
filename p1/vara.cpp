#include "../algo3.h"
using namespace std;

int l;
int n;
vector<int> C;
vector<int> L; // [0, 2, 4, 7, 10]

int DP(int i, int j, matrix<int>& M) {
    cout << "DP(" << i << ", " << j << ")" << endl;
    if (M[i][j] == 1e9) {
        for (int k = i; k < j; ++k) {
            M[i][j] = min(M[i][j], DP(i, k, M) + DP(k+1, j, M) + L[j] - L[i-1]);
        }
    }
    return M[i][j];
}

int BT(int i, int j) {
    bool corte = false;
    int mej = 1e9;
    for (int c = 0; c < C.size(); ++c) {
        if (i < C[c] && C[c] < j) {
            mej = min(mej, BT(i, C[c]) + BT(C[c], j) + j - i);
            corte = true;
        }
    }
    return corte ? mej : 0;
}

int main() {
    cin >> l;
    cin >> n;
    C.resize(n);
    L.resize(n + 2);
    L[0] = 0;
    L[L.size() - 1] = l;
    matrix<int> M(n + 2);
    for (int i = 0; i < n; ++i) {
        cin >> C[i];
        L[i+1] = C[i];
    }
    for (int i = 0; i < M.size(); ++i) {
        M[i] = vector<int>(M.size(), 1e9);
        M[i][i] = 0;
    }
    cout << DP(1, M.size() - 1, M) << endl;
}