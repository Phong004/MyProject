#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *next;
};

typedef struct Node* node;

node makeNode (int x) {
    node temp = new Node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void makeList (node &a, int size) {
    for (int i = 0; i < size; i++) {
        int x; cin >> x;
        node temp = makeNode(x);
        if (a==NULL) {
            a = temp;
        }
        else {
            node p = a;
            while (p->next!=NULL) {
                p = p->next;
            }
            p->next = temp;
        }
    }
}

int sizeList (node a) {
    int count = 0;
    while (a!=NULL) {
        count++;
        a = a->next;
    }
    return count;
}

void deleteFirst (node &a) {
    if (a == NULL) return;
    node temp = a;
    a = a->next;
    delete temp;
}

void deleteLast (node &a) {
    if (a == NULL) return;
    node prev = NULL, next = a;
    while (next->next!=NULL) {
        prev = next;
        next = next->next;
    }
    if (prev == NULL) {
        a = NULL;
    }
    else {
        prev->next = NULL;
        delete next;
    }
}

void deleteMiddle (node &a, int pos) {
    int n = sizeList(a);
    if (a==NULL) return;
    if (pos < 0 || pos >= n) {
        cout << "Invalid position" << endl;
        return;
    }
    node prev = NULL, next = a;
    for (int i=0; i<pos; i++) {
        prev = next;
        next = next->next;
    }
    if (prev == NULL) {
        a = next->next;
        delete next;
    }
    else {
        prev->next=next->next;
        delete next;
    }
}

void printList (node a) {
    // cout << "--------------------------------\n";
    while (a != NULL) {
        cout << a->data << " ";
        a = a->next;
    }
    // cout << endl;
    // cout << "--------------------------------";
}

int main(void) {
    #ifndef ONLINE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    node head = NULL;
    int n; cin >> n;
    makeList(head, n);
    int k; cin >> k;
    deleteMiddle(head, k);
    printList(head);
}