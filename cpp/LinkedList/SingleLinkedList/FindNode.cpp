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

void insertFirst(node &a, int x) {
    node temp = makeNode(x);
    if (a==NULL) 
        a = temp;
    else {
        temp->next = a;
        a = temp;
    }
}

void insertLast(node &a, int x) {
    node temp = makeNode(x);
    if (a==NULL) 
        a = temp;
    else {
        node p = a;
        while (p->next!=NULL)
            p = p->next;
        p->next = temp;
    }
}

void printvalueof(node a, int k) {
    for (int i=0; i<k; i++) {
        a=a->next;
    }
    cout << a->data;
}

int main() {
    #ifndef ONLINE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    node head = NULL;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        insertLast(head, x);
    }
    int k; cin >> k;

    printvalueof(head, k);    
}