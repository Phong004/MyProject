#include <iostream>
#include <queue>
using namespace std;

int main() {
    #ifndef ONLINE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif

    queue<string> q;
    string s1, s2;
    
    cin >> s1 >> s2;

    q.push(s1);
    q.push(s2);
    
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}