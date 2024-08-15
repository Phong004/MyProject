#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* pLeft;
    Node* pRight;
};
typedef struct Node* node;

node makeNode(int x) {
    node p = new Node();
    p->data = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

void insert(node &t, int x) {
    if (t == NULL) t=makeNode(x);
    else {
        if (x < t->data) 
            insert(t->pLeft, x);
        else if (x > t->data)
            insert(t->pRight, x);
    }
}

void printTree(node t) {
    if (t!= NULL) {
        printTree(t->pLeft);
        cout << t->data << " ";
        printTree(t->pRight);
    }
}

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    node t = NULL;
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        insert(t, x);
    }
    printTree(t);
}