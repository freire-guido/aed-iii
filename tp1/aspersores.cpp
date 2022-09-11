#include "../algo3.h"
using namespace std;

vector<pair<int, int>> asper;
int n;
int l;
int w;

bool cubrio(int i, float k) {
    return (pow(asper[i].second, 2) - pow(asper[i].first - k, 2)) >= pow(w, 2) / 4;
}

int aspersores() {
    int j = 0;
    int acum = 0;
    for (float k = 0; k < l; k = asper[j].first + sqrt(pow(asper[j].second, 2) - pow(w, 2) / 4)) {
        int i = j;
        for (; i < n; ++i) {
            if (cubrio(i, k) && asper[i].first + asper[i].second >= asper[j].first + asper[j].second) {
                j = i;
            }
        }
        if (!cubrio(j, k)) {
            return -1;
        }
        ++acum;
    }
    return acum;
}

int main() {
    while (cin >> n >> l >> w) {
        asper.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> asper[i].first >> asper[i].second;
        }
        sort(asper.begin(), asper.end());
        cout << aspersores() << endl;
    }
}