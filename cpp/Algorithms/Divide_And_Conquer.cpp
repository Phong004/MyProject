#include <iostream>
#include <vector>
using namespace std;

int count(vector<int> &v, int l, int r, int x) {
    if (l == r) 
        if (v[l] == x) return 1;
        else return 0;
    int m = (l+r)/2;
    return count(v, l, m, x) + count(v, m+1, r, x);
}

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int k; cin >> k;
    cout << count(v, 0, n-1, k);
    return 0;   
}