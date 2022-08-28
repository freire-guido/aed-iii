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

pair<int, int> cc(int i, int c) {
    if (c <= 0) {
        return {0, 0};
    } else if (i == -1) {
        return {1e9, 1e9};
    }
    else {
        pair<int, int> b = {B[i], 1};
        return mejor(b + cc(i-1, c - B[i]), cc(i-1, c));
    }
}

int main () {
    cin >> c;
    cin >> n;
    B.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
    }
    pair<int, int> res = cc(n-1, c);
    cout << res.first << ' ' << res.second;
    return 0;
}