#include "../algo3.h"
using namespace std;

int l;
int n;
vector<int> C;

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
    for (int i = 0; i < n; ++i) {
        cin >> C[i];
    }
    cout << BT(0, l);
}