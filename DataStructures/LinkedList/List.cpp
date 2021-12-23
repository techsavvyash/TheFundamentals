#include <iostream>
using namespace std;

class ListNode {
public: 
    int data;
    ListNode* next;
    //constructors
    ListNode() {
        next = NULL;
    }

    ListNode(int data) {
        this->data = data;
        next = NULL;
    }
    friend class List ;
};  

class List {
    ListNode* root ;
    ListNode* tail;
    int listSize;
public: 
    List() {
        root = tail = NULL;
        listSize = 0;
    }

    void addFront(int val) {
        if(root == NULL) {
            root = new ListNode(val);
            root->next = NULL;
            tail = root;
            return;
        }
        ListNode* newNode = new ListNode(val);
        newNode->next = root;
        root = newNode;
        listSize++ ;
    }

    void addAtBack(int val) {
        if(root == NULL) {
            root = new ListNode(val);
            root->next = NULL;
            tail = root ;
            return ;
        }
        ListNode* newNode = new ListNode(val) ;
        tail->next = newNode ;
        tail = newNode ;
        listSize++;
    }

    int size() {
        return listSize;
    }

    bool empty() {
        if(root == NULL) return true;
        return false;
    }

    ListNode* begin() {
        return root;
    }

    ListNode* end() {
        return tail;
    }

};


int main() {
    List *l = new List();
    l->addAtBack(1);
    l->addAtBack(2);
    l->addAtBack(3);
    l->addAtBack(4);
    l->addAtBack(5);

    ListNode* temp = l->begin() ;

    while(temp!= NULL) {
        cout << temp->data << endl;
        temp = temp->next ;
    }

    return 0;
}