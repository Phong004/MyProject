#include <iostream>
#include <vector>
using namespace std;

vector<int> a;
vector<int> res;

int qSort(vector<int> &a, int l, int r) {
    int pivot = a[l];
    int i = l-1, j = r + 1;
    while (i < j) {
        do i++; while (a[i] > pivot);
        do j--; while (a[j] < pivot);
        if (i < j) swap(a[i], a[j]);
    }
    return j;
}

void quick_sort(vector<int> &a, int a_start, int a_end) {
    if (a_start < a_end) {
        int p = qSort(a, a_start, a_end);
        quick_sort(a, a_start, p);
        quick_sort(a, p+1, a_end);
    }
}

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push_back(x);
    }
    quick_sort(a, 0, n-1);
    for (int i = 0; i < n; i++) {
        int temp = a[i] + i + 1;
        res.push_back(temp);
    }
    int ans = res[0];
    for (int i = 1; i < n; i++) {
        ans = max(ans, res[i]);
    }
    cout << ans;
}