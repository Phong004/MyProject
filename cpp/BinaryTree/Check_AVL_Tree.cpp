#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* pLeft;
    Node* pRight;
};
typedef struct Node *node;

node newNode(int data) {
    node p = new Node();
    p->data = data;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

void treeInsert(node &t, int data) {
    if (t == NULL) t = newNode(data);
    else if (data < t->data) treeInsert(t->pLeft, data);
    else treeInsert(t->pRight, data);
}

int height(node t) {
    if (t == NULL) return -1;
    if (t->pLeft == NULL && t->pRight == NULL) return 0;
    return max(height(t->pLeft), height(t->pRight)) + 1;
}

string isAVL_Tree(node t) {
    if (t == NULL) return "true";
    if (abs(height(t->pLeft)-height(t->pRight)) > 1) return "false";
    else return "true";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    node t = NULL;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        treeInsert(t, x);
    }
    cout << isAVL_Tree(t);
}