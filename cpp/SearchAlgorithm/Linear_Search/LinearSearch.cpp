#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x; cin >> x;
    for (auto i = a.begin(); i != a.end(); i++) {
        if (*i == x) {
            cout << i - a.begin() << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}