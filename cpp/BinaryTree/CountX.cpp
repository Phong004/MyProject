#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *pLeft;
    Node *pRight;
};
typedef struct Node *node;

node newNode(int data) {
    node temp = new Node;
    temp->data = data;
    temp->pLeft = NULL;
    temp->pRight = NULL;
    return temp;
}

node treeInsert(node t, int data) {
    if (t == NULL) t = newNode(data);
    else if (data < t->data) t->pLeft = treeInsert(t->pLeft, data);
    else t->pRight = treeInsert(t->pRight, data);
    return t;
}

node turnLeft(node t) {
    node b = t->pRight;
    node c = b->pLeft;
    b->pLeft = t;
    t->pRight = c;
    return b;
}

node turnRight(node t) {
    node b = t->pLeft;
    node c = b->pRight;
    b->pRight = t;
    t->pLeft = c;
    return b;
}

int height(node t) {
    if (t == NULL) return -1;
    else if (t->pLeft == NULL && t->pRight == NULL) return 0;
    else return 1 + max(height(t->pLeft), height(t->pRight));
}

bool isAVL(node t) {
    if (t == NULL) return true;
    if (abs(height(t->pLeft) - height(t->pRight)) > 1) return false;
    return isAVL(t->pLeft) && isAVL(t->pRight);
}

node updateTree(node t) {
    if (t==NULL) return NULL;
    if (abs(height(t->pLeft) - height(t->pRight)) > 1) {
        if (height(t->pLeft) > height(t->pRight)) {
            node p = t->pLeft;
            if (height(p->pLeft) > height(p->pRight)) t = turnRight(t);
            else {
                t->pLeft = turnLeft(t->pLeft);
                t = turnRight(t);
            }
        }
        else {
            node p = t->pRight;
            if (height(p->pRight) > height(p->pLeft)) t = turnLeft(t);
            else {
                t->pRight = turnRight(t->pRight);
                t = turnLeft(t);
            }
        }
    }
    if (t->pLeft != NULL) t->pLeft = updateTree(t->pLeft);
    if (t->pRight != NULL) t->pRight = updateTree(t->pRight);
    return t;
}

int count (node t, int x) {
    if (t == NULL) return 0;
    if (t->data == x) return 1 + count(t->pLeft, x) + count(t->pRight, x);
    else if (t->data < x) return count(t->pRight, x);
    return count(t->pLeft, x);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;
    node t = NULL;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        t = treeInsert(t, x);
    }
    while (!isAVL(t)) t = updateTree(t);
    int m; cin >> m;
    cout << count(t, m);
}