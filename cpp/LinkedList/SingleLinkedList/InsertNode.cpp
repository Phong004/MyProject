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

bool isEmptyNode(node a) {return a==NULL;}
int sizeList(node a) { 
    int count =0;
    while (a!=NULL) {
        count++;
        a = a->next;
    }
    return count;
}

void insertFirst (node &a, int x) {
    node temp = makeNode(x);
    if (a==NULL) {
        a = temp;
    }
    else {
        temp->next = a;
        a = temp;
    }
}

void insertLast (node &a, int x) {
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

void makeListNode(node &a, int size) {
    for (int i = 0; i < size; i++) {
        int x; cin >> x;
        insertLast(a, x);
    }
}

void insertMiddle (node &a, int pos, int x) {
    int n = sizeList(a);
    if (pos < 0 || pos > n) {
        cout << "Invalid insert position";
    }
    if (pos == 0) {
        insertFirst(a, x);
    }
    else if (pos == n) {
        insertLast(a, x);
    }
    else {
        node temp = makeNode(x);
        node p = a;
        for (int i=0; i<pos-1; i++) {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
}

void printList(node a) {
    cout << "----------------------------------------------------------------\n";
    while (a!=NULL) {
        cout << a->data << " ";
        a = a->next;
    }
    cout << endl;
    cout << "----------------------------------------------------------------\n";
}

int main() {
    #ifndef ONLINE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n; cin >> n;
    node head = NULL;
    makeListNode(head, n);
    int k; cin >> k;
    int x; cin >> x;

    insertMiddle(head, k, x);

    printList(head);
}