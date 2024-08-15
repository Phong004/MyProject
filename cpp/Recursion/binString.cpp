#include <iostream>
#include <vector>
using namespace std;

void binString(int n, string s) {
    if (n == 0) {
        cout << s << " ";
        return;
    }
    for (int i=0; i<=1; i++) {
        binString (n-1, s+ char(i+'0'));
    }
}

int main () {
    freopen ("../input.txt", "r", stdin);
    freopen ("../output.txt", "w", stdout);
    int n; cin >> n;
    binString(n, "");
}