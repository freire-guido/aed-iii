#include <bits/stdc++.h>
using namespace std;

int n, l, w;
vector<vector<int>> A;
vector<vector<int>> M;

float a(int i) {
    return A[i][0] - sqrt(pow(A[i][1], 2) - pow(w, 2) / 4);
}

float b(int i) {
    return A[i][0] + sqrt(pow(A[i][1], 2) - pow(w, 2) / 4);
}

bool comp(const vector<int>& a, const vector<int>& b) {
    return a[0] - sqrt(pow(a[1], 2) - pow(w, 2) / 4) < b[0] - sqrt(pow(b[1], 2) - pow(w, 2) / 4);
}

bool dejasinregar(int i, int k) {
    if (i == n + 1) return b(k) < l;
    return a(i) > b(k);
}

int DP(int i, int k) {
    if (M[i][k] == -1) {
        if (b(k) >= l) {
            M[i][k] = 0;
        } else if (dejasinregar(i, k)) {
            M[i][k] = 99;
        } else {
            M[i][k] = min(DP(i + 1, k), A[i][2] + DP(i + 1, i));
        }
    }
    return M[i][k];
}

int main() {
    while (cin >> n >> l >> w) {
        M.resize(n + 2);
        M[0] = vector<int>(n + 2, -1);
        M[n + 1] = vector<int>(n + 2, -1);
        A.resize(n + 1);
        A[0] = {0, w, 0};
        for (int i = 1; i < n + 1; ++i) {
            M[i] = vector<int>(n + 2, -1);
            A[i].resize(3);
            cin >> A[i][0] >> A[i][1] >> A[i][2];
        }

        sort(A.begin() + 1, A.end(), &comp);
        int res = DP(0, 0);
        cout << (res >= 99 ? -1 : res) << endl;
    }
}