#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};
struct ListLinkedNode {
    Node *head;
    Node *tail;
};
typedef struct Node* node;
typedef struct ListLinkedNode* ListNode;

node makeNode(int x) {
    node temp = new Node();
    temp->data = x;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

ListNode makeList(node a) {
    ListNode temp = new ListLinkedNode();
    if (a == NULL) {
        temp->head = NULL;
        temp->tail = NULL;
    }
    else {
        temp->head = a;
        node p = a;
        while (p->next != NULL) {
            p = p->next;
        }
        temp->tail = p;
    }
    return temp;
}

int getSize (node a) {
    int size = 0;
    while (a!= NULL) {
        size++;
        a = a->next;
    }
    return size;
}

void insertFirst (ListNode &list, node &a, int x) {
    node temp = makeNode(x);
    if (a==NULL) {
        a = temp;
        list = makeList(a);
    }
    else {
        temp->next = a;
        a->prev = temp;
        a = temp;
        list = makeList(a);
    }
}

void insertLast (ListNode &list, node &a, int x) {
    node temp = makeNode(x);
    if (a==NULL) {
        a = temp;
        list = makeList(a);
    }
    else {
        node p = a;
        while (p->next!= NULL) {
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
        list = makeList(a);
    }
}

void addNode (ListNode &list, node &a, int x) {
    insertLast(list, a, x);
}

void insertNode(ListNode &list, node &a, int x, int pos) {
    node temp = makeNode(x);
    if (pos < 0 || pos > getSize(a)) {
        cout << "Invalid position" << endl;
    }
    else if (pos == 0) {
        insertFirst(list, a, x);
    }
    else if (pos == getSize(a)) {
        insertLast(list, a, x);
    }
    else {
        node temp = makeNode(x);
        node p = a;
        for (int i = 0; i < pos-1; i++) {
            p = p->next;
        }
        temp->next = p->next;
        temp->prev = p;
        p->next = temp;
        temp->next->prev = temp;
    }
}

void printNode(ListNode list, node a) {
    while (a!= NULL) {
        cout << a->data << " ";
        a = a->next;
    }
}
int main() {
    #ifndef ONLINE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif

    int n; cin >> n;
    node head = NULL;
    ListNode list = NULL;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        addNode(list, head, x);
    }

    int k, j; cin >> k >> j;
    insertNode(list, head, j, k);

    printNode(list, head);
}