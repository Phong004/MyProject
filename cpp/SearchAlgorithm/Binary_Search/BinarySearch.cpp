#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int BinarySearch(vector<int> a, int first, int last, int x) {
    sort(a.begin(), a.end());
    auto l = first, r = last;
    while (l != r) {
        auto mid = (l + r) / 2;
        if (a[mid] < x) l = mid + 1;
        else r = mid;
    }
    return a[l] == x? l : -1;
}

int main() {
    #ifndef ONLINE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x; cin >> x;
    cout << BinarySearch(a, 0, n-1, x);
    return 0;
}