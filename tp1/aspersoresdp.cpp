#include <bits/stdc++.h>
using namespace std;

int n, l, w;
vector<vector<int>> M;

float a(int i) {
    return M[i][0] - sqrt(pow(M[i][1], 2) - pow(w, 2) / 4);
}

float b(int i) {
    return M[i][0] + sqrt(pow(M[i][1], 2) - pow(w, 2) / 4);
}

bool comp(const vector<int>& a, const vector<int>& b) {
    return a[0] - sqrt(pow(a[1], 2) - pow(w, 2) / 4) < b[0] - sqrt(pow(b[1], 2) - pow(w, 2) / 4);
}

bool dejasinregar(int i, int k) {
    if (i == n + 1) return b(k) < l;
    return a(i) > b(k);
}

int BT(int i, int k) {
    if (b(k) >= l) {
        return 0;
    } else if (dejasinregar(i, k)) {
        return 1e9;
    } else {
        return min(BT(i + 1, k), M[i][2] + BT(i + 1, i));
    }
}



int main() {
    while (cin >> n >> l >> w) {
        M.resize(n + 1);
        M[0] = {0, w, 0};
        for (int i = 1; i < n + 1; ++i) {
            M[i].resize(3);
            cin >> M[i][0] >> M[i][1] >> M[i][2];
        }
        sort(M.begin() + 1, M.end(), &comp);
        cout << BT(1, 0);
    }
}