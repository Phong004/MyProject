#include <iostream>
#include <vector>
using namespace std;

int qSort(vector<int> &a, int l, int r) {
    int i = l-1, j = r+1;
    int pivot = a[l];
    while (i < j) {
        do i++; while (a[i] > pivot);
        do j--; while (a[j] < pivot);
        if (i < j) swap(a[i], a[j]);
    }
    return j;
}

void quickSort(vector<int> &a, int l, int r) {
    if (l < r) {
        int p = qSort(a, l, r);
        quickSort(a, l, p);
        quickSort(a, p+1, r);
    }
}

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n; cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push_back(x);
    }
    quickSort(a, 0, n-1);
    
    int cnt = 1;
    int temp = a[0];
    for (int i = 1; i < n; i++) {
        temp -= 1;
        if (temp >= 0) ++cnt;
        else break;
    }
    cout << cnt;
    return 0;
}