#ifndef BUBBLE
#define BUBBLE
#include <iostream>
#include <vector>
#include <algorithm>
#endif
using namespace std;

void openFile() {
    #ifndef ONLINE
    #define ONLINE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

void BubbleSort(vector<int> &a, int first, int last) {
    for (int i = first; i < last; i++) {
        for (int j = first; j < last-1-i; j++) {
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
            }
        }
    }
}

void outputSort(vector<int> a) {
    for (int x: a) cout << x << " ";
}

#ifndef BUBBLE
#define BUBBLE
int main() {
    openFile();
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    BubbleSort(a, 0, n);
    outputSort(a);
}
#endif