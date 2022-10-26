#include <bits/stdc++.h>
#define INF 1e9;
using namespace std;

struct Ecuacion {
    int j, i, Bij;
    Ecuacion(int a, int b, int c) { j = a; i = b; Bij = c; };
};

int n, m, k;
vector<int> D;
vector<Ecuacion> ecs;
vector<int> x;

bool satisface(const Ecuacion ec) {
    return  D[x[ec.j]] <= D[x[ec.i]] + ec.Bij;
}

bool fishburn() {
    x = vector<int>(n, m-1);
    bool cambio = true;
    while (cambio) {
        cambio = false;
        for (Ecuacion& ec: ecs) {
            if (!satisface(ec)) {
                int i = m - 1;
                for (; i >= 0 && D[i] > D[x[ec.i]] + ec.Bij; --i);
                if (i == -1) {
                    return false;
                }
                x[ec.j] = i;
                cambio = true;
            }
        }
    }
    return true;
}

int main() {
    int t; cin >> t;
    while (cin >> k >> n >> m) {
        ecs.clear(); x.clear(); D.clear();
        for (int i = 0; i < k; ++i) {
            int a, b, c; cin >> a >> b >> c;
            ecs.push_back(Ecuacion(a - 1, b - 1, c));
        }
        for (int i = 0; i < m; ++i) {
            int d; cin >> d;
            D.push_back(d);
        }
        if (fishburn()) {
            cout << x[0] + 1;
            for (int i = 1; i < n; ++i) {
                cout << " " << x[i] + 1;
            }
            cout << endl;
        } else {
            cout << "insatisfactible" << endl;
        }
    }
}