#include "../algo3.h"
using namespace std;

int c;
int n;
vector<int> B;

pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
    return {a.first + b.first, a.second + b.second};
}

pair<int, int> mejor(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first || (a.first == b.first && a.second <= b.second)) {
        return a;
    }
    return b;
}

pair<int, int> DP(int i, int c, matrix<pair<int, int>>& M) {
    if (c <= 0) {
        return {0, 0};
    }
    else if (i == -1) {
        return {1e9, 1e9};
    }
    else {
        pair<int, int> s = {B[i], 1};
        M[i][c-1] = mejor(s + DP(i-1, c - B[i], M), DP(i-1, c, M));
    }
    return M[i][c-1];
}

int main () {
    cin >> c;
    cin >> n;
    B.resize(n);
    matrix<pair<int, int>> M(n);
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
        M[i] = vector<pair<int, int>>(c, {-1, -1});
        M[i][0] = {0, 0};
    }
    pair<int, int> res = DP(n-1, c, M);
    cout << res.first << ' ' << res.second;
    return 0;
}