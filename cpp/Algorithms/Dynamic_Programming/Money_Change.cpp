#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> c;

void moneyChanged(vector<int> v, int n, int m) {
    sort(v.begin(), v.end());
    c.assign(m, 1e9);
    c[0] = 1;
    for (int i=0; i< n; i++) {
        for (int j=0; j<= m; j++) {
            if (j - v[i] >= 0 && c[j - v[i]] != 1e9) {
                c[j] = min(c[j], c[j - v[i]]+1);
            }
        }
    }
    if (c[m] == 1e9) cout << 0;
    else cout << c[m];
}

int main() {
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int m; cin >> m;
    moneyChanged(a, n, m);
    return 0;
}