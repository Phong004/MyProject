#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int BinSearch(vector<int> a, int first, int last, int x) {
    sort (a.begin(), a.end());
    int l=first, r=last, mid = (l+r)/2;
    if (l <= r) {
        if (a[mid] < x) return BinSearch(a, mid + 1, last, x);
        else return BinSearch(a, first, mid - 1, x);
    }
    return a[l] == x ? l : -1;
}
//O(log(n))

vector<int> createVectorB(vector<int> a) {
    int n = a.size();
    vector<int> result(n);
    result[0] = a[0];
    for (int i=1; i<n; i++) {
        result[i] = result[i-1] + a[i];
    }
    return result;
}
//O(n)

void printResult(vector<int> a, int first, int last) {
    for (int i = first; i <= last; i++) {
        cout << a[i] << " ";
    }
}
//O(n)

bool solved (vector<int> a, vector<int> b, int s) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (b[i] == s) {
            printResult(a, 0, i);
            return 1;
        }
        else if (b[i] > s) {
            int index = BinSearch(b, 0, n-1, b[i]-s);
            if (index != -1) {
                printResult(a, index+1, i);
                return 1;
            }
        }
    }
    return 0;
}

int main () {
    #ifndef ONLINE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //O(n)
    vector<int> b = createVectorB(a);
    int s; cin >> s;

    if (!solved(a, b, s)) cout << -1;
    return 0;
}
//O(nlog(n))