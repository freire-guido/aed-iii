#include "../algo3.h"
using namespace std;

vector<int> ady[100];
int N;
int dist[100][100];

struct Estado {
    int v, p, d;
    Estado(int a, int b, int c) { v = a; p = b; c = d; };
    bool operator>(const Estado& s) const { return d > s.d; };
};

int dijkstra() {
    for (int i = 0; i < N; ++i) { dist[i][0] = INF; dist[i][1] = INF};
    priority_queue<Estado, vector<Estado>, greater<Estado>> cp;
    cp.push(Estado(0, 0, 0));

    while (!cp.empty()) {
        Estado e = cp.top(); cp.pop();
        for (auto v : ady[e.v]) {
            if (dist[v][(e.p + 1) % 2] > e.d + 1) {
                dist[v][(e.p + 1) % 2] = e.d + 1;
                cp.push(Estado(v, (e.p + 1) % 2, e.d + 1));
            }
        }
    }
}