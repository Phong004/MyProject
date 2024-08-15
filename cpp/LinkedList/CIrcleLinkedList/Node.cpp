#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *next;
};
typedef struct Node* node;

node createNode(int x) {
    node a = new Node();
    a->data = x;
    a->next = NULL;
    return a;
}

int sizeList(node a) {
    node p = a; int count = 0;
    do {
        count++;
        p = p->next;
    } while (p != a);
    return count;
}

void linkNode(node &a, int x) {
    if (a == NULL) {
        a=createNode(x);
        a->next = a;    
    }
    else {
        node temp = createNode(x);
        node p = a;
        do {
            p = p->next;
        } while (p->next != a);
        p->next = temp;
        temp->next = a;
    }
}

void changeHeader(node &a, int pos) {
    node p = a;
    if (pos <= 0  || pos >= sizeList(a)) return;
    else {
        for (int i = 0; i < pos-1; i++) {
            p = p->next;
        }
        a=p->next;
    }
}

void printNode (node a) {
    node p = a;
    if (a == NULL) return;
    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != a);
}

int main() {
    #ifndef ONLINE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    node head = NULL;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        linkNode(head, x);
    }
    int k; cin >> k;
    changeHeader(head, k);

    printNode(head);
}