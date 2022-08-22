#include<bits/stdc++.h>
using namespace std;

int n; int k;
int mejorS = 0;
vector<int> mejorI;

int sumarUlt(vector<vector<int>> M, vector<int> I) {
    int s = 0;
    for (int i = 0; i < I.size() - 1; ++i) {
        s += M[i][I[I.size() - 1]];
    }
    return s;
}

void BT(vector<vector<int>> M, vector<int> I, int i = 0, int s = 0) {
    if (I.size() == k && s >= mejorS) {
        mejorI = I;
        mejorS = s;
    } else if (I.size() < k) {
        for (int j = i; j < n; ++j) {
            BT(M, I, j + 1, s);
            I.push_back(j);
            BT(M, I, j + 1, s + sumarUlt(M, I));
        }
    }
}

void BUDP(vector<vector<int>> M, vector<int> I) {
    int s[k]{};
    for (int i = 0; i < k; i++) {
        for (int j = i; j < n; j++) {
            I.push_back(j);
            mejorS = max(mejorS, s[i] + sumarUlt(M, I)); //memoizar I parciales
            I.pop_back();
        }
        s[i] = mejorS;
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
    BUDP(M, {});
    cout << mejorS << endl;
    for (int i = 0; i < mejorI.size(); ++i) {
        cout << mejorI[i] + 1 << ", ";
    }
    return 0;
}