#include <iostream>
using namespace std;

template <typename T>
class ListNode
{
public:
    T data;
    ListNode *next;
    // constructors
    ListNode()
    {
        next = NULL;
    }

    ListNode(int data)
    {
        this->data = data;
        next = NULL;
    }

    class List;
};

template <typename T>
class List
{
    ListNode *root;
    ListNode *tail;
    int listSize;

public:
    List()
    {
        root = tail = NULL;
        listSize = 0;
    }

    void addFront(T val)
    {
        if (root == NULL)
        {
            root = new ListNode(val);
            root->next = NULL;
            tail = root;
            return;
        }
        ListNode *newNode = new ListNode(val);
        newNode->next = root;
        root = newNode;
        listSize++;
    }

    void addAtBack(T val)
    {
        if (root == NULL)
        {
            root = new ListNode(val);
            root->next = NULL;
            tail = root;
            return;
        }
        ListNode *newNode = new ListNode(val);
        tail->next = newNode;
        tail = newNode;
        listSize++;
    }

    int size()
    {
        return listSize;
    }

    bool empty()
    {
        if (root == NULL)
            return true;
        return false;
    }

    ListNode *begin()
    {
        return root;
    }

    ListNode *end()
    {
        return tail;
    }
};

int main()
{
    List<int> *l = new List<int>();
    l->addAtBack(1);
    l->addAtBack(2);
    l->addAtBack(3);
    l->addAtBack(4);
    l->addAtBack(5);

    ListNode<int> *temp = l->begin();

    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }

    return 0;
}
