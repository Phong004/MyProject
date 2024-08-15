#include <iostream>
#include <vector>
using namespace std;

int sort(vector<int>& a, int l, int r) {
    int i = l - 1, j = r + 1;
    int x = a[l];
    while (i < j) {
        do ++i; while (a[i] < x);
        do --j; while (a[j] > x);
        if ( i < j) swap (a[i], a[j]);
    }
    return j;
}

void quickSort(vector<int>& a, int l, int r) {
    if (l < r) {
        int j = sort(a, l, r);
        quickSort(a, l, j);
        quickSort(a, j + 1, r);
    }
}

int solve(vector<int> a, int k) {
    int cnt = 1;
    for (int i = 1; i < a.size(); i++) {
        if (a[i] - a[i - 1] > k) ++cnt;
    }
    return cnt;
}

int main() {
    int n, k;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> k;
    quickSort(a, 0, n - 1);
    cout << solve(a, k);
    return 0;
}