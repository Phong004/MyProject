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

void addNode(node &a, int x) {
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

int getAt(node a, int pos) {
    for (int i=0; i<pos; i++) {
        a = a->next;
    }
    return a->data;
}

void deleteGreater(node &head, int pos) {
    node Prev = NULL, Next = head;
    int temp = getAt(head, pos);
    if (head==NULL) return;
    while (Next!=NULL) {
        if (Next->data > temp) {
            if (Prev == NULL ) {
                head = head->next;
                delete Next;
                Next = head;
            }
            else {
                Prev->next = Next->next;
                delete Next;
                Next = Prev->next;
            }
        }
        else {
           Prev = Next;
           Next = Next->next;
        }
    }
} 

void printList(node head) {
    while (head!=NULL) {
        cout << head->data << " ";
        head = head->next;
    }
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
        addNode(head, x);
    }
    int k; cin >> k;
    deleteGreater(head, k);
    printList(head);
}