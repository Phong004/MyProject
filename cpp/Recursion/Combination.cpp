#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

void printScr(vector<int> v, int n) {
    for (int i=1; i<=n; i++) cout << v[i];
    cout << " ";
}

void combination(int n, int h, int k) {
    for (int i=v[h-1]+1; i <= n-(k-h); i++) {
        v[h] = i;
        if (k==h) printScr(v, k);
        else {
            combination(n, h+1, k);
        }
    }
}

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, k; cin >> n >> k;

    v.assign(n+1, 0);
    combination(n, 1, k);
}