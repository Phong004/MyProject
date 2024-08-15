#include <iostream>
#include <vector>
using namespace std;
int main () {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int min = 0, max = n-1;
    for (int i = 0; i < n; i++) {
        if (a[i] < a[min]) {
            min = i;
            break;
        }
    }
    for (int j = n-1; j >= 0; j--) {
        if (a[j] > a[max]) {
            max = j;
            break;
        }
    }
    int temp = a[min];
    a[min] = a[max]; a[max] = temp;
    for (auto x: a) { 
        cout << x << " ";
    } 
}