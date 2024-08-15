#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& v, int l, int m, int r) {
    vector<int> a(v.begin() + l, v.begin() + m+1);
    vector<int> b(v.begin() + m+1, v.begin() + r + 1);
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            v[l] = a[i];
            i++; l++;
        }
        else {
            v[l] = b[j];
            j++; l++;
        }
    }
    while (i < a.size()) {
        v[l] = a[i];
        i++; l++;
    }
    while (j < b.size()) {
        v[l] = b[j];
        j++; l++;
    }
}

void mergeSort(vector<int>& v, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(v, l, m);
        mergeSort(v, m+1, r);
        merge(v, l, m, r);
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
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    mergeSort(v, 0, n-1);
    for (int x: v) cout << x << " ";
}