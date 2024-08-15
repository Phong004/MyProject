#include <iostream>
#include <vector>
using namespace std;

vector<bool> v;
vector<int> x;

void printScreen(vector<int> a) {
    //freopen ("output.txt", "w", stdout);
    for (auto x: a) cout << x;
    cout << " ";
}

void permutation(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (v[i]) {
            x[k-1] = i;
            if (k == n) printScreen(x);
            else {
                v[i] = false;
                permutation(k + 1, n);
                v[i] = true;
            }
        }
    }
}

int main() {
    int n; cin >> n;
    v.assign(n+1, true);
    x.assign(n, 0);
    permutation(1,n);
}