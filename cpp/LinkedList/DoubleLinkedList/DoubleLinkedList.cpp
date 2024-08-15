#include <iostream>
#include <algorithm>
using namespace std;

struct DouNode {
    int data;
    DouNode *next;
    DouNode *prev;
};
struct DouListNode {
    DouNode *head;
    DouNode *tail;
};
typedef struct DouNode* node;
typedef struct DouListNode* ListNode;

node makeNode(int x) {
    node temp = new DouNode();
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void addNode (ListNode &list, node &a, int x) {
    node temp = makeNode(x);
    if (a==NULL) {
        a=temp;
        list->head = a;
    }
    else {
        node p = a;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
        list->tail = temp;
    }
}

int size (node a) {
    int count = 0;
    while (a->next != NULL) {
        count++;
        a = a->next;
    }
    return count;
}

void print_node(ListNode list) {
    for (node p = list->head; p != NULL; p = p->next)
        cout << p->data << " ";
    for (node q = list->tail->prev; q != NULL; q = q->prev) 
        cout << q->data << " ";
}

int main() {
    #ifndef ONLINE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ListNode list = new DouListNode();
    node head = NULL;
    node tail = NULL;
    list->head = head;
    list->tail = tail;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; x = n - i;
        addNode(list, head, x);
    }
    print_node(list);
}