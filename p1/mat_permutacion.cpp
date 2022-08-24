#include "../algo3.h"
using namespace std;

int n;
int mejorS = INT_MAX;
vector<int> mejorI = {0};

void atrasar(vector<int>& v, int i) {
    int t = v[(i - 1) % v.size()];
    v[(i - 1) % v.size()] = v[i];
    v[i] = t;
}

void BT(const matrix<int>& M, vector<int> I, int s = 0) {
    if (I.size() == n && s < mejorS) {
        mejorS = s;
        mejorI = I;
    }
    else if (I.size() < n) {
        I.push_back(I.size());
        for (int i = I.size() - 1; i > 2; --i) {
            BT(M, I, s - M[i-1][i+1] + M[i-1][i] + M[i][(i + 1) % I.size()]);
            atrasar(I, i);
        }
        BT(M, I, s + M[0][1] + M[1][2 % I.size()]);
    }
}

int main() {
    cin >> n;
    matrix<int> M(n); cin >> M;
    BT(M, mejorI);
    cout << mejorI << endl;
    cout << mejorS;
}