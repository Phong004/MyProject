#include <iostream>
#include <vector>
using namespace std;

int main() {
    size_t n; cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x; cin >> x;
    int cnt = 0;
    for (size_t i = 0; i < n; i++) {
        if (a[i] == x) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}