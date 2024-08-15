#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int frequency(vector<int> a, int x) {
    int count = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == x) {
            count++;
        }
    }
    return count;
}

void input() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    srand(time(NULL));
}

int main() {
    input();
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = rand() % n*100;
    //for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (a[i] != a[i - 1])
        cout << a[i] << " " << frequency(a, a[i]) << "; ";
    }
}