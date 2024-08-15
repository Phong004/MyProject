#include <iostream>
#include <vector>
using namespace std;

vector<int> c;

int findIndex () {
    int index = 0;
    for (int i = 1; i < c.size(); i++) {
        if (c[index] < c[i] ) {
            index = i;
        }
    }
    return index;
}

void Subsequence (vector<int> v, int n) {
    c.push_back(1);
    for (int i=1; i <= n; i++) {
        if (v[i] >= v[i-1]) {
            c.push_back(c[i-1] + 1);
        }
        else c.push_back(1);
    }
    int index = findIndex ();
    for (int i = index-c[index]+1; i <= index ; i++) cout << v[i] << " "; 
}

int main() {
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    Subsequence(v, n-1);
    return 0;
}