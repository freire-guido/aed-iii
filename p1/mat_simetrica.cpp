#include<bits/stdc++.h>
using namespace std;

int n; int k;
int mejorS = 0;
vector<int> mejorI;

int suma(vector<vector<int>> M, vector<int> I, int i = 0) {
    if (i > I.size()) {
        return 0;
    } else {
        int sin = suma(M, I, i+1);
        I.push_back(i);
        int con = suma(M, I, i+1);
        return sin + con;
    }
}

void BT(vector<vector<int>> M, vector<int> I, int i = 0) {
    if (I.size() == k) {
        int s = suma(M, I);
        if (s >= mejorS) {
            mejorI = I;
            mejorS = s;
        }
    } else if (I.size() < k) {
        for (int j = i; j < n; ++j) {
            BT(M, I, j + 1);
            I.push_back(j);
            BT(M, I, j + 1);
        }
    }
}

int main () {
    cin >> n;
    cin >> k;
    vector<vector<int>> M(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            M[i].resize(n);
            cin >> M[i][j];
        }
    }
    BT(M, {});
    return 0;
}