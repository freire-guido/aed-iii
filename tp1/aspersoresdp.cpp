#include <bits/stdc++.h>
using namespace std;

int n, l, w;
vector<vector<int>> M;

double a(int i) { return M[i][0] - sqrt(pow(M[i][1], 2) - pow(M[0][1], 2) / 4); }

double aComp(int p, int r) { return p - sqrt(pow(r, 2) - pow(r, 2) / 4); }

double b(int i) { return M[i][0] + sqrt(pow(M[i][1], 2) - pow(M[0][1], 2) / 4); }

bool comp(const vector<int>& a, const vector<int>& b) {
    return aComp(a[0],a[1]) < aComp(b[0],b[1]);
}

bool dejansinregar(int i, int k) {
    if (k == -1) {
        return a(i) > 0.00001;
    } else if (i==n-1){
        return a(i) > b(k) or b(i) < l;
    } else {
        return a(i) > b(k);
    }
}

int BT(int i, int k) {
    if (i == M.size() && b(k) >= l) {
        return 0;
    } else if(i == M.size() && b(k) < l) {
        return 1e9;
    } else {
        if (dejansinregar(i, k)) {
            return 1e9;
        } else {
            return min(BT(i + 1, k), M[i][2] + BT(i + 1, i));
        }
    }
}

int main() {
    cin >> n >> l >> w;
    M.resize(n);
    for (int i = 0; i < n; ++i) {
        M[i].resize(3);
        cin >> M[i][0] >> M[i][1] >> M[i][2];
    }
    sort(M.begin(), M.end(), &comp);
    for (int i = 0; i < n; ++i) {
        cout << M[i][0] << " " << M[i][1] << " " << M[i][2] << endl;
    }
    cout << BT(0, -1);
}