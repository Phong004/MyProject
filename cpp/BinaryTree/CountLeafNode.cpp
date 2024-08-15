#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* pLeft;
    Node* pRight;
};
typedef struct Node* node;

node newNode(int data) {
    node p = new Node();
    p->data = data;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

void insert(node &t, int x) {
    if (t == NULL) t = newNode(x);
    else {
        if (x < t->data) insert(t->pLeft, x);
        else insert(t->pRight, x);
    }
}

int countLeafs(node t) {
    if (t == NULL) return 0;
    if (t->pLeft == NULL && t->pRight == NULL) return 1;
    return countLeafs(t->pLeft) + countLeafs(t->pRight);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    node t = NULL;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        insert(t, x);
    }
    cout << countLeafs(t) << endl;
    return 0;
}