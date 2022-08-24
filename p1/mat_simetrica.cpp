#include "../algo3.h"
using namespace std;

int n; int k;
int mejorS = 0;
vector<int> mejorI;

int sumarUlt(matrix<int> M, vector<int> I) {
    int s = 0;
    for (int i = 0; i < I.size() - 1; ++i) {
        s += M[i][I[I.size() - 1]];
    }
    return s;
}

void BT(matrix<int> M, vector<int> I, int i = 0, int s = 0) {
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

void BUDP(matrix<int> M, vector<int> I) {
    int s[n]{};
    
}

int main () {
    cin >> n;
    cin >> k;
    matrix<int> M(n); cin >> M;
    BUDP(M, {});
    cout << mejorS << endl;
    for (int i = 0; i < mejorI.size(); ++i) {
        cout << mejorI[i] + 1 << ", ";
    }
    return 0;
}