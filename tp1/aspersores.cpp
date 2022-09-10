#include "../algo3.h"
using namespace std;

vector<pair<int, int>> asper;
int jult;
int n;
int l;
int w;

bool cubrio() {

}

int aspersores(int k, int j) {
    int acum = 0;
    for (k = 0; k < l; k + asper[j].first + asper[j].second) {
        for (int i = j; i < n; ++i) {
            if (asper[i].first - asper[i].second < k && asper[i].second > asper[j].second) {
                j = i;
            }
        }
        if (k != 0 && !(cubrio)) { //guardas
            return -1;
        }
        jult = j;
        ++acum;
    }
    return acum;
}

int main() {
    
}