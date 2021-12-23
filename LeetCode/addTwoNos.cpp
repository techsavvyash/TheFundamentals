#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int data;
    ListNode* next;
    ListNode(int val) {
        data = val;
        next = NULL;
    }
};

void addAtEnd(ListNode* head, ListNode* tail, int val) {
    ListNode *newNode = new ListNode(val);
    if(head == NULL) {
        tail = head = newNode;
        return;
    }

    tail->next = newNode;
    tail = tail->next;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int 

    return 0;
}