#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* pLeft;
    Node* pRight;
};
typedef struct Node *node;

node newNode(int data) {
    node temp = new Node();
    temp->data = data;
    temp->pLeft = NULL;
    temp->pRight = NULL;
    return temp;
}

void treeInsert(node &t, int x) {
    if (t == NULL) t = newNode(x);
    else if (x < t->data) treeInsert(t->pLeft, x);
    else treeInsert(t->pRight, x); 
}

node turnLeft(node a) {
    node b = a->pRight;
    node c = b->pLeft;
    b->pLeft = a;
    a->pRight = c;
    return b;
}

node turnRight(node a) {
    node b = a->pLeft;
    node c = b->pRight;
    b->pRight = a;
    a->pLeft = c;
    return b;
}

int height(node t) {
    if (t == NULL) return -1;
    else if (t->pLeft == NULL && t->pRight == NULL) return 0;
    else return 1 + max(height(t->pLeft), height(t->pRight));
} 

node balanceAVL(node t) {
    if (t == NULL) return NULL;
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
    if (t->pLeft != NULL) t->pLeft = balanceAVL(t->pLeft);
    if (t->pRight != NULL) t->pRight = balanceAVL(t->pRight);
    return t;
}

bool isAVL_Tree(node t) {
    if (t == NULL) return true;
    if (abs(height(t->pLeft) - height(t->pRight)) > 1) return false;
    return isAVL_Tree(t->pLeft) && isAVL_Tree(t->pRight);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;  cin >> n;
    node t = NULL;
    for (int i = 0; i < n; i++) {
        int x;  cin >> x;
        treeInsert(t, x);
    }
   while (!isAVL_Tree(t)) {
         t = balanceAVL(t);
   }
    cout << height(t) << endl;
    return 0;
}