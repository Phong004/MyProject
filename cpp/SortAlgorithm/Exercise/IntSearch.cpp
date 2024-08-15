#include <iostream>
#include <vector>
using namespace std;

int qSort(vector<int>& a, int l, int r) {
    int pivot = a[l];
    int i = l - 1, j = r + 1;
    while (i < j) {
        do ++i; while (a[i] < pivot);
        do --j; while (a[j] > pivot);
        if (i < j) swap(a[i], a[j]);
    }
    return j;
}

void quickSort(vector<int>& a, int l, int r) {
    if (l < r) {
        int p = qSort(a, l, r);
        quickSort(a, l, p);
        quickSort(a, p + 1, r);
    }
}

bool binarySearch(vector<int> a, int l, int r, int x) {
    int m = (l+r)/2;
    while (l <= r) {
        if (a[m] == x) return true;
        else if (a[m] < x) l = m + 1;
        else r = m - 1;
        m = (l+r)/2;
    }
    return false;
}

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n; cin >> n;
    vector<int> a(n);
    srand(time(NULL));
    for (int i = 0; i < n; i++) a[i] = rand() % n*10;
    quickSort(a, 0, n - 1);
    int x = 0;
    while (binarySearch(a, 0, n - 1, x)) ++x;
    for (auto x: a) cout << x << " ";
    cout << endl;
    cout << x;
}