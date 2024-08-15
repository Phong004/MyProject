#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *next;
};

typedef struct Node* node;

node makeNode(int x) {
    node temp = new Node();
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void addNode(node &a) {
    int x; cin >> x;
    node temp = makeNode(x);
    if (a==NULL) {
        a=temp;
    }
    else {
        node p = a;
        while (p->next!=NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}

void replaceNode(node &head, int a, int b) {
    node p = head;
    while (p != NULL) {
        if (p->data == a) {
            p->data = b;
        }
        p = p->next;
    }
}

void printList(node a) {
    while (a!=NULL) {
        cout << a->data << " ";
        a = a->next;
    }
}

int main() {
    #ifndef ONLINE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    node head = NULL;
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        addNode(head);
    }
    int a, b; cin >> a >> b;
    replaceNode(head, a, b);
    printList(head);
}
