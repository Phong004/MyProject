#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
typedef struct Node* node;

node newNode(int data) {
    node p = new Node();
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void treeInsert(node &t, int data) {
    if (t == NULL) t = newNode(data);
    else if (data < t->data) treeInsert(t->left, data);
    else treeInsert(t->right, data);
}

void freeNode(node t) {
    if (t != NULL) {
        freeNode(t->left);
        freeNode(t->right);
        delete t;
    }
}

void deleteOneNumber(node &t, int x) {
    if (t == NULL) return;
    else if (x < t->data) deleteOneNumber(t->left, x);
    else if (x > t->data) deleteOneNumber(t->right, x);
    else {
        if (t->left == NULL && t->right == NULL) {
            freeNode(t);
            t = NULL;
        }
        else if (t->left == NULL) {
            node temp = t;
            t = t->right;
            freeNode(temp);
        }
        else if (t->right == NULL) {
            node temp = t;
            t = t->left;
            freeNode(temp);
        }
        else {
            node temp = t->right;
            while (temp->left!= NULL) temp = temp->left;
            t->data = temp->data;
            deleteOneNumber(t->right, temp->data);
        }
    }
}

void deleteOneBranch(node &t, int x) {
    if (t != NULL) {
        if (x < t->data) deleteOneBranch(t->left, x);
        else if (x > t->data) deleteOneBranch(t->right, x);
        else {
            freeNode(t->left);
            freeNode(t->right);
            t = NULL;
        }
    }
}

void inorder(node t) {
    if (t!= NULL) {
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    node t = NULL;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        treeInsert(t, x);
    }
    int k; cin >> k;
    //deleteOneNumber(t, k);
    deleteOneBranch(t, k);
    inorder(t);
}