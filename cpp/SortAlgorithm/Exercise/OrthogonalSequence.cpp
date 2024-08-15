#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool binSearch(vector<int> a, int x) {
    int l = 0, r = a.size() - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (a[mid] < x) l = mid + 1; 
        else r = mid;
    }
    return a[l] == x ? 1 : 0;
}

void merge (vector<int>& v, int l, int m, int r) {
    vector<int> a(v.begin() + l, v.begin() + m + 1);
    vector<int> b(v.begin() + m + 1, v.begin() + r + 1);
    
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            v[l] = a[i];
            ++i; ++l;
        }
        else {
            v[l] = b[j];
            ++j; ++l;
        }
    }
    while (i < a.size()) {
        v[l] = a[i];
        ++i; ++l;
    }
    while (j < b.size()) {
        v[l] = b[j];
        ++j; ++l;
    }
}

void mergeSort(vector<int>& v, int l, int r) {
    int m = (l+r)/2;
    if (l < r) {
        mergeSort(v, l, m);
        mergeSort(v, m+1, r);
        merge(v, l, m, r);
    }
}

void input() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    
}

int main() {
    input();
    int n; cin >> n;
    int c = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    mergeSort(a, 0, n-1);
    for (int i = 0; i <= sqrt(a.back()); i++) {
        if (binSearch(a, i*i)) {
            cout << i*i << " ";
            c++;
        }
    }
    if (c == 0) cout << "NULL";
}