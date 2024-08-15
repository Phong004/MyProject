#include <iostream>
#include <vector>
using namespace std;

int qSort(vector<int>& a, int l, int r) {
    int i = l-1, j = r+1;
    int x = a[l];
    while (i < j) {
        do ++i; while (a[i] < x);
        do --j; while (a[j] > x);
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

void input() {
    #ifndef ONLINE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int main() {
    input();
    int n; cin >> n;
    vector<int> a (n);
    srand(time(NULL));
    for (int i = 0; i < n; i++) a[i] = rand() % n;
    quickSort(a, 0, a.size() - 1);
    for (int x: a) cout << x << " ";
}