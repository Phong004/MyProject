#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int InterSearch(vector<int> a, int first, int last, int x) {
    sort(a.begin(), a.end());
    int l = first, r = last;
    if (a[l] != a[r] && a[l] <= x && x <= a[r]) {
        int m = l + ((r - l) * (x - a[l]))/(a[r] - a[l]);
        if (a[m] < x) return InterSearch(a, m + 1, r, x);
        else if (a[m] > x) return InterSearch(a, l, m - 1, x);
        else if (m > 0 && a[m-1] == x) return InterSearch(a, l, m - 1, x);
        else return m;
    }
    if (a[l] == x) return l;
    return -1;
}

int main() {
    #ifndef ONLINE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int x; cin >> x;
    cout << InterSearch(a, 0, n - 1, x) << endl;
    return 0;
}