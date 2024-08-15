#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* pLeft;
    Node* pRight;
};
typedef struct Node* node;

node newNode(int data) {
    node temp = new Node;
    temp->data = data;
    temp->pLeft = NULL;
    temp->pRight = NULL;
    return temp;
}

void insert(node &root, int data) {
    if (root == NULL) {
        root = newNode(data);
    }
    else if (data < root->data) {
        insert(root->pLeft, data);
    }
    else {
        insert(root->pRight, data);
    }
}

int findGrade(node t) {
    if (t == NULL) return -1;
    if (t->pLeft == NULL && t->pRight == NULL) return 0;
    return 1 + max(findGrade(t->pLeft), findGrade(t->pRight));
}

int main() {
    node t = NULL;
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        insert(t, x);
    }
    cout << findGrade(t) << endl;
    return 0;
}