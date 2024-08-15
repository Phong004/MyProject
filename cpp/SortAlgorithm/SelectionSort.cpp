#include <iostream>
#include <vector>
using namespace std;

void SelecSort(vector<int>& a, int a_start, int a_end) {
    for (int i=a_start; i<a_end; i++) {
        int min = i;
        for (int j=i+1; j<a_end; j++) {
            if (a[min] > a[j]) {
                min = j;
            }
        }
        if (a[min] < a[i]) swap(a[min], a[i]);
    }
}

int main() {
    #ifndef ONLINE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    SelecSort(a, 0, n);
    for (int i=0; i<n; i++) cout << a[i] << " ";
}