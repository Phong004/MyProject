#include <iostream>
#include <vector>
using namespace std;

int qSort(vector<int>& v, int l, int r) {
    int i = l - 1, j = r + 1;
    int pivot = v[l];
    while (i < j) {
        do ++i; while (v[i] < pivot);
        do --j; while (v[j] > pivot);
        if (i < j) swap(v[i], v[j]);
    }
    return j;
}

void quickSort(vector<int>& v, int l, int r) {
    if (l < r) {
        int p = qSort(v, l, r);
        quickSort(v, l, p);
        quickSort(v, p + 1, r);
    }
}

void solve (vector<int>& a, vector<int>& b) {
    int k = 0;
    int n = a.size();
    vector<int>::iterator ita = a.begin();
    while (ita!= a.end()) {
        if (*ita != 0) 
            b.push_back(*ita);
    }
    quickSort(b, 0, b.size() - 1);
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] < 0) {
            a[i] = b[k];
            ++k;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0) {
            a[i] = b[k];
            ++k;
        }
    }
}

int main() {
    freopen ("../input.txt", "w", stdout);
    int n; cin >> n;
    int t = -n;
    srand(time(NULL));
    for (int i = 0; i < n; i++){
        cout << t + rand()%(n-t+1) << " ";
    }
    fclose (stdout);
    freopen ("../input.txt", "r", stdin);
    freopen ("../output.txt", "w", stdout);
    vector<int> a(n);
    vector<int> b;
    solve(a, b);
    for (auto x : a) cout << x << " ";
}