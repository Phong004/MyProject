#include <iostream>
#include <vector>
using namespace std;

void init(int n) {
    freopen ("../input.txt", "w", stdout);
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        cout << -n + rand() % (n-(-n)) << " ";
    }
    cout << endl;
    fclose(stdout);
}

void input(vector<int> &a, vector<int> &b) {
    freopen ("../input.txt", "r", stdin);
    for (int i = 0; i < a.size(); i++) {
        cin >> a[i];
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != 0) {
            b.push_back(a[i]);
        }
    }
    fclose(stdin);
}

int qSort(vector<int> &v, int l, int r) {
    int i = l-1, j = r+1;
    int pivot = v[l];
    while (i < j) {
        do i++; while (v[i] < pivot);
        do j--; while (v[j] > pivot);
        if (i < j) swap(v[i], v[j]);
    }
    return j;
}

void quickSort(vector<int> &v, int l, int r) {
    if (l < r) {
        int m = qSort(v, l, r);
        quickSort(v, l, m);
        quickSort(v, m+1, r);
    }
}

void output(vector<int> v) {
    freopen("../output.txt", "w", stdout);
    for (auto x: v) {
        cout << x << " ";
    }
    fclose(stdout);
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b;
    init(n);
    input(a, b);
    quickSort(b, 0, b.size()-1);
    int cnt = 0;
    for (int i=n-1; i >= 0; --i) {
        if (a[i] < 0) {
            a[i] = b[cnt];
            ++cnt;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0) {
            a[i] = b[cnt];
            ++cnt;
        }
    }
    output(a);
    return 0;
}